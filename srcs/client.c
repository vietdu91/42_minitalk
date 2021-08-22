/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:40:15 by emtran            #+#    #+#             */
/*   Updated: 2021/08/22 19:40:54 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdlib.h>

int	not_found_404(int argc)
{
	if (argc != 2)
		ft_putstr("Shit ! Bad number of arguments : not going too quickly...");
	return (0);
}

int main(int argc, char **argv)
{
	pid_t	pid;
	
	if (argc == 2)
	{
   		pid = ft_atoi(argv[1]);
   		kill(pid, SIGUSR1);
   		return (0);	
	}
	not_found_404(argc);
	return (0);
}
