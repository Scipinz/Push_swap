/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 13:59:42 by kblok         #+#    #+#                 */
/*   Updated: 2022/08/22 14:20:59 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	int				og_value;
	int				og_position;
	int				sorted_position;
	struct s_node 	*next;
} t_node;

#endif