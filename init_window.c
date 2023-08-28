/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:01:20 by lmasetti          #+#    #+#             */
/*   Updated: 2023/08/28 11:01:58 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Inizializziamo le texture, salvandole nelle immagini del box. 
Sicuramente ci servira' altra roba da inizializzare. (getDataAddress in particolare)
*/

void	ft_init_texture(t_cub3d *box)
{
	box->north.img_ptr = mlx_xpm_file_to_image(box->mlx_ptr, box->path_to_north,
			&box->north.w, &box->north.h);
	box->south.img_ptr = mlx_xpm_file_to_image(box->mlx_ptr, box->path_to_south,
			&box->south.w, &box->south.h);
	box->east.img_ptr = mlx_xpm_file_to_image(box->mlx_ptr, box->path_to_east,
			&box->east.w, &box->east.h);
	box->west.img_ptr = mlx_xpm_file_to_image(box->mlx_ptr, box->path_to_west,
			&box->west.w, &box->west.h);
}

/* creiamo la finestra dopo aver inizializzato. (tutte funzioni minilibx) */

void	ft_create_window(t_cub3d *box)
{
	box->mlx_ptr = mlx_init();
	box->win_ptr = mlx_new_window(box->mlx_ptr, box->width,
			box->height, "cub3d");
}

/* iniziamo a creare l'immagine adesso che abbiamo la finestra a disposizione. */

void	ft_create_image(t_cub3d *box)
{
	box->img.img_ptr = mlx_new_image(box->mlx_ptr, box->width, box->height);
	box->img.addr = mlx_get_data_addr(box->img.img_ptr, &box->img.bits_per_pixel,
			&box->img.line_length, &box->img.endian);
}

void	ft_init_window(t_cub3d *box)
{
	ft_create_window(box);
	ft_create_image(box);
	ft_init_texture(box);
}