/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:49:32 by twinters          #+#    #+#             */
/*   Updated: 2022/04/04 12:35:09 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*buff;
	char	*tmp;

	tmp = (char *)s;
	buff = 0;
	if (!c)
	{
		while (*tmp)
			tmp++;
		return (tmp);
	}
	while (*tmp)
	{
		if (*tmp == (char)c)
			buff = tmp;
		tmp++;
	}
	return (buff);
}
