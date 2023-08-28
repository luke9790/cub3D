/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:13:25 by lmasetti          #+#    #+#             */
/*   Updated: 2023/08/25 13:05:38 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* adesso che abbiamo le dimensioni, creiamo una matrice con count,
riapriamo la mappa e copiamo riga per riga il contenuto. */

void	ft_create_map_2(t_cub3d *box, int count, char *map)
{
	int		i;
	int		fd;

	i = 0;
	box->map = (char **) malloc(sizeof(char *) * (count + 1));
	if (!box->map)
		ft_perror_exit("Error allocation memory");
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_perror_exit("Error\n");
	while (i < count)
		box->map[i++] = get_next_line(fd);
	box->map[i] = 0;
	close(fd);
}

/* aprimo la mappa, cioe' av[1], e controlliamo che non sia vuota 
 e contiamo quante righe e' grande con count. */

void	ft_create_map(t_cub3d *box, char *map)
{
	int		fd;
	int		count;
	char	*tmp;

	count = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_perror_exit("Error opening the map\n");
	tmp = get_next_line(fd);
	if (tmp != NULL)
		count++;
	else
		ft_perror_exit("Error: empty map\n");
	while (tmp != NULL)
	{
		free (tmp);
		tmp = get_next_line(fd);
		count++;
	}
	close(fd);
	ft_create_map_2(box, count, map);
}

/* Inizializziamo la struttura. Abbiamo le dimensioni della finestra
   e la posizione del giocatore (widht,height, player x e y).
   Il FOV (campo visivo) a 66 e' quello consigliato. 
   Tutti i dati half servono successivamente, credo per dare dei
   punti di riferimento per il raycasting.
   Ci sara' da aggiungere i dati relativi al raycasting.
   I vari path sono i percorsi dove trovare le texture da caricare
   per i muri. Andando avanti vedremo se ci servono altri dati.
*/
void	ft_init_struct(t_cub3d *box)
{
	box->width = 800;
	box->height = 600;
	box->player_x = 0;
	box->player_y = 0;
	box->half_h = box->height / 2;
	box->half_w = box->width / 2;
	box->fov = 66;
	box->half_fov = box->fov / 2;
	box->path_to_north = NULL;
	box->path_to_south = NULL;
	box->path_to_east = NULL;
	box->path_to_west = NULL;
}
