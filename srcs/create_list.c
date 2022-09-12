/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_list.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 15:49:07 by kblok         #+#    #+#                 */
/*   Updated: 2022/09/12 15:44:27 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_head(int argc, char **argv)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(t_node));
	if (!head)
		error_exit("Error", 1);
	head->og_value = ft_atoi(argv[argc - 1]);
	head->og_position = 0;
	head->sorted_position = 0;
	head->next = NULL;
	return (head);
}

static t_node	*list_new(int og_value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		error_exit ("Error", 1);
	new->og_value = og_value;
	new->og_position = 0;
	new->sorted_position = 0;
	new->next = NULL;
	return (new);
}

static void	push(t_node **head, int og_value)
{
	t_node	*node;

	node = list_new(og_value);
	if (!node || !head)
		error_exit("Error", 1);
	node->next = *head;
	*head = node;
}

static t_node	*link_list(int argc, char **argv)
{
	t_node	*head;
	int		arg_count;

	head = create_head(argc, argv);
	arg_count = argc - 2;
	while (arg_count)
	{
		push(&head, ft_atoi(argv[arg_count]));
		arg_count--;
	}
	return (head);
}

t_node	*create_list(int argc, char **argv)
{
	t_node	*stack_a;

	stack_a = link_list(argc, argv);
	if (sort_check(&stack_a) == 1)
	{
		free_list(stack_a);
		exit(1);
	}
	if (argc > 6)
	{
		assign_position(stack_a);
		assign_index(&stack_a, argc);
	}
	return (stack_a);
}
