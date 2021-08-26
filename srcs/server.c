/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:40:19 by emtran            #+#    #+#             */
/*   Updated: 2021/08/26 14:57:41 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdio.h>

void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	static char	c = 0xFF;
	static int	bites = 0;

	if (signum == SIGUSR1)
	{
		ft_putchar('0');
		c ^= 0x80 >> bites;
	}
	else if (signum == SIGUSR2)
	{
		ft_putchar('1');
		c |= 0x80 >> bites;
	}
	bites++;
	if (bites == 8)
	{
		ft_putstr("-> ");
		ft_putchar(c);
		bites = 0;
		c = 0xFF;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	s_sigactor;

	s_sigactor.sa_sigaction = &handler_sigusr;
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
