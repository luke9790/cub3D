/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:01:32 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/13 13:49:09 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*ft_strchr(char const *s, int c);
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin_free_s1(char *s1, char *s2);
char	*ft_substr(char *str, unsigned int start, size_t size);
char	*get_next_line(int fd);

#endif
