/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:47:48 by emtran            #+#    #+#             */
/*   Updated: 2021/09/09 13:48:06 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define DECOLLAGE "TADAM ! Ready to decoller 🚀 ? The magical PID is : "
# define BAD_ARG "Shit ! Bad number of arguments : not going too quickly...\n"
# define NOT_NB "Oups ! There's an error somewhere...\n"
# define TEA_TIME "Have a cup of tea ~~ and refocus... !"
# define B_SGL "Allo ? Je ne vous entends plus ? Tous les cris les SOS !!!\n "
# define GOOD_JOB "Mission accomplished ! \n"
# define CIT_1 "Il ne faut jamais aller plus vite que sa vitesse..."
# define CIT_2 "Lorsque tu accomplis ta mission en t'appuyant sur toi-même"
# define CIT_2BIS ", tu goûtes le fruit de la maturité...\n"

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

/* SERVER */

char	*str_factory(char *str, char j);
void	handler_sigusr_serv(int signum, siginfo_t *info, void *context);
void	decollage_immediat(char *str, char i);

/* CLIENT */

void	not_found_404(int argc, char **argv);
int		the_end_of_the_world(pid_t pid, char *str);
int		lighthouse_signals(char *str, pid_t pid);
void	handler_sigusr_c(int signum);

/* UTILS */

void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_atoi(const char *str);
char	*ft_strdup(char *str);
int		check_str_nb(char *str);
void	houston_we_ve_a_problem(char *str, pid_t pid);
void	its_the_end(char *str);
#endif