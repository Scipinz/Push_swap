/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 17:18:20 by kblok         #+#    #+#                 */
/*   Updated: 2022/10/31 12:59:07 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*list_a;
	t_node	*list_b;

	if (argc == 1)
		return (0);
	check_int(argv, argc);
	if (dupe_check(argc, argv) == 0)
		error_exit("Error", 1);
	list_a = create_list(argc, argv);
	list_b = NULL;
	if (argc <= 6)
		stack_sort(argc, &list_a, &list_b);
	else
	{
		sort_og_position(&list_a, argc - 1);
		big_sort(&list_a, &list_b);
	}
	return (0);
}
