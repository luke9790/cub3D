/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:54:28 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/13 15:01:09 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t ft_malloc_usable_size(void *ptr) {
    if (ptr == NULL) {
        return 0;
    }

    size_t *size_ptr = (size_t *)ptr - 1; // Assuming the size is stored just before the allocated block.
    return *size_ptr;
}

void *custom_realloc(void *ptr, size_t new_size)
{
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    
    if (ptr == NULL) {
        return malloc(new_size);
    }
    
    void *new_ptr = malloc(new_size);
    if (new_ptr == NULL) {
        return NULL;
    }

    size_t old_size = ft_malloc_usable_size(ptr);
    memcpy(new_ptr, ptr, (new_size < old_size) ? new_size : old_size);
    free(ptr);

    return new_ptr;
}


char **super_split(const char *str, const char *delimiters, int *count)
{
    char **tokens = NULL;
    int token_count = 0;
    
    char *str_copy = strdup(str);  // Make a copy of the input string to avoid modifying the original.
    char *token = strtok(str_copy, delimiters);
    
    while (token != NULL)
    {
        token_count++;
        tokens = (char **)custom_realloc(tokens, token_count * sizeof(char *));
        tokens[token_count - 1] = strdup(token);
        token = strtok(NULL, delimiters);
    }
    
    free(str_copy);  // Free the copied string.
    if (count != NULL)
        *count = token_count;
    
    return tokens;
}
