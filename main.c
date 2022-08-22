/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 17:18:20 by kblok         #+#    #+#                 */
/*   Updated: 2022/08/22 14:49:36 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = create_list(argc, argv);
	b = NULL;
	fill_og_position(a);
	bubblesort(&a, argc);
}