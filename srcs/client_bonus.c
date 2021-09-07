/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:07:07 by emtran            #+#    #+#             */
/*   Updated: 2021/09/07 11:40:21 by emtran           ###   ########.fr       */
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

int	landing_of_null(pid_t pid, char *str)
{
	static int	i = 0;

	if (i != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			free(str);
			str = NULL;
			exit(EXIT_FAILURE);
		}
		i++;
		return (0);
	}
	return (1);
}

int	lighthouse_signals(char *str, pid_t pid)
{
	static char	*nstr = NULL;
	static int	pid_s = 0;
	static int	shift_cape = 0;

	if (str)
		nstr = ft_strdup(str);
	if (pid)
		pid_s = pid;
	if (!nstr)
		houston_we_ve_a_problem(0, 0);
	while (nstr[shift_cape / 8])
	{
		if (nstr[shift_cape / 8] & (0x80 >> (shift_cape % 8)))
			kill(pid_s, SIGUSR2);
		else
			kill(pid_s, SIGUSR1);
		usleep(1);
		shift_cape++;
		return (0);
	}
	if (landing_of_null(pid_s, str) == 1)
		return (0);
	free(nstr);
	return (1);
}

void	handler_sigusr_c(int signum)
{
	int		final;

	final = 0;
	if (signum == SIGUSR1)
		final = lighthouse_signals(0, 0);
	else if (signum == SIGUSR2)
	{
		ft_putstr("Allo ? Allo ? Je ne vous entends plus ? ");
		ft_putstr("Tous les cris les SOS !!!\n");
		exit(EXIT_FAILURE);
	}
	if (final)
	{
		ft_putstr("Mission accomplished ! \n");
		ft_putstr("Lorsque tu accomplis ta mission en t'appuyant sur toi-même");
		ft_putstr(", tu goûtes le fruit de la maturité...\n");
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;

	if (argc != 3 || check_str_nb(argv[1]) == 1)
	{
		not_found_404(argc, argv);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, handler_sigusr_c);
	signal(SIGUSR2, handler_sigusr_c);
	lighthouse_signals(argv[2], pid);
	while (1)
		pause();
}
