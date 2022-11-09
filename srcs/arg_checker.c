/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_checker.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 17:01:31 by kblok         #+#    #+#                 */
/*   Updated: 2022/11/09 13:55:49 by kblok         ########   odam.nl         */
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
		if (str_check(argv, argv[i], i, argc) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	check_int(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i - 1 < argc - 1)
	{
		j = 0;
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
		{
			printf("hi");
			error_exit("Error", 1);
		}
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				error_exit("Error", 1);
			if ((argv[i][j] == '-' && argv[i][j + 1] == '\0') || \
				(argv[i][j] == '-' && argv[i][j + 1] == '-'))
				error_exit("Error", 1);
			j++;
		}
		i++;
	}
}
