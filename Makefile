# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kblok <kblok@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/16 20:46:21 by kblok         #+#    #+#                  #
#    Updated: 2022/08/22 17:11:51 by kblok         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#==============================================================================: Filename
NAME	= 	push_swap

#==============================================================================: Source to object conversion 
OBJ		= 	$(SRCS:src/%.c=obj/%.o)

#==============================================================================: Compile variable
CC		= 	gcc
CFLAGS	= 	-Wall -Werror -Wextra -c
INCL	=	-Ilibft
RM		=	rm -rf
AR		=	ar rcs
PUSH_SWAP	= 	.
LIBFT	= 	libft/
HEADERS	= 	-I $(LIBFT) -I $(PUSH_SWAP)

#==============================================================================: Source files 
SRCS	=	push_swap.c \
			main.c \
			arg_checker.c \
			error_exit.c

#==============================================================================: Color codes
GREEN		= \033[1;32m
RED			= \033[1;31m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
RESET		= \033[0m

all: message $(NAME)

run:
	@./$(NAME) $(ARGS)

#==============================================================================: Compile project
$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(CC) $(OBJ) $(HEADERS) $(LIBFT)/libft.a -o $(NAME)
	@echo "$(GREEN)✅Done compiling $(NAME)$(RESET)"

message:
	@echo "$(BLUE)🔨Creating object folder$(RESET)"
	@echo "$(GREEN)🔨Compiling: $(MAGENTA)$(NAME)...$(RESET)"

obj/%.o: src/%.c
	@$(CC) $(CFLAGS) -o $@ $< -I .
ifeq ($(DB),1)
	@printf "$(GREEN)\r🔨Compiling: $(MAGENTA)$(notdir $<)$(GREEN)\r\e[35C[OK]\n$(RESET)"
endif

#==============================================================================: Remove object files and folder
clean:
	@$(RM) obj/
	@$(MAKE) clean -C libft
	@echo "$(RED)🧹Cleaned object folders!$(RESET)"

#==============================================================================: Remove object files, folder and lib files/executables
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C libft
	@echo "$(RED)🧹Cleaned $(NAME)!$(RESET)"

re: fclean all

.PHONY: all clean fclean re message