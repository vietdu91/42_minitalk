/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:06:17 by emtran            #+#    #+#             */
/*   Updated: 2021/09/02 16:06:33 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdio.h>

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
	nstr[len] = j;
	nstr[len + 1] = '\0';
	return (nstr);
}

void	handler_sigusr_serv(int signum, siginfo_t *info, void *context)
{
	static char		i = 0xFF;
	static int		bites = 0;
	static char		*str = NULL;

	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		i ^= 0x80 >> bites;
	else if (signum == SIGUSR2)
		i |= 0x80 >> bites;
	bites++;
	if (bites == 8)
	{
		if (i)
		{
			str = str_factory(str, i);
			ft_putstr(str);
			free(str);
			str = NULL;
		}
		bites = 0;
		i = 0xFF;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	s_sigactor;

	s_sigactor.sa_sigaction = handler_sigusr_serv;
	s_sigactor.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sigactor.sa_mask);
	pid = getpid();
	ft_putstr("TADAM ! The magical PID is : ");
	ft_putnbr(pid);
	ft_putchar('\n');
	sigaction(SIGUSR1, &s_sigactor, NULL);
	sigaction(SIGUSR2, &s_sigactor, NULL);
	while (1)
		pause();
	return (0);
}
