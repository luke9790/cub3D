/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:32:37 by lmasetti          #+#    #+#             */
/*   Updated: 2023/08/28 11:01:16 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Apriamo e chiudiamo uno alla volta i percorsi copiati in precedenza dalle 
mappe. Se mancano del tutto o non vengono aperti stampiamo errore e chiudiamo. */

void	ft_check_path(t_cub3d *box)
{
	int	fd;

	if (box->path_to_north == NULL || box->path_to_south == NULL
		|| box->path_to_east == NULL || box->path_to_west == NULL)
		ft_print_error_n_free(box, box->map, "Error\ntexture mancante\n");
	fd = open(box->path_to_east, O_RDONLY);
	if (fd < 0)
		ft_print_error_n_free(box, box->map, "Error\ntexture EA non valida\n");
	close (fd);
	fd = open(box->path_to_west, O_RDONLY);
	if (fd < 0)
		ft_print_error_n_free(box, box->map, "Error\ntexture WE non valida\n");
	close (fd);
	fd = open(box->path_to_north, O_RDONLY);
	if (fd < 0)
		ft_print_error_n_free(box, box->map, "Error\ntexture NO non valida\n");
	close (fd);
	fd = open(box->path_to_south, O_RDONLY);
	if (fd < 0)
		ft_print_error_n_free(box, box->map, "Error\ntexture SO non valida\n");
	close (fd);
}

unsigned int	ft_get_color(t_cub3d *box, char *s, int start)
{
	// da fare, bisogna convertire con atoi la stringa s (pescata dalla mappa) 
	// che ha i valori rgb del pavimento e del cielo. Start e' il punto da
	// dove inizia il nostro indice (ragionamento simile a ft_strncpy ma si 
	// puo modificare come ci pare). La roba sotto e' per compilare per ora ma non 
	// serve a nulla
	unsigned int temp;

	(void)s;

	temp = box->i+1+start;

	return(temp);
}

void	ft_checkwalls(t_cub3d *box)
{
	// da fare, bisogna controllare che la mappa sia chiusa da muri
	(void)box;
}

// ci salviamo il percorso da dove caricare le texture e prendiamo i colori 
// per cielo e pavimento.

static void	ft_check_parameters(t_cub3d *box)
{
	if (ft_strncmp(box->map[box->j], "NO ") == 1)
		box->path_to_north = ft_strncpy(box->map[box->j], 3);
	else if (ft_strncmp(box->map[box->j], "SO ") == 1)
		box->path_to_south = ft_strncpy(box->map[box->j], 3);
	else if (ft_strncmp(box->map[box->j], "WE ") == 1)
		box->path_to_west = ft_strncpy(box->map[box->j], 3);
	else if (ft_strncmp(box->map[box->j], "EA ") == 1)
		box->path_to_east = ft_strncpy(box->map[box->j], 3);
	else if (ft_strncmp(box->map[box->j], "F ") == 1)
		box->floor_color = ft_get_color(box, box->map[box->j], 2);
	else if (ft_strncmp(box->map[box->j], "C ") == 1)
		box->sky_color = ft_get_color(box, box->map[box->j], 2);
}

/* adesso che abbiamo la mappa nel box, dobbiamo controllare se e' fatta bene.
contiamo il numero di righe e con controlliamo se rispettano i parametri.
Con i due check interni controlliamo la presenza dei path per le texture
dei muri e se i colori di soffitto e pavimento sono validi.
Il ciclo while in fondo serve per capire dove parte la mappa vera e propria.
La parte finale serve per controllare che la mappa sia chiusa (muri) e 
per il parsing della mappa */

void	ft_check_map(t_cub3d *box)
{
	int	tmp;

	box->i = 0;
	box->j = 0;
	box->number_of_rows = 0;
	box->flag = 0;
	while (box->map[box->j])
	{
		box->number_of_rows++;
		ft_check_parameters(box);
		box->j++;
	}
	ft_check_path(box);
	tmp = box->number_of_rows;
	while ((box->map[tmp - 1][0] == ' '	|| box->map[tmp - 1][0] == '1'))
		tmp--;
	ft_checkwalls(box);
	ft_parsing(box, tmp);
}
