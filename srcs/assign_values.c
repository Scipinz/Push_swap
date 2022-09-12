/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assign_values.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 12:48:58 by kblok         #+#    #+#                 */
/*   Updated: 2022/09/12 14:58:28 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubblesort(t_node **list_a, int total_args)
{
	t_node	**temp;
	int		arg_count;
	int		i;
	int		swap;

	arg_count = 0;
	while (arg_count <= total_args)
	{
		temp = list_a;
		swap = 0;
		i = 0;
		while (i < total_args - arg_count - 1)
		{
			if (compare_nodes(*temp, (*temp)->next) == 1)
			{
				swap_nodes(temp);
				swap = 1;
			}
			temp = &(*temp)->next;
			i++;
		}
		arg_count++;
		if (swap == 0)
			break ;
	}
}

void	assign_index(t_node **list_a, int argc)
{
	t_node	**temp;
	int		i;

	bubblesort(list_a, argc - 1);
	temp = list_a;
	i = 0;
	while (argc - 1 != 0)
	{
		(*temp)->og_value = i;
		temp = &(*temp)->next;
		i++;
		argc--;
	}
}

void	assign_position(t_node *stack_a)
{
	int		position;

	position = 0;
	while (stack_a)
	{
		stack_a->og_position = position;
		stack_a = stack_a->next;
		position++;
	}
}
