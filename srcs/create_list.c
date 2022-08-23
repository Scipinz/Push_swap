/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_list.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/23 15:49:07 by kblok         #+#    #+#                 */
/*   Updated: 2022/08/23 17:33:43 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*list_last(t_node *a)
{
	if (a->next == NULL)
		return (a);
	while (a)
	{
		if (a->next == NULL)
			return (a);
		a = a->next;
	}
	return (NULL);
}

static t_node	*list_new(int og_value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		error_exit ("Error\n", 1);
	new->og_value = og_value;
	new->og_position = 0;
	new->sorted_position = 0;
	new->next = NULL;
	return (new);
}

static void	lstadd_back(t_node **a, int og_value)
{
	t_node	*new;
	t_node	*temp;

	new = list_new(og_value);
	if (!(*a))
	{
		*a = new;
		return ;
	}
	temp = list_last (*a);
	temp->next = new;
}

static t_node	*create_head(char **argv)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		error_exit("Error\n", 1);
	new->og_value = ft_atoi(argv[1]);
	new->og_position = 0;
	new->sorted_position = 0;
	new->next = NULL;
	return (new);
}

t_node	*create_list(int argc, char **argv)
{
	t_node	*a;
	int		args;
	int		argv_index;

	args = argc - 2;
	argv_index = 2;
	a = create_head(argv);
	while (args)
	{
		lstadd_back(&a, ft_atoi(argv[argv_index]));
		argv_index++;
		args--;
	}
	return (a);
}
