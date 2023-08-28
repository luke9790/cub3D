/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:38:32 by lmasetti          #+#    #+#             */
/*   Updated: 2023/08/28 11:03:41 by lmasetti         ###   ########.fr       */
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

void	ft_everything(char **av)
{
	t_cub3d	box;

	ft_init_struct(&box);
	ft_create_map(&box, av[1]);
	ft_check_map(&box);
	ft_start(&box);
	ft_init_window(&box);
	// ft_raycasting();
	// mlx_put_image_to_window(box.mlx_ptr, box.win_ptr, box.img_ptr, 0, 0);
	mlx_hook(box.win_ptr, 17, 0, ft_free_n_exit, &box);
	mlx_key_hook(box.win_ptr, ft_handle_inputs, &box);
	mlx_loop(box.mlx_ptr);
}

void	is_cub(char *av)
{
	int	i;

	i = ft_strlen(av);
	i--;
	if (av[i] != 'b' || av[i-1] != 'u' || av[i-2] != 'c' || av[i-3] != '.')
	{
		printf("Error\nLa mappa non e' in formato .cub\n");
		exit(0);
	}
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
