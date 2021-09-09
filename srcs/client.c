/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:40:15 by emtran            #+#    #+#             */
/*   Updated: 2021/09/09 13:50:06 by emtran           ###   ########.fr       */
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
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	lighthouse_signals(argv[2], pid);
	return (0);
}
