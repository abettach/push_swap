# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abettach <abettach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/27 19:18:23 by abettach          #+#    #+#              #
#    Updated: 2021/07/27 20:09:26 by abettach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_CHECKER = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INC =-I./inc

SRCS		=	./srcs/utils/ft_do_a.c \
				./srcs/utils/ft_do_b.c \
				./srcs/utils/get_next_line.c \
				./srcs/utils/utils.c \
				./srcs/utils/utils_1.c \
				./srcs/utils/utils_2.c \
				./srcs/utils/utils_3.c \
				./srcs/utils/ft_splite.c \
				./srcs/utils/ft_errors.c

PUSH		= 	./srcs/push_swap/ft_sort_3numbers.c \
				./srcs/push_swap/ft_sort_5numbers.c \
				./srcs/push_swap/push_swap.c \
				./srcs/push_swap/ft_sort_more.c \
				./srcs/push_swap/ft_sort_more_2.c 


CHECKER		=	./srcs/checker/checker.c



SRCS_PUSH		=	$(PUSH)
SRCs_push	=	$(CHECKER) 

OBJ=$(SRCS:.c=.o)
OBJ_PUSH=$(SRCS_PUSH:.c=.o)
OBJ_CHECKER=$(SRCs_push:.c=.o)

all:
	@$(MAKE) $(NAME) --no-print-directory

$(NAME): $(OBJ) $(OBJ_PUSH)
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(OBJ_PUSH) -o $(NAME)
	@echo "\033[1;33mMake \033[1;32m\t    [OK]"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "\033[1;32m| \033[1;33m" $(NAME) : Created ! "\033[1;32m|"
	@echo "\033[1;32m~~~~~~~~~~~~~~~~~~~~~~~~~~"

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

bonus:
	@$(MAKE) $(NAME_CHECKER) --no-print-directory

$(NAME_CHECKER): $(OBJ) $(OBJ_CHECKER) $(OBJ_PUSH)
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(OBJ_CHECKER) -o $(NAME_CHECKER)
	@echo "\033[1;33mMake bonus\033[1;32m\t    [OK]"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "\033[1;32m| \033[1;33m" $(NAME_CHECKER) : Created ! "\033[1;32m  |"
	@echo "\033[1;32m~~~~~~~~~~~~~~~~~~~~~~~~~~"

clean:
	@rm -f $(OBJ) $(OBJ_PUSH) $(OBJ_CHECKER)
	@echo "\033[1;33mMake clean \033[1;32m [OK]"

fclean: clean
	@rm -f $(NAME) $(NAME_CHECKER)
	@echo "\033[1;33mMake fclean \033[1;32m[OK]"

re:
	@make fclean --no-print-directory
	@make all --no-print-directory