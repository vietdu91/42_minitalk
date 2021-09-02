/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:07:07 by emtran            #+#    #+#             */
/*   Updated: 2021/09/02 16:07:26 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdio.h>

void	not_found_404(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr("Shit ! Bad number of arguments : not going too quickly...\n");
		ft_putstr("Il ne faut jamais aller plus vite que sa vitesse...");
	}
	if (check_str_nb(argv[1]) == 1)
	{
		ft_putstr("Oups ! There's an error somewhere...\n");
		ft_putstr("Have a cup of tea ~~ and refocus... !");
	}
}

int	lighthouse_signals(char *str, pid_t pid)
{
	static char	*nstr = NULL;
	static int	shift_cape = 0;

	if (str)
		nstr = ft_strdup(str);
	if (!nstr)
		houston_we_ve_a_problem(0, 0);
	while (nstr[shift_cape / 8])
	{
		if (nstr[shift_cape / 8] & (0x80 >> (shift_cape % 8)))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		shift_cape++;
		usleep(100);
	}
	free(nstr);
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t				pid;

	if (argc != 3 || check_str_nb(argv[1]) == 1)
	{
		not_found_404(argc, argv);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	lighthouse_signals(argv[2], pid);
	return (0);
}

