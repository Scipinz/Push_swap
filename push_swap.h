/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 13:59:42 by kblok         #+#    #+#                 */
/*   Updated: 2022/08/31 13:46:43 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	int				og_value;
	int				og_position;
	int				sorted_position;
	struct s_node	*next;
}	t_node;

t_node	*create_list(int argc, char **argv);
void	error_exit(char *str, int exit_code);
void	check_int(char **argv, int argc);
int		dupe_check(int argc, char **argv);
void	assign_index(t_node **list_a, int argc);
void	assign_position(t_node *stack_a);
int		compare_nodes(t_node *first, t_node *second);
int		sort_check(t_node **stack_a);
void	swap_nodes(t_node **stack);

#endif