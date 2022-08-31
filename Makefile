# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kblok <kblok@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/16 20:46:21 by kblok         #+#    #+#                  #
#    Updated: 2022/08/31 13:34:34 by kblok         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#==============================================================================: Filename
NAME		= 	push_swap

#==============================================================================: Source to object conversion 
OBJS			= 	$(SRCS:srcs/%.c=objs/%.o)

#==============================================================================: Compile variables
CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra -c
INCL		=	-Ilibft
RM			=	rm -rf
AR			=	ar rcs
MKDIR		=	mkdir -p
HEADERS		= 	-I $(LIBFT)

#==============================================================================: Include files
LIBFT		= 	libft/

#==============================================================================: Source files 
SRCS		=	$(addprefix srcs/, \
				push_swap.c \
				main.c \
				arg_checker.c \
				error_exit.c \
				create_list.c \
				big_sort.c \
				assign_values.c \
				operations.c \
				small_sort.c \
				sort_check.c \
				sort_og_pos.c)

#==============================================================================: Color codes
GREEN		= \033[1;32m
RED			= \033[1;31m
BLUE		= \033[1;34m
MAGENTA		= \033[1;35m
RESET		= \033[0m

#==============================================================================: Make commands
all: message $(NAME)

#==============================================================================: Executable run command
run:
	@./$(NAME) $(ARGS)

#==============================================================================: Main compile
$(NAME): $(OBJS)
	@$(MAKE) -C libft
	@$(CC) $(OBJS) $(HEADERS) $(LIBFT)/libft.a -o $(NAME)
	@echo "$(GREEN)✅Done compiling $(NAME)$(RESET)"

#==============================================================================: File compile
objs/%.o: srcs/%.c
	@$(MKDIR) objs
	@$(CC) $(CFLAGS) -o $@ $< -I .
ifeq ($(DB),1)
	@printf "$(GREEN)\r🔨Compiling: $(MAGENTA)$(notdir $<)$(GREEN)\r\e[35C[OK]\n$(RESET)"
endif

#==============================================================================: Build messages
message:
	@echo "$(BLUE)🔨Creating object folder$(RESET)"
	@echo "$(GREEN)🔨Compiling: $(MAGENTA)$(NAME)...$(RESET)"

#==============================================================================: Remove all object files
clean:
	@$(RM) objs/
	@$(MAKE) clean -C libft
	@echo "$(RED)🧹Cleaned object folders!$(RESET)"

#==============================================================================: Remove object files and executables
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C libft
	@echo "$(RED)🧹Cleaned $(NAME)!$(RESET)"

#==============================================================================: Remove object files and executables then remake executables
re: fclean all

.PHONY: all clean fclean re message