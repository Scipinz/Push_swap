/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_checker.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 17:01:31 by kblok         #+#    #+#                 */
/*   Updated: 2022/08/23 16:14:04 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_check(char **argv, char *str, int i, int argc)
{
	while (i < argc - 1)
	{
		i++;
		if (ft_atoi(str) - ft_atoi(argv[i]) == 0)
			return (0);
	}
	return (1);
}

int	dupe_check(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (str_check(argv, argv[i], i, argc))
			return (0);
		i++;
	}
	return (1);
}

void	check_int(char **argv, int argc)
{
	int		i;
	int		j;
	int		max_int;

	i = 1;
	max_int = 2147483647;
	while (i - 1 < argc - 1)
	{
		j = 0;
		if (ft_atoi(argv[i]) > max_int || ft_atoi(argv[i]) < -2147483648)
			error_exit("Error", 1);
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] != '0' && argv[i][j] != '1' && argv[i][j] != '2' && \
				argv[i][j] != '3' && argv[i][j] != '4' && argv[i][j] != '5' && \
				argv[i][j] != '6' && argv[i][j] != '7' && argv[i][j] != '8' && \
				argv[i][j] != '9' && argv[i][j] != '-')
				error_exit("Error", 1);
			if ((argv[i][j] == '-' && argv[i][j + 1] == '\0') || \
				(argv[i][j] == '-' && argv[i][j + 1] == '-'))
				error_exit("Error", 1);
			j++;
		}
		i++;
	}
}
