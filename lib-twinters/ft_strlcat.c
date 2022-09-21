/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:43:09 by twinters          #+#    #+#             */
/*   Updated: 2022/04/12 14:56:10 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*s;
	unsigned int	i;
	unsigned int	j;

	s = (char *)src;
	i = ft_strlen(dst);
	j = 0;
	if (size == 0 || i > size)
		return (size + ft_strlen(s));
	if (!*src)
		return (i);
	while (s[j] && i + j < size - 1)
	{
		dst[i + j] = s[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(s));
}
