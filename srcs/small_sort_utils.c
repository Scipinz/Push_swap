/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/01 15:50:42 by kblok         #+#    #+#                 */
/*   Updated: 2022/11/09 15:56:26 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lowest_number(t_node **list_a)
{
	int	min;

	min = 2147483647;
	while (*list_a != NULL)
	{
		if (min > (*list_a)->og_value)
			min = (*list_a)->og_value;
		list_a = &(*list_a)->next;
	}
	return (min);
}

int	lowest_position(t_node **list_a, int lowest)
{
	int	position;

	position = 1;
	while ((*list_a)->og_value != lowest)
	{
		position++;
		list_a = &(*list_a)->next;
	}
	return (position);
}
