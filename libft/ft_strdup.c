/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:03:00 by twinters          #+#    #+#             */
/*   Updated: 2022/04/22 08:43:14 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		size_s;

	size_s = ft_strlen(s) + 1;
	dup = malloc(sizeof(char) * size_s);
	if (!dup)
		return (NULL);
	ft_memmove(dup, s, size_s);
	return (dup);
}
