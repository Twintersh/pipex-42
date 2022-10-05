/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:40:33 by twinters          #+#    #+#             */
/*   Updated: 2022/04/08 12:59:59 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp_src;
	char	*tmp_dest;

	tmp_dest = dest;
	tmp_src = (char *)src;
	if ((const void *) dest < src)
		while (n--)
			*tmp_dest++ = *tmp_src++;
	else if ((const void *) dest > src)
		while (n--)
			tmp_dest[n] = tmp_src[n];
	return (dest);
}
