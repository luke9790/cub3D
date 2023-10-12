/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:54:16 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/12 16:31:43 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_error(char *str, char **mappa)
{
	printf("%s", str);
	ft_free_map(mappa);
	exit(1);
}

void	ft_free_map(char **mappa)
{
	int	i;

	i = 0;
	while (mappa[i])
		free(mappa[i++]);
	free(mappa);
}

void	ft_perror_exit(char *str)
{
	perror(str);
	exit (1);
}

char	*ft_strncpy(char *str, int start)
{
	char	*dst;
	int		i;

	i = 0;
	dst = (char *) malloc(sizeof(char) * (ft_strlen(str) - start));
	if (!dst)
		perror("Error\n");
	while (start < (int)ft_strlen(str) - 1)
		dst[i++] = str[start++];
	dst[i] = '\0';
	return (dst);
}

int	ft_strncmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
