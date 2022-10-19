/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/01 14:25:20 by kblok         #+#    #+#                 */
/*   Updated: 2022/10/19 16:49:06 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	biggest_num(t_node **stack_a)
{
	t_node	*temp;

	temp = list_last(*stack_a);
	return (temp->og_position);
}

static int	get_max_bits(t_node **stack)
{
	int	max_bits;
	int	max_num;

	max_bits = 0;
	max_num = biggest_num(stack);
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	big_sort(t_node **stack, t_node **stack_b)
{
	int	i;
	int	j;
	int	max_bits;
	int	stack_size;

	i = 0;
	max_bits = get_max_bits(stack);
	stack_size = list_size(*stack);
	while (i < max_bits)
	{
		j = 0;
		while (j < stack_size)
		{
			if ((((*stack)->og_value >> i) & 1) == 1)
				rotate(stack);
			else
				to_stack_b(stack, stack_b);
			j++;
		}
		i++;
		while ((*stack_b)->next != NULL)
			to_stack_a(stack_b, stack);
		to_stack_a(stack_b, stack);
	}
}
