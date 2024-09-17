# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 14:55:12 by jormoral          #+#    #+#              #
#    Updated: 2024/09/11 15:02:58 by jormoral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = minishell
USER    = jormoral
LIBFT   = Lib/Libft/
CFLAGS  = -g -Wall -Wextra -Werror -ILib
CC      = clang 
LIB = -lreadline


MAGENTA = \033[35;1m
YELLOW  = \033[33;1m
GREEN   = \033[32;1m
WHITE   = \033[37;1m
RESET   = \033[0m
GRAY 	= \033[0;90m
BLUE    = \033[34;1m
CYAN    = \033[37;1m
BOLD	= \033[1m
RED		= \033[31;1m

SRCS	:= main.c\


OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

$(NAME):	compiling $(OBJS)
			@echo
			@make all -C $(LIBFT)
			@$(CC) $(CFLAGS) $(OBJS) $(LIB) -L$(LIBFT) -lft -o $(NAME)
			@echo "$(MAGENTA)Minishell compiled!$(RESET)"

$%.o: %.c
			@echo "$(BLUE)Compiling: $(RESET)$(notdir $<)"
			@$(CC) $(CFLAGS) -c $< -o $@

compiling:
			@echo "$(YELLOW)Compiling Minishell!$(RESET)"
			
clean:
			@make clean -C $(LIBFT)
			@rm -rf $(OBJS)
			@echo "$(RED)Cleaning LIBFT.$(RESET)"
			@echo "$(RED)Cleaning Minishell executables.$(RESET)"
			

fclean:
			make fclean -C $(LIBFT)
			rm -rf $(OBJS)
			rm -rf $(NAME)
			@echo "$(RED)Fcleaning LIBFT.$(RESET)"
			@echo "$(RED)Fcleaning minishell.$(RESET)"

re: fclean all
			@echo "$(YELLOW)Minishell recompiled$(RESET)"

norm:
			@echo "$(YELLOW)Norminette of Minishell files & BONUS.$(RESET)"
			@norminette $(SRCS)
			@echo "$(YELLOW)Norminette of LIBFT.$(RESET)"
			@norminette $(LIBFT)
						
.PHONY: all clean fclean re norm compiling