/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:40:50 by lmasetti          #+#    #+#             */
/*   Updated: 2023/09/25 16:40:00 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "./gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"

typedef struct	s_image
{
	void		*img_ptr;   // Puntatore all'immagine
	char		*addr;      // Puntatore all'area di memoria dei dati dei pixel
	int			bits_per_pixel; // Numero di bit per ogni pixel (es. 32 bit)
	int			line_length;    // Dimensione di una riga in byte
	int			endian;     // Specifiche sull'ordinamento dei byte (endianess)
	int			w;			// widht
	int			h;			// height
}				t_image;

typedef struct s_cub3d
{
	int				width;
	int				height;
	double			player_x;
	double			player_y;
	char			player_dir;
	double			half_h;
	double			half_w;
	double			fov;
	double			half_fov;
	// dati mappa: matrice iniziale e quella parsata 
	// + altre variabili per i check da fare.
	char			**map;
	char			**parsed_map;
	int				i;
	int				j;
	int				number_of_rows;
	int				flag;
	// dati per finestra e processo mlx. img probabilmente sara' struct a se'.
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	// dati per texture e colore cielo e pavimento
	// (sono tutti da leggere dalla mappa)
	char			*path_to_north;
	char			*path_to_south;
	char			*path_to_east;
	char			*path_to_west;
	unsigned int	sky_color;
	unsigned int	floor_color;
	// immagini (img e' lo schermo, le altre le texture da prendere)
	t_image			img;
	t_image			north;
	t_image			south;
	t_image			west;
	t_image			east;
}				t_cub3d;

//KEYS
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

//BASE FUNCTIONS
void			ft_init_struct(t_cub3d *box);
void			ft_create_map(t_cub3d *box, char *argv);
void			ft_check_map(t_cub3d *box);
void			ft_start(t_cub3d *box);
void			ft_init_window(t_cub3d *box);
// HANDLE_INPUTS
int 			ft_handle_inputs(int input, t_cub3d *box);
// SUBFUNCTIONS
void			ft_parsing(t_cub3d *box, int tmp);
// COLORS
unsigned int	ft_get_rgb(t_cub3d *box, char *s, int start);
// UTILS
void			ft_print_error(char *str, char **mappa);
void			ft_free_map(char **mappa);
int				ft_free_n_exit(t_cub3d *box);
int				ft_strncmp(char *s1, char *s2);
char			*ft_strncpy(char *str, int start);
void			ft_print_error_n_free(t_cub3d *box, char **mappa, char *str);
void			ft_perror_exit(char *str);
// UTILSMATH
long			ft_atoi(const char *nptr);

#endif
