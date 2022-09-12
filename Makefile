# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kblok <kblok@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/16 20:46:21 by kblok         #+#    #+#                  #
#    Updated: 2022/09/12 14:28:04 by kblok         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#==============================================================================: Filename
NAME		= 	push_swap

#==============================================================================: Source to object conversion 
OBJS		= 	$(SRCS:srcs/%.c=objs/%.o)

#==============================================================================: Compile variables
CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra -c
RM			=	rm -rf
AR			=	ar rcs
MKDIR		=	mkdir -p
HEADERS		= 	-I $(LIBFT) -I $(PUSH_SWAP)

#==============================================================================: Include files
LIBFT		= 	libft/
PUSH_SWAP	=	.

#==============================================================================: Source files 
SRCS		=	$(addprefix srcs/, \
				push_swap.c \
				arg_checker.c \
				error_exit.c \
				create_list.c \
				big_sort.c \
				assign_values.c \
				operations.c \
				small_sort.c \
				sort_check.c \
				sort_og_pos.c \
				small_sort_utils.c \
				list_utils.c)

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
	@$(MAKE) -C $(LIBFT)
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

# #===============================================================================: Filename
# NAME		= push_swap

# #===============================================================================: Source to object conversion location
# OBJS		= $(subst srcs, objs, $(SRCS:.c=.o))

# #===============================================================================: Color codes
# GREEN		= \033[1;32m
# RED			= \033[1;31m
# BLUE		= \033[1;34m
# MAGENTA		= \033[1;35m
# RESET		= \033[0m

# #===============================================================================: Include files
# LIBFT		= libft/
# PUSH_SWAP	= .

# #===============================================================================: Compile variables
# CC			= gcc
# CFLAGS		= -Wall -Werror -Wextra
# MAKEFLAGS	= --no-print-directory
# RM			= rm -rf
# MKDIR		= mkdir -p
# HEADERS		= -I $(LIBFT) -I $(PUSH_SWAP)

# #===============================================================================: Sourcefiles
# SRCS		= $(addprefix srcs/, $(addsuffix .c, \
# 				push_swap \
# 				arg_checker \
# 				error_exit \
# 				create_list \
# 				big_sort \
# 				assign_values \
# 				operations \
# 				small_sort \
# 				sort_check \
# 				sort_og_pos \
# 				small_sort_utils \
# 				list_utils))

# #===============================================================================: Make commands
# all: libft message $(NAME)
# ifeq (run,$(firstword $(MAKECMDGOALS)))
#   RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
#   $(eval $(RUN_ARGS):;@:)
# endif

# #===============================================================================: Main compile
# $(NAME): $(OBJS)
# 	@$(CC) $(OBJS) $(HEADERS) $(LIBFT)libft.a -o $(NAME)
# 	@printf "$(GREEN)✅Executable \"$(NAME)\" created!$(RESET)\n\n"

# #===============================================================================: C file compile
# objs/%.o: srcs/%.c
# 	@$(MKDIR) objs
# 	@$(CC) -o $@ -c $< $(HEADERS)
# ifeq ($(DB),1)
# 	@printf "$(GREEN)\r🔨Compiling: $(MAGENTA)$(notdir $<)$(GREEN)\r\e[35C[OK]\n$(RESET)"
# endif

# #===============================================================================: Executable run command
# run: all
# 	@printf "$(GREEN)Executing $(NAME)!\n$(RESET)\n"
# 	@./$(NAME) $(RUN_ARGS)

# #===============================================================================: Build messages
# message:
# 	@printf "$(MAGENTA)🔨Building \"$(NAME)\"\n$(RESET)\n"

# #===============================================================================: Libft Compile
# libft:
# 	@$(MAKE) -C $(LIBFT) $(MAKEFLAGS)

# #===============================================================================: Remove all object files
# clean:
# 	@$(RM) objs/
# 	@$(MAKE) -C $(LIBFT) clean
# 	@printf "$(RED)🧹Removed objects for \"$(NAME)\"!$(RESET)\n"

# #===============================================================================: Remove project object files & executable
# pclean:
# 	@$(RM) objs/
# 	@$(RM) $(NAME)
# 	@printf "$(RED)🧹Removed current objects & current executable for \"$(NAME)\"$(RESET)\n"

# #===============================================================================: Remove all object files and executable
# fclean:
# 	@$(RM) objs/
# 	@$(RM) $(NAME)
# 	@$(MAKE) -C $(LIBFT) fclean
# 	@printf "$(RED)🧹Removed objects for \"$(NAME)\"!$(RESET)\n"
# 	@printf "$(RED)🧹Removed \"$(NAME)\"!$(RESET)\n"

# #===============================================================================: Remove all object files, executable and remake executable
# re: fclean all

# #===============================================================================: To not confuse make
# .PHONY: all, clean, fclean, re, message, run