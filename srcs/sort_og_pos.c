/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_og_pos.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 13:41:06 by kblok         #+#    #+#                 */
/*   Updated: 2022/09/12 12:48:21 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_nodes(t_node **stack)
{
	t_node	*temp;

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

static int	comp_pos(t_node *first, t_node *second)
{
	if (second == NULL)
		return (-1);
	if (first->og_position > second->og_position)
		return (1);
	return (0);
}

void	sort_og_position(t_node **list_a, int total_args)
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
			if (comp_pos(*temp, (*temp)->next) == 1)
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
