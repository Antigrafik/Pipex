# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmurgia- <mmurgia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 11:57:04 by ccanete-          #+#    #+#              #
#    Updated: 2022/10/07 11:26:18 by mmurgia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
SAN			=	-g -fsanitize=address
RM			=	rm -rf

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m

#FILES AND PATH
HEADER	=	pipex.h

MPATH_SRCS	=	pipex.c
MPATH_DIR	=	mandatory/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

FUNC_SRCS	=	ft_split.c ft_strjoin.c ft_strncmp.c ft_utils.c path_access.c ft_strdup.c
FUNC_DIR	=	functions/
FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))
OBJ_F		=	$(FUNC:.c=.o)

.o:.c $(FUNC) $(MPATH)
	${CC} ${FLAGS} -I$(HEADER) -c -o $@ $<

$(NAME): $(OBJ_F) $(OBJ_M)
	$(CC) ${FLAGS} -o $(NAME) $(OBJ_F) $(OBJ_M)
	@echo "$(GREEN)$(NAME) Created!$(DEFAULT)"

all:			$(NAME)

clean:
				@$(RM) $(OBJ_M)
				@$(RM) *.o
				@$(RM) functions/*.o
				@$(RM) $(OBJ_B)
				@echo "$(YELLOW)Object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo "$(RED)All deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re
