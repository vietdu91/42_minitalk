/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:40:19 by emtran            #+#    #+#             */
/*   Updated: 2021/08/22 19:32:03 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdio.h>

void	handler_sigusr1(int signum)
{
	printf("signal %d received.\n", signum);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("TADAM ! The magical PID is : ");
	ft_putnbr(pid);
	signal(SIGUSR1, handler_sigusr1);
	while (1)
   		pause();
	return (0);
}
