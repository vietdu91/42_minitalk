	# Library Name #
NAME_C	= client

NAME_S	= server

	# Variables #
SRCS_C	= client.c \
		utils.c \
		utils_the_retour.c

SRCS_S	= server.c \
		utils.c \
		utils_the_retour.c

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

norme:		
			norminette srcs/*
			norminette includes/*
			@printf "$(YELLOW)==============================================================================================\n$(RESET)"
			@printf "$(GREEN)La vie passe, la norminette trepasse !\n$(RESET)"
clean:
			rm -f ${OBJS_C}
			rm -f ${OBJS_S}
			@printf "$(YELLOW)\n Au fond, est-ce que ranger ça ne revient pas un peu à foutre le bordel dans son désordre ? \n$(RESET)"
			@printf "$(YELLOW)==============================================================================================\n$(RESET)"
fclean:
			rm -f ${OBJS_C}
			rm -f ${OBJS_S}
			rm -f ${NAME_C}
			rm -f ${NAME_S}
			@printf "$(YELLOW)\n Au fond, est-ce que ranger ça ne revient pas un peu à foutre le bordel dans son désordre ? \n$(RESET)"
			@printf "$(YELLOW)==============================================================================================\n$(RESET)"

re:			fclean all
			@printf "$(YELLOW)\n Aimer, désirer, c’est aussi souffrir, et être prêt à recommencer... \n$(RESET)"
			@printf "$(YELLOW)==============================================================================================\n$(RESET)"
			
	
.PHONY: 	bonus all norme clean fclean re
