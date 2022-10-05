/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:13:02 by twinters          #+#    #+#             */
/*   Updated: 2022/06/27 19:33:22 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!little[0])
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while (j + i < len && little[j] == big[i + j])
		{
			j++;
			if (!little[j])
				return ((char *) big + i);
		}
		i++;
	}
	return (NULL);
}
