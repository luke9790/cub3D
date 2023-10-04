/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:13:25 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/03 16:27:38 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* adesso che abbiamo le dimensioni, creiamo una matrice con count,
riapriamo la mappa e copiamo riga per riga il contenuto. */

/* void	ft_create_map_2(t_data *box, int count, char *map)
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
} */

/* aprimo la mappa, cioe' av[1], e controlliamo che non sia vuota 
 e contiamo quante righe e' grande con count. */

/* void	ft_create_map(t_data *box, char *map)
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
	ft_create_map_2(box, count, map);
	close(fd);
} */

/* Inizializziamo la struttura. Abbiamo le dimensioni della finestra
   e la posizione del giocatore (widht,height, player x e y).
   Il FOV (campo visivo) a 66 e' quello consigliato. 
   Tutti i dati half servono successivamente, credo per dare dei
   punti di riferimento per il raycasting.
   Ci sara' da aggiungere i dati relativi al raycasting.
   I vari path sono i percorsi dove trovare le texture da caricare
   per i muri. Andando avanti vedremo se ci servono altri dati.
*/

t_image	init_img(void)
{
	return ((t_image)
		{
			.img_ptr = NULL,
			.addr = NULL,
			.bits_per_pixel = 0,
			.line_length  = 0,
			.endian = 0
		});
}

void	ft_init_struct(t_data *box)
{
	box->mlx_ptr = mlx_init();
	if (!box->mlx_ptr)
		write(1, "error mlx_ptr", 14);
	box->win_ptr = mlx_new_window(box->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	// da aggiungere textures dopo
	/* box->textures.north.ptr = NULL;
	box->textures.south.ptr = NULL;
	box->textures.east.ptr = NULL;
	box->textures.west.ptr = NULL; */
	//check player pov
	/* set_player_info(&box->player, 3, 5, 'N');
	init_player_pov(box); */
	box->wasd_movement[0] = false;
	box->wasd_movement[1] = false;
	box->wasd_movement[2] = false;
	box->wasd_movement[3] = false;
	box->wasd_movement[4] = false;
	box->wasd_movement[5] = false;
	box->wasd_movement[6] = false;
	box->parsed_map = NULL;
	box->textures.east.img_ptr = NULL;
	box->textures.west.img_ptr = NULL;
	box->textures.north.img_ptr = NULL;
	box->textures.south.img_ptr = NULL;
	box->textures.east.img_ptr = NULL;
	box->textures.west.img_ptr = NULL;
	box->textures.north.img_ptr = NULL;
	box->textures.south.addr = NULL;
	box->textures.north.addr = NULL;
	box->textures.east.addr = NULL;
	box->textures.west.addr = NULL;
	box->img = init_img();
}
