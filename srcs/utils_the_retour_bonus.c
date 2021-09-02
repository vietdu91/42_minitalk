/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_the_retour_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:08:36 by emtran            #+#    #+#             */
/*   Updated: 2021/09/02 16:08:45 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	check_str_nb(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	houston_we_ve_a_problem(char *str, pid_t pid)
{
	if (str)
		free(str);
	ft_putstr("Uh, Houston, we've had a problem...\n");
	ft_putstr("The server or the client goes down !");
	if (pid != 0)
		kill(pid, SIGUSR2);
	exit(0);
}

char	*ft_strdup(char *str)
{
	char	*nstr;
	int		i;

	nstr = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (nstr == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		nstr[i] = str[i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}
