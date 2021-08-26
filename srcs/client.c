/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:40:15 by emtran            #+#    #+#             */
/*   Updated: 2021/08/26 20:52:59 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdlib.h>
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

int	the_end_of_the_world(pid_t pid, char *str)
{
	static int	i = 0;

	if (i != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			houston_we_ve_a_problem(str, 0);
		i++;
		return (0);
	}
	return (1);
}

int	lighthouse_signals(char *str, pid_t pid)
{
	static int	shift_cape = 0;

	if (!str)
		houston_we_ve_a_problem(0, 0);
	while (str[shift_cape / 8])
	{
		if (str[shift_cape / 8] & (0x80 >> (shift_cape % 8)))
		{
			if (kill(pid, SIGUSR2) != 0)
				houston_we_ve_a_problem(str, pid);
			shift_cape++;
		}
		else if (kill(pid, SIGUSR1) != 0)
			houston_we_ve_a_problem(str, pid);
		shift_cape++;
		usleep(300);
		return (0);
	}
	if (the_end_of_the_world(pid, str) == 0)
		return (0);
	free(str);
	return (1);
}

void	handler_sigusr_cli(int signum, siginfo_t *info, void *context)
{
	int	link;

	(void)info;
	(void)context;
	link = 0;
	if (signum == SIGUSR1)
		link = lighthouse_signals(0, 0);
	else if (signum == SIGUSR2)
	{
		ft_putstr("Uh, Houston, we've had a problem...\n");
		ft_putstr("Help me! We can't hear them anymore!");
		exit(0);
	}
	if (link == 0)
	{
		ft_putstr("Allo la Terre ?! Ici la Lune !\n");
		ft_putstr("Can you hear us? Yes, the communication is perfect!");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	s_sigactor;

	s_sigactor.sa_sigaction = &handler_sigusr_cli;
	s_sigactor.sa_flags = SA_SIGINFO;
	sigemptyset(&s_sigactor.sa_mask);
	if (argc != 3 || check_str_nb(argv[1]) == 1)
	{
		not_found_404(argc, argv);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	lighthouse_signals(argv[2], pid);
	while (1)
	{
		sigaction(SIGUSR1, &s_sigactor, NULL);
		sigaction(SIGUSR2, &s_sigactor, NULL);
		pause();
	}
	return (0);
}
