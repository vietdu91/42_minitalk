/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:07:07 by emtran            #+#    #+#             */
/*   Updated: 2021/09/09 13:47:00 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	not_found_404(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr(BAD_ARG);
		ft_putstr(CIT_1);
	}
	else if (check_str_nb(argv[1]) == 1)
	{
		ft_putstr(NOT_NB);
		ft_putstr(TEA_TIME);
	}
}

int	lighthouse_signals(char *str, pid_t pid)
{
	static char	*nstr = NULL;
	static int	pid_s = 0;
	static int	shift_cape = -1;

	if (str)
		nstr = ft_strdup(str);
	if (pid)
		pid_s = pid;
	if (!nstr)
		houston_we_ve_a_problem(0, 0);
	while (nstr[++shift_cape / 8])
	{
		if (nstr[shift_cape / 8] & (0x80 >> (shift_cape % 8)))
			kill(pid_s, SIGUSR2);
		else
			kill(pid_s, SIGUSR1);
		usleep(10);
		return (0);
	}
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
		ft_putstr(B_SGL);
		exit(EXIT_FAILURE);
	}
	if (final)
	{
		ft_putstr(GOOD_JOB);
		ft_putstr(CIT_2);
		ft_putstr(CIT_2BIS);
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
