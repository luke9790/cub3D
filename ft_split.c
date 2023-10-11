/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:11:00 by pcocci            #+#    #+#             */
/*   Updated: 2023/10/11 14:27:19 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_substr2(char *str, unsigned int start, size_t size)
{
	size_t	len;
	char	*sub;

	len = ft_strlen (str);
	if (start >= len)
		len = 0;
	if (len - start < size)
		size = len - start;
	sub = malloc (sizeof (*sub) * (size + 1));
	if (!sub)
		return (NULL);
	sub[size] = '\0';
	while (size--)
		sub[size] = str[start + size];
	return (sub);
}

static int	words_counter(char const *s, char c)
{
	int	words;
	int	flag;
	int	i;

	words = 0;
	flag = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			words++;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (words);
}

static int	letters_in_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		word;
	char	**str;

	if (!s)
		return (NULL);
	i = 0;
	j = -1;
	word = words_counter(s, c);
	str = malloc((word + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		str[j] = ft_substr2((char *)s, i, letters_in_word(s, c, i));
		if (!str)
			return (NULL);
		i += letters_in_word(s, c, i);
	}
	str[j] = NULL;
	return (str);
}
