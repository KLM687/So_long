/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:41:01 by flee              #+#    #+#             */
/*   Updated: 2021/06/10 18:23:27 by cesco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_strchr(const char *hay, int needle)
{
	unsigned int	i;

	i = 0;
	while (hay[i])
	{
		if (hay[i] == (char)needle)
			return ((char *)hay + i);
		i++;
	}
	if (hay[i] == (char)needle)
		return ((char *)hay + i);
	return (NULL);
}
