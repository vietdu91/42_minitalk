/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:47:48 by emtran            #+#    #+#             */
/*   Updated: 2021/08/26 20:51:45 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>


/* CLIENT */

void	not_found_404(int argc, char **argv);
int		the_end_of_the_world(pid_t pid, char *str);
int		lighthouse_signals(char *str, pid_t pid);
void	handler_sigusr_cli(int signum, siginfo_t *info, void *context);

/* SERVER */

void	houston_we_ve_a_problem(char *str, pid_t pid);
char	*str_factory(char *str, char j);
void	handler_sigusr_serv(int signum, siginfo_t *info, void *context);
int		check_str_nb(char *str);

/* UTILS */
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_atoi(const char *str);
#endif