/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 17:18:20 by kblok         #+#    #+#                 */
/*   Updated: 2022/08/23 17:26:41 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_og_position(t_node *a)
{
	int i;

	i = 0;
	while (a)
	{
		a->og_position = i;
		a = a->next;
		i++;
	}
}

static void	print_list(t_node *a)
{
	int	idx;

	idx = 0;
	while (a)
	{
		printf("idx: %i\tog_value: %i\tog_pos: %i\n", idx, a->og_value, a->og_position);
		a = a->next;
		idx++;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	// t_node	*b;

	a = create_list(argc, argv);
	fill_og_position(a);
	print_list(a);
	// b = NULL;
	// bubblesort(&a, argc);
}
