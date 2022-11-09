/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/01 16:04:41 by kblok         #+#    #+#                 */
/*   Updated: 2022/11/09 15:57:06 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_node **list_a)
{
	list_swap(list_a);
}

static void	sort_three(t_node **list_a)
{
	int	swap_first;
	int	swap_second;
	int	rot_third;

	swap_first = compare_nodes(*list_a, (*list_a)->next);
	swap_second = compare_nodes((*list_a)->next, (*list_a)->next->next);
	rot_third = compare_nodes((*list_a)->next->next, (*list_a));
	if (swap_first == 1 && swap_second == 0 && rot_third == 1)
		list_swap(list_a);
	if (swap_first == 1 && swap_second == 1 && rot_third == 0)
	{
		list_swap(list_a);
		reverse_rot(list_a);
	}
	if (swap_first == 1 && swap_second == 0 && rot_third == 0)
		rotate(list_a);
	if (swap_first == 0 && swap_second == 1 && rot_third == 1)
	{
		list_swap(list_a);
		rotate(list_a);
	}
	if (swap_first == 0 && swap_second == 1 && rot_third == 0)
		reverse_rot(list_a);
}

static void	sort_four(t_node **list_a, t_node **list_b)
{
	int	lowest;
	int	pos;

	lowest = lowest_number(list_a);
	pos = lowest_position(list_a, lowest);
	if (pos == 2)
		rotate(list_a);
	if (pos == 3)
	{
		rotate(list_a);
		rotate(list_a);
	}
	if (pos == 4)
		reverse_rot(list_a);
	if (sort_check(list_a) == 0)
	{
		to_stack_b(list_a, list_b);
		sort_three(list_a);
		to_stack_a(list_b, list_a);
	}
}

static void	sort_five(t_node **list_a, t_node **list_b)
{
	int	lowest;
	int	pos;

	lowest = lowest_number(list_a);
	pos = lowest_position(list_a, lowest);
	if (pos == 2)
		rotate(list_a);
	if (pos == 3)
	{
		rotate(list_a);
		rotate(list_a);
	}
	if (pos == 4)
	{
		reverse_rot(list_a);
		reverse_rot(list_a);
	}
	if (pos == 5)
		reverse_rot(list_a);
	if (sort_check(list_a) == 0)
	{
		to_stack_b(list_a, list_b);
		sort_four(list_a, list_b);
		to_stack_a(list_b, list_a);
	}
}

void	stack_sort(int argc, t_node **list_a, t_node **list_b)
{
	if (argc == 3)
		sort_two(list_a);
	else if (argc == 4)
		sort_three(list_a);
	else if (argc == 5)
		sort_four(list_a, list_b);
	else if (argc == 6)
		sort_five(list_a, list_b);
}
