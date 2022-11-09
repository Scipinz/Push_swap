/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 13:59:42 by kblok         #+#    #+#                 */
/*   Updated: 2022/11/09 13:56:15 by kblok         ########   odam.nl         */
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
void	big_sort(t_node **stack, t_node **stack_b);
void	free_list(t_node *head);
t_node	*list_last(t_node *list);
int		list_size(t_node *stack_a);
int		lowest_number(t_node **list_a);
int		lowest_position(t_node **list_a, int lowest);
void	stack_sort(int argc, t_node **list_a, t_node **list_b);
void	list_swap(t_node **stack);
void	rotate(t_node **stack);
void	reverse_rot(t_node **stack);
void	to_stack_a(t_node **stack, t_node **stack_b);
void	to_stack_b(t_node **stack, t_node **stack_b);
void	sort_og_position(t_node **list_a, int total_args);

#endif