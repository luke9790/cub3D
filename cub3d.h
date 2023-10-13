/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:40:50 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/13 15:14:18 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <string.h>
# include "./gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"

//WINDOW

# define WIN_WIDTH 640
# define WIN_HEIGHT 500

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

# define NORTH	'N'
# define SOUTH	'S'
# define WEST	'W'
# define EAST	'E'

//EVENTS

# define KEYPRESS 2
# define KEIRELEASE 3
# define DESTROY 17

// KEYS
# define W 119
# define A 97
# define S 115
# define D 100
# define Q 113
# define E 101
# define R 114
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define SPACE 32

# define ESC 65307
# define TAB 65289
# define SHIFT 65505
# define CTRL 65507

# define WALL '1'
# define OPEN '0'

# define MOVESPEED 0.022f
# define MARGIN	0.05f
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define POSSIBLE_PLAYER_CHARS "NSEW"
# define VALID_INSIDE_MAP "0NSEW"
# define VALID_ELEMENT_SURROUNDING "01NSEW"
# define POSSIBLE_PLAYER_CHARS "NSEW"

typedef struct s_image
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			w;
	int			h;	
}				t_image;

typedef struct s_textures
{
	int		sky_rgb[3];
	int		floor_rgb[3];	
	t_image	north;
	t_image	south;
	t_image	east;
	t_image	west;
}				t_textures;

// DATA FOR CALCULATIONS

typedef struct s_raycaster
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
}				t_raycaster;

typedef struct s_camera
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_camera;

typedef struct s_player
{
	double	x;
	double	y;
	double	speed;
	char	orientation;
}				t_player;

typedef struct s_map_check
{
	int	i;
	int	j;
	int	nbr_rows;
	int	nbr_col;
	int	flag;
}				t_map_checks;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_textures	textures;
	char		**parsed_map;
	int			map_height;
	t_image		img;
	t_player	player;
	t_camera	camera;
	bool		wasd_movement[7];
}				t_data;

//BASE FUNCTIONS
int				scene_is_empty(char *file);
void			ft_init_struct(t_data *box);
void			ft_create_map(t_data *box, char *map);
void			ft_check_map(t_data *box);
void			ft_start(t_data *box);
void			ft_init_window(t_data *box);
void			ft_raycasting(t_data *box);
void			init_player_pov(t_data *box);
void			set_player_info(t_player *player_info, int player_x,
					int player_y, char orientation);
int				ft_free_all(t_data *box);
bool			rgb_len(char *av);
void			put_pixel_in_image(t_image *img, int x, int y, uint32_t color);
t_image			new_img(void *mlx_ptr);
void			ground_and_sky(t_data *box);
// PARSE
char			**ft_textures(int fd);
bool			parse_textures(t_data *box, char **textures);
void			parse_tex_colors(t_data *box, char *file);
bool			save_player_info(char **map, t_data *this);
void			start_player(t_data *box);
int				ft_checkwalls(t_data *box, int tmp, t_map_checks *map);
size_t			matrix_len(char **matrix);
char			**get_map(char *file_name, int fd);
bool			parse_map(char **map_part, t_data *box);
// HANDLE_INPUTS
void			rotate_right(t_data *box);
void			rotate_left(t_data *box);
int				ft_quit(int input, t_data *box);
int				key_press(int input, t_data *box);
int				key_release(int input, t_data *box);
void			move_player(t_data *box);
// SUBFUNCTIONS
void			ft_parsing(t_data *box, int tmp, t_map_checks *check);
// COLORS
unsigned int	ft_get_rgb(t_data *box, char *s, int start);
// UTILS
void			ft_print_error(char *str, char **mappa);
void			ft_free_map(char **mappa);
int				ft_free_n_exit(t_data *this);
int				ft_strncmp(char *s1, char *s2);
char			*ft_strncpy(char *str, int start);
void			ft_print_error_n_free(t_data *box, char **mappa, char *str);
void			ft_perror_exit(char *str);
char			*trim_free(char *s1, char const *set);
bool			only_spaces(const char *str);
bool			is_spaces(char c);
char			**ft_split(char const *s, char c);
bool			streq(char *str1, char *str2);
void			free_matrix(char **matrix);
bool			is_onstr(const char *str, int ch);
//UTILS LMLX
void			my_mlx_pixel_put(t_image *img, int x, int y, int color);
void			render_next_frame(t_data *box);
int				handle_no_event(void *data);
void			draw_line(t_image *img, t_data *box);
int				window_loop(t_data *box);
bool			load_img(void *mlx_ptr, t_image *texture, char **path);
uint32_t		get_color(t_data *box, t_raycaster *rc);
unsigned int	ft_color_converter(int r, int g, int b);
// UTILSMATH
long			ft_atoi(const char *nptr);
bool			fits_in_intrange(int n, int lowest, int highest);
bool			is_all_digits(const char *str);
// MOVE2
void			rotate_right(t_data *box);
void			rotate_left(t_data *box);
void			speed_up(t_data *box);
// RAYCASTING2
void			init_rc(t_data *box, t_raycaster *rc, int x);
void			put_pixel_in_image(t_image *img, int x, int y, uint32_t color);
t_image			new_img(void *mlx_ptr);
void			point_rays(t_data *box, t_raycaster *rc);

#endif
