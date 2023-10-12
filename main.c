/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:38:32 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/12 15:28:46 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Con init struct inizializziamo le strutture t_data e image. 
In parse tex colors prendiamo texture e mappa (con controlli).
Con start player settiamo il giocatore e la sua posizione e direzione.
I vari hook servono per gestire i vari input, mentre il loop
si basa su windows loop che crea l'immagine a schermo e l'aggiorna via via.
*/

void	ft_everything(char **av)
{
	t_data	box;

	ft_init_struct(&box);
	parse_tex_colors(&box, av[1]);
	start_player(&box);
	mlx_hook(box.win_ptr, 17, 0, ft_free_n_exit, &box);
	mlx_hook(box.win_ptr, 2, 1L << 0, key_press, &box);
	mlx_hook(box.win_ptr, 3, 1L << 1, key_release, &box);
	mlx_loop_hook(box.mlx_ptr, window_loop, &box);
	mlx_loop(box.mlx_ptr);
}

bool	check_extensions(char *av)
{
	int	i;

	i = ft_strlen(av);
	i--;
	while (i >= 0 && av[i] == ' ')
		i--;
	if (!av[i - 4] || av[i - 4] == '/')
	{
		printf("Error\nLa mappa deve avere un nome\n");
		return (false);
	}
	if (av[i] != 'b' || av[i -1] != 'u' || av[i -2] != 'c' || av[i -3] != '.')
	{
		printf("Error\nLa mappa non e' in formato .cub\n");
		return (false);
	}
	return (true);
}

void	is_cub(char *av)
{
	if (!check_extensions(av))
		exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		is_cub(av[1]);
		ft_everything(av);
	}
	printf("Error\nNumero argomenti errato\n");
}
