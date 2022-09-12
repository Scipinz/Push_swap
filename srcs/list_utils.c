/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/01 14:45:18 by kblok         #+#    #+#                 */
/*   Updated: 2022/09/12 12:47:25 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size(t_node *stack_a)
{
	int	nodes;

	nodes = 0;
	while (stack_a)
	{
		nodes++;
		stack_a = stack_a->next;
	}
	return (nodes);
}

t_node	*list_last(t_node *list)
{
	if (!list)
		return (NULL);
	while (list)
	{
		if (list->next == NULL)
			return (list);
		list = list->next;
	}
	return (list);
}

void	free_list(t_node *head)
{
	t_node	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
