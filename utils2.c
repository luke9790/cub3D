/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:48:04 by lmasetti          #+#    #+#             */
/*   Updated: 2023/08/28 10:44:58 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strncpy(char *str, int start)
{
	char	*dst;
	int		i;

	i = 0;
	dst = (char *) malloc(sizeof(char) * (ft_strlen(str) - start));
	if (!dst)
		perror("Error\n");
	while (start < ft_strlen(str) - 1)
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

int	ft_free_n_exit(t_cub3d *box)
{
	mlx_destroy_image(box->mlx_ptr, box->north.img_ptr);
	mlx_destroy_image(box->mlx_ptr, box->south.img_ptr);
	mlx_destroy_image(box->mlx_ptr, box->east.img_ptr);
	mlx_destroy_image(box->mlx_ptr, box->west.img_ptr);
	mlx_destroy_image(box->mlx_ptr, box->img.img_ptr);
	mlx_destroy_window(box->mlx_ptr, box->win_ptr);
	mlx_destroy_display(box->mlx_ptr);
	free(box->mlx_ptr);
	free(box->path_to_east);
	free(box->path_to_west);
	free(box->path_to_north);
	free(box->path_to_south);
	ft_free_map(box->map);
	ft_free_map(box->parsed_map);
	exit(0);
	return (0);
}
