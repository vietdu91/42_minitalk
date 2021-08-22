	# Library Name #
NAME_C	= client

NAME_S	= server

	# Variables #
SRCS_C	= client.c \
		utils.c

SRCS_S	= server.c \
		utils.c

INCLUDES = includes/minitalk.h

	# Colors #
YELLOW		=	\e[38;5;226m
GREEN		=	\e[38;5;118m
RESET		=	\e[0m

	# Objects #
OBJS_C	= ${SRCS_C:.c=.o}
OBJS_C	:= $(addprefix objs/,${OBJS_C})

OBJS_S	= ${SRCS_S:.c=.o}
OBJS_S	:= $(addprefix objs/,${OBJS_S})

	# Rules #
all:		${NAME_C} ${NAME_S}

bonus:		${NAME_C} ${NAME_S}

$(NAME_C):	${OBJS_C}
			gcc -Wall -Werror -Wextra -I includes ${OBJS_C} -o $(NAME_C)
			@printf "$(YELLOW)\n Règle du jeu : mettre l’argent du client dans sa poche.\n$(RESET)"
			@printf "$(YELLOW)==============================================================================================\n$(RESET)"
			@printf "$(GREEN)La vie passe...\n\n$(RESET)"

$(NAME_S):	${OBJS_S}
			gcc -Wall -Werror -Wextra -I includes ${OBJS_S} -o $(NAME_S)
			@printf "$(YELLOW)\n Que la damnation puisse être éternelle suppose en fin de compte que le péché n'a point de fin.\n$(RESET)"
			@printf "$(YELLOW)==============================================================================================\n$(RESET)"
			@printf "$(GREEN)...la moulinette trepasse !\n$(RESET)"

objs/%.o:		srcs/%.c
					@mkdir -p objs
					gcc -Wall -Werror -Wextra -I includes -o $@ -c $<

norme:		norminette {SRCS_C}
			norminette {SRCS_S}
			norminette {INCLUDES}

clean:
			rm -f ${OBJS_C}
			rm -f ${OBJS_S}

fclean:
			rm -f ${OBJS_C}
			rm -f ${OBJS_S}
			rm -f ${NAME_C}
			rm -f ${NAME_S}

re:			fclean all

.PHONY: 	bonus all norme clean fclean re
