/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsmath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:46:33 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/12 16:32:17 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	matrix_len(char **matrix)
{
	size_t	i;

	i = 0;
	if (!matrix)
		return (0);
	while (matrix[i])
		i += 1;
	return (i);
}

bool	is_all_digits(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i += 1;
	}
	return (true);
}

bool	fits_in_intrange(int n, int lowest, int highest)
{
	return (n >= lowest && n <= highest);
}

static int	ft_atoi_check_char(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '+' && str[i] != '-' && (str[i] < '0' || str[i] > '9'))
			return (256);
		i++;
	}
	return (0);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	if (ft_atoi_check_char(nptr) == 256)
		return (256);
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}
