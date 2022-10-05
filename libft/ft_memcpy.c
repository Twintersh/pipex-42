/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:55:13 by twinters          #+#    #+#             */
/*   Updated: 2022/04/23 17:33:36 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tmp_src;
	char	*tmp_dest;

	if (!dest && !src)
		return (NULL);
	tmp_dest = dest;
	tmp_src = (char *)src;
	while (n--)
		*tmp_dest++ = *tmp_src++;
	return (dest);
}
