NAME = push_swap
NAME_CHECKER = checker

CC = gcc
CFLAGS = 

INC =-I./inc

SRCS		=	./srcs/utils/ft_do_a.c \
				./srcs/utils/ft_do_b.c \
				./srcs/utils/ft_error.c \
				./srcs/utils/get_next_line.c \
				./srcs/utils/get_next_line_utils.c \
				./srcs/utils/print_stack.c \
				./srcs/utils/utils.c \
				./srcs/utils/ft_splite.c

PUSH		= 	./srcs/push_swap/ft_sort_3numbers.c \
				./srcs/push_swap/ft_sort_5numbers.c \
				./srcs/push_swap/push_swap.c \
				./srcs/push_swap/ft_sort_more.c 


CHECKER		=	./srcs/checker/checker.c



SRCS_PUSH		=	$(PUSH)
SRCS_CHECKER	=	$(CHECKER)

OBJ=$(SRCS:.c=.o)
OBJ_PUSH=$(SRCS_PUSH:.c=.o)
OBJ_CHECKER=$(SRCS_CHECKER:.c=.o)

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
	@echo "\033[1;33mMake \033[1;32m\t    [OK]"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "\033[1;32m| \033[1;33m" $(NAME_CHECKER) : Created ! "\033[1;32m|"
	@echo "\033[1;32m~~~~~~~~~~~~~~~~~~~~~~~~~~"
test:
	@make re --no-print-directory
	@make bonus --no-print-directory
	@make clean --no-print-directory
clean:
	@rm -f $(OBJ) $(OBJ_PUSH) $(OBJ_CHECKER)
	@echo "\033[1;33mMake clean \033[1;32m [OK]"

fclean: clean
	@rm -f $(NAME) $(NAME_CHECKER)
	@echo "\033[1;33mMake fclean \033[1;32m[OK]"

re:
	@make fclean --no-print-directory
	@make all --no-print-directory