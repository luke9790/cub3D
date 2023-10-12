/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:45:51 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/12 15:26:35 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	custom_isalnum(char c)
{
	return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
int	scene_is_empty(char *file)
{
	int is_empty = 1; // Assume it's empty until we find a non-empty line.

	FILE *file_ptr = fopen(file, "r");
	if (file_ptr == NULL)
		return is_empty;

	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	// Iterate through the file using get_next_line.
	while ((read = getline(&line, &len, file_ptr)) != -1)
	{
		int i = 0;
		while (i < read) {
			if (custom_isalnum(line[i]))
			{
                is_empty = 0; // Found an alphanumeric character, so it's not empty.
                break;
            }
            i++;
        }
        if (!is_empty)
		{
            free(line);
            fclose(file_ptr);
            return 0; // Not empty, return 0.
        }
    }

    free(line);
    fclose(file_ptr);
    return is_empty; // If the loop completes without finding alphanumeric characters, it's empty.
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
