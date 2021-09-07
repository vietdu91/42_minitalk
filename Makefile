	# Library Name #
NAME_C	= client

NAME_BC	= client_bonus

NAME_S	= server

NAME_BS	= server_bonus

	# Variables #
SRCS_C	= client.c \
		utils.c \
		utils_the_retour.c

SRCS_S	= server.c \
		utils.c \
		utils_the_retour.c

SRCS_BC	= client_bonus.c \
		utils_bonus.c \
		utils_the_retour_bonus.c

SRCS_BS	= server_bonus.c \
		utils_bonus.c \
		utils_the_retour_bonus.c
	
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

OBJS_BC	= ${SRCS_BC:.c=.o}
OBJS_BC	:= $(addprefix objs/,${OBJS_BC})

OBJS_BS	= ${SRCS_BS:.c=.o}
OBJS_BS	:= $(addprefix objs/,${OBJS_BS})

	# Rules #
all:		${NAME_C} ${NAME_S}

bonus:		${NAME_BC} ${NAME_BS}

$(NAME_C):	${OBJS_C}
			gcc -Wall -Werror -Wextra -fsanitize=address -I includes ${OBJS_C} -o $(NAME_C)
			@printf "$(YELLOW)\n Règle du jeu : mettre l’argent du client dans sa poche.\n$(RESET)"
			@printf "$(YELLOW)==============================================================================================\n$(RESET)"
			@printf "$(GREEN)La vie passe...\n\n$(RESET)"

$(NAME_S):	${OBJS_S}
			gcc -Wall -Werror -Wextra -fsanitize=address -I includes ${OBJS_S} -o $(NAME_S)
			@printf "$(YELLOW)\n Que la damnation puisse être éternelle suppose en fin de compte que le péché n'a point de fin.\n$(RESET)"
			@printf "$(YELLOW)==============================================================================================\n$(RESET)"
			@printf "$(GREEN)...la moulinette trepasse !\n$(RESET)"

$(NAME_BC):	${OBJS_BC}
			gcc -Wall -Werror -Wextra -fsanitize=address -I includes ${OBJS_BC} -o $(NAME_BC)
			@printf "$(YELLOW)\n Règle du jeu : mettre l’argent du client dans sa poche.\n$(RESET)"
			@printf "$(YELLOW)==============================================================================================\n$(RESET)"
			@printf "$(GREEN)La vie passe...\n\n$(RESET)"

$(NAME_BS):	${OBJS_BS}
			gcc -Wall -Werror -Wextra -fsanitize=address -I includes ${OBJS_BS} -o $(NAME_BS)
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
			rm -f ${OBJS_BC}
			rm -f ${OBJS_BS}
			@printf "$(YELLOW)\n Au fond, est-ce que ranger ça ne revient pas un peu à foutre le bordel dans son désordre ? \n$(RESET)"
			@printf "$(YELLOW)==============================================================================================\n$(RESET)"
fclean:
			rm -f ${OBJS_C}
			rm -f ${OBJS_S}
			rm -f ${OBJS_BC}
			rm -f ${OBJS_BS}
			rm -f ${NAME_C}
			rm -f ${NAME_S}
			rm -f ${NAME_BC}
			rm -f ${NAME_BS}
			@printf "$(YELLOW)\n Au fond, est-ce que ranger ça ne revient pas un peu à foutre le bordel dans son désordre ? \n$(RESET)"
			@printf "$(YELLOW)==============================================================================================\n$(RESET)"

re:			fclean all
			@printf "$(YELLOW)\n Aimer, désirer, c’est aussi souffrir, et être prêt à recommencer... \n$(RESET)"
			@printf "$(YELLOW)==============================================================================================\n$(RESET)"
			
	
.PHONY: 	bonus all norme clean fclean re
