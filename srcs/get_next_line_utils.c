/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 10:49:26 by flee              #+#    #+#             */
/*   Updated: 2021/07/20 17:23:49 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_gnl(const char *str, size_t state)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (state == 0)
	{
		if (str == NULL)
			return (0);
		while (str[i] != '\0')
			i++;
	}
	if (state == 1)
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
	}
	return (i);
}

size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	size_t	index;

	destlen = 0;
	srclen = ft_strlen_gnl(src, 0);
	index = 0;
	while (dst[destlen] && destlen < size)
		destlen++;
	while ((src[index]) && ((destlen + index + 1) < size))
	{
		dst[destlen + index] = src[index];
		index++;
	}
	if (destlen != size)
		dst[destlen + index] = '\0';
	return (destlen + srclen);
}

char	*ft_strjoin_gnl(char *s1, char const *s2, size_t read_return)
{
	size_t		cmpt1;
	size_t		cmpt2;
	char	*str;

	if (s2)
	{
		cmpt1 = ft_strlen_gnl((char *)s1, 0);
		cmpt2 = cmpt1 + read_return;
		str = (char *)malloc(sizeof(char) * (cmpt2 + 1));
		if (!str)
			return (NULL);
		ft_strlcpy_gnl(str, (char *)s1, cmpt1 + 1);
		ft_strlcat_gnl(str, (char *)s2, cmpt2 + 1);
		free(s1);
		return (str);
	}
	return (NULL);
}

size_t	ft_strlcpy_gnl(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	if (src)
	{
		while (src[src_len])
			src_len++;
		if (size > 0)
		{
			while (src[i] && (i < (size - 1)))
			{
				dest[i] = src[i];
				i++;
			}
		}
	}
	dest[i] = '\0';
	return (src_len);
}

char	*ft_substr_gnl(char *s, size_t start, size_t len, size_t state)
{
	char	*tab;
	size_t		len1;
	size_t		len2;
	size_t		i;

	i = -1;
	tab = NULL;
	if (s)
	{
		len1 = (size_t)ft_strlen_gnl((char *)s, 0);
		len2 = len;
		if ((size_t)start > len1)
			len2 = 0;
		else if ((size_t)start + len2 > len1)
			len2 = len1 - (size_t)start;
		tab = (char *) malloc(sizeof(char) * (len2 + 1));
		if (!tab)
			return (NULL);
		while (++i < len2)
			tab[i] = s[start + i];
		tab[i] = '\0';
		if (state == 1)
			free(s);
	}
	return (tab);
}