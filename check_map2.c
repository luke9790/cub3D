/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:45:51 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/12 14:48:44 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int 	scene_is_empty(int fd)
{
	char buffer[1024];
    bool allEmptyOrWhitespace = true;
    
    while (1) {
        ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
        
        
        if (bytesRead == 0) {
            break; // Reached the end of the file
        }
        
        for (ssize_t i = 0; i < bytesRead; i++) {
            if (buffer[i] != '\n') {
                allEmptyOrWhitespace = false;
                break;
            }
        }
    }
    
    close(fd);
    
    return allEmptyOrWhitespace;
}

bool	rgb_len(char *av)
{
	char	**tmp;

	tmp = ft_split(av, ',');
	if (matrix_len(tmp) != 3)
	{
		free_matrix(tmp);
		return (false);
	}
	free_matrix(tmp);
	return (true);
}
