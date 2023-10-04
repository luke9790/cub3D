/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:54:16 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/02 16:42:38 by pcocci           ###   ########.fr       */
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
