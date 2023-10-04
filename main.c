/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:38:32 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/03 16:36:06 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Funzione cardine che fa tutto il necessario richiamando altre funzioni. 
Creato il box, inizializziamo.
Creiamo e controlliamo la mappa.
Iniziamo prendendo la posizione e la direzione del giocatore.
Creiamo finestra e immagine ancora vuote e inizializziamo le texture. 
Con raycasting (che sara' il 90% del progetto) creiamo tutti i pixel 
da mettere a schermo (da quanto ho capito). 
Successivamente carichiamo su schermo i dati ottenuti in precedenza e
teniamo in loop aggiornando in base agli input con le 
funzioni di default della libreria minilibx.
Il primo hook e' per chiudere la finestra con la x in alto a destra.
Il secondo key hook serve per l'input dei comandi da tastiera.
Il loop serve senno la finestra si chiude subito dopo l'esecuzione.
 */

/* This function needs to exist, but it is useless for the moment */

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

bool	check_len(char *av)
{
	char **tmp;
	int i;

	tmp = ft_split(av, '/');
	i = 0;
	while (tmp[i])
		i++;
	i--;
	if (ft_strlen(tmp[i]) >= 5)
	{	
		free_matrix(tmp);
		return (true);
	}
	printf("Error\nLa mappa non e' in formato .cub\n");
	free_matrix(tmp);
	return (false);

}

bool	check_extensions(char *av)
{
	int	i;

	i = ft_strlen(av);
	i--;
	if (av[i] != 'b' || av[i-1] != 'u' || av[i-2] != 'c' || av[i-3] != '.')
	{
		printf("Error\nLa mappa non e' in formato .cub\n");
		return (false);
	}
	return (true);
}

void	is_cub(char *av)
{
	if (!check_extensions(av) || !check_len(av))
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
