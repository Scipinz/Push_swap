/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 13:34:30 by kblok         #+#    #+#                 */
/*   Updated: 2022/09/12 12:47:35 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_swap(t_node **stack)
{
	t_node	*temp;

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
	ft_putendl_fd("sa", 1);
}

void	rotate(t_node **stack)
{
	t_node	*temp;
	t_node	*temp_first;

	temp = list_last(*stack);
	temp_first = *stack;
	temp->next = temp_first;
	temp_first = temp_first->next;
	(*stack)->next = NULL;
	*stack = temp_first;
	ft_putendl_fd("ra", 1);
}

void	reverse_rot(t_node **stack)
{
	t_node	*temp;
	int		i;
	int		total;

	i = 0;
	total = list_size(*stack);
	temp = list_last(*stack);
	temp->next = *stack;
	*stack = temp;
	while (temp)
	{
		if ((i + 1) == total)
		{
			temp->next = NULL;
			break ;
		}
		i++;
		temp = temp->next;
	}
	ft_putendl_fd("rra", 1);
}

void	to_stack_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*new;

	new = *stack_a;
	if (new == NULL)
		return ;
	*stack_a = new->next;
	new->next = *stack_b;
	*stack_b = new;
	ft_putendl_fd("pa", 1);
}

void	to_stack_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*new;

	new = *stack_a;
	if (new == NULL)
		return ;
	*stack_a = new->next;
	new->next = *stack_b;
	*stack_b = new;
	ft_putendl_fd("pb", 1);
}
