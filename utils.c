/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:54:16 by lmasetti          #+#    #+#             */
/*   Updated: 2023/08/25 12:38:32 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_error(char *str, char **mappa)
{
	printf("%s", str);
	ft_free_map(mappa);
	exit(1);
}

void	ft_print_error_n_free(t_cub3d *box, char **mappa, char *str)
{
	free(box->path_to_east);
	free(box->path_to_west);
	free(box->path_to_north);
	free(box->path_to_south);
	ft_print_error(str, mappa);
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
