/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kblok <kblok@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/16 18:21:12 by kblok         #+#    #+#                 */
/*   Updated: 2022/11/09 13:55:13 by kblok         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
long	ft_atoi(const char *str)
{
	int	idx;
	int	res;
	int	sign;

	idx = 0;
	res = 0;
	sign = 1;
	while (ft_isspace((str[idx])))
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while (ft_isdigit(str[idx]))
	{
		res = res * 10 + str[idx] - '0';
		idx++;
	}
	return (sign * res);
}

// COMMENTS:

// res = res * 10 + str[idx] - '0';
// - '0' to make char to int
// res * 10 to go to the following place in the number
// that will be converted to an int.