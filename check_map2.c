/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:45:51 by lmasetti          #+#    #+#             */
/*   Updated: 2023/08/28 09:51:53 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* il parsing della mappa e' semplicemente "accorciare" la mappa originale,
togliendo le indicazioni iniziali relative a texture e colori. Tmp e' la riga
in cui inizia davvero la mappa, number or rows il totale delle righe della
stessa.
*/

void	ft_parsing(t_cub3d *box, int tmp)
{
	int	i;

	i = 0;
	box->parsed_map = (char **) malloc (sizeof(char*) * (box->number_of_rows - tmp + 1));
	if (!box->parsed_map)
	{
		ft_free_map(box->map);
		ft_perror_exit("Error\n");
	}
	while (tmp < box->number_of_rows)
		box->parsed_map[i++] = ft_strdup(box->map[tmp++]);
	box->parsed_map[i] = 0;
}