/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_checker.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 17:01:31 by kblok         #+#    #+#                 */
/*   Updated: 2022/08/22 17:05:04 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	check_integer(char **argv, int argc)
{
	int		i;
	int		k;
	int		max_int;

	i = 1;
	max_int = 2147483647;
	while (i - 1 < argc - 1)
	{
		k = 0;
		if (ft_atoi(argv[i]) > max_int || ft_atoi(argv[i]) < -2147483648)
			error_exit("Error", 1);
		while (argv[i][k] != '\0')
		{
			if (argv[i][k] != '0' && argv[i][k] != '1' && argv[i][k] != '2' && \
				argv[i][k] != '3' && argv[i][k] != '4' && argv[i][k] != '5' && \
				argv[i][k] != '6' && argv[i][k] != '7' && argv[i][k] != '8' && \
				argv[i][k] != '9' && argv[i][k] != '-')
				error_exit("Error", 1);
			if ((argv[i][k] == '-' && argv[i][k + 1] == '\0') || \
				(argv[i][k] == '-' && argv[i][k + 1] == '-'))
				error_exit("Error", 1);
			k++;
		}
		i++;
	}
}