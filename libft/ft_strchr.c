/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:18:15 by twinters          #+#    #+#             */
/*   Updated: 2022/04/04 13:20:23 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	if (!c)
	{
		while (*tmp)
			tmp++;
		return (tmp);
	}
	while (*tmp)
	{
		if (*tmp == (char)c)
			return (tmp);
		tmp++;
	}	
	return (NULL);
}
