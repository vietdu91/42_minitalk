/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:40:15 by emtran            #+#    #+#             */
/*   Updated: 2021/08/26 15:08:51 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdlib.h>
#include <stdio.h>

int	not_found_404(int argc)
{
	if (argc != 3)
	{
		ft_putstr("Shit ! Bad number of arguments : not going too quickly...\n");
		ft_putstr("Il ne faut jamais aller plus vite que sa vitesse...");
	}
	return (0);
}

void	lighthouse_signals(char *str, pid_t pid)
{
	int	i;
	int	shift_cape;

	i = 0;
	shift_cape = 0;
	while (str[i])
	{
		while (shift_cape < 8)
		{
			if (str[i] & 0x80 >> shift_cape)
			{
				if (kill(pid, SIGUSR2) != 0)
					exit(0);
				shift_cape++;
			}
			else
			{
				if (kill(pid, SIGUSR1) != 0)
					exit(0);
				shift_cape++;
			}
			usleep(300);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		not_found_404(argc);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	lighthouse_signals(argv[2], pid);
	return (0);
}
