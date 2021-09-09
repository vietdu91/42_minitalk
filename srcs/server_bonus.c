/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:06:17 by emtran            #+#    #+#             */
/*   Updated: 2021/09/09 13:48:22 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	*str_factory(char *str, char j)
{
	int		len;
	char	*nstr;
	int		i;

	if (str == 0)
	{
		nstr = (char *)malloc(sizeof(char) * 2);
		if (nstr == 0)
			return (0);
		nstr[0] = j;
		nstr[1] = '\0';
		return (nstr);
	}
	len = ft_strlen(str);
	nstr = (char *)malloc(sizeof(char) * (len + 8));
	if (nstr == 0)
		return (0);
	i = -1;
	while (str[++i] && str != 0)
		nstr[i] = str[i];
	free(str);
	nstr[len] = j;
	nstr[len + 1] = '\0';
	return (nstr);
}

void	decollage_immediat(char *str, char i)
{
	str = str_factory(str, i);
	ft_putstr(str);
	free(str);
	str = NULL;
}

void	its_the_end(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	exit(EXIT_FAILURE);
}

void	handler_sigusr_serv(int signum, siginfo_t *info, void *context)
{
	static char		i = 0xFF;
	static int		bites = 0;
	static int		pid_c = 0;
	static char		*str = NULL;

	(void)context;
	if (info->si_pid)
		pid_c = info->si_pid;
	if (signum == SIGUSR1)
		i ^= 0x80 >> bites;
	else if (signum == SIGUSR2)
		i |= 0x80 >> bites;
	bites++;
	if (bites == 8)
	{
		if (i)
			decollage_immediat(str, i);
		bites = 0;
		i = 0xFF;
	}
	if (kill(pid_c, SIGUSR1) == -1)
		its_the_end(str);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	s_sigactor;

	s_sigactor.sa_sigaction = handler_sigusr_serv;
	s_sigactor.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sigactor.sa_mask);
	pid = getpid();
	ft_putstr(DECOLLAGE);
	ft_putnbr(pid);
	ft_putchar('\n');
	sigaction(SIGUSR1, &s_sigactor, NULL);
	sigaction(SIGUSR2, &s_sigactor, NULL);
	while (1)
		pause();
}
