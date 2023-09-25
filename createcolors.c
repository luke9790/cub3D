/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createcolors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 09:48:49 by lmasetti          #+#    #+#             */
/*   Updated: 2023/09/25 16:32:13 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
In questa funzione prendiamo la stringa che rappresenta il colore e troviamo
il numero corrispondente. Prendiamo il pezzo tra i e start(che avanza fino a 
trovare una virgola o \n), lo salviamo in res e convertiamo con atoi.
*/
static int	ft_create_color_num(char *s, int start)
{
	int		i;
	int		num;
	char	*res;

	i = start;
	while (s[start] != ',' && s[start] != '\n')
		start++;
	res = (char *) malloc(sizeof(char) * start - i + 1);
	start = i;
	i = 0;
	while (s[start] != ',' && s[start] != '\n')
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	num = ft_atoi(res);
	free(res);
	return (num);
}

/*
i tre valori singoli vengono inseriti in un intero che ci permette di salvare
il tutto in un int, che verra' usato in pixel_put.

int
mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color );
*/

static unsigned int	ft_color_converter(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

/*
Dobbiamo prendere la scritta nella mappa e convertirla in rgb. Usiamo i
come indice e avanziamo fino a trovare le virgole, in modo tale da avere
i numeri di r,g e b.
*/
unsigned int	ft_get_rgb(t_cub3d *box, char *s, int start)
{
	int		i;
	int		r;
	int		g;
	int		b;

	i = start;
	r = 256;
	g = 256;
	b = 256;
	r = ft_create_color_num(s, i);
	while (s[i] != ',')
		i++;
	i++;
	g = ft_create_color_num(s, i);
	while (s[i] != ',')
		i++;
	i++;
	b = ft_create_color_num(s, i);
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		ft_print_error_n_free(box, box->map, "Error\nColori rgb errati\n");
	return (ft_color_converter(r, g, b));
}
