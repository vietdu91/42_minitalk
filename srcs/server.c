/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:40:19 by emtran            #+#    #+#             */
/*   Updated: 2021/08/27 16:56:19 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdio.h>

char	*str_factory(char *str, char j)
{
	int		len;
	char	*nstr;
	int		i;

	if (str != 0 && j != 0)
	{
		len = ft_strlen(str);
		nstr = (char *)malloc(sizeof(char) * (len + 22));
		if (nstr == 0)
			return (0);
		i = -1;
		while (str[++i])
			nstr[i] = str[i];
		nstr[len] = j;
		nstr[len + 1] = '\0';
		return (nstr);
	}
	return (0);
}

void	handler_sigusr_serv(int signum, siginfo_t *info, void *context)
{
	static char		i = 0xFF;
	static pid_t	pid = 0;
	static int		bites = 0;
	static char		*str = NULL;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
//	ft_putchar(i);
//	fflush(stdout);
//	ft_putnbr(pid);
//	fflush(stdout);			
	if (signum == SIGUSR1)
		i ^= 0x80 >> bites;
	else if (signum == SIGUSR2)
		i |= 0x80 >> bites;
//	ft_putnbr(bites);
//	fflush(stdout);	
	bites++;
	if (bites == 8)
	{
		if (i)
			str = str_factory(str, i);
		else
		{
			ft_putstr(str);
			free(str);
		}
		bites = 0;
		i = 0xFF;
	}
	if (kill(pid, SIGUSR1) != 0)
		houston_we_ve_a_problem(str, pid);
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
	while (1)
	{
		sigaction(SIGUSR1, &s_sigactor, NULL);
		sigaction(SIGUSR2, &s_sigactor, NULL);
		pause();
	}
	return (0);
}
