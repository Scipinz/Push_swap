/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_check.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 12:39:52 by kblok         #+#    #+#                 */
/*   Updated: 2022/08/31 13:40:38 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_nodes(t_node *first, t_node *second)
{
	if (second == NULL)
		return (-1);
	if (first->og_value > second->og_value)
		return (1);
	return (0);
}

int	sort_check(t_node **stack_a)
{
	t_node *temp;

	temp = (*stack_a);
	while (temp->next != NULL)
	{
		if (compare_nodes(temp, temp->next) == 1)
			return (0);
		temp = temp->next;
	}
	return (1);
}