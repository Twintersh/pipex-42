/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:10:28 by twinters          #+#    #+#             */
/*   Updated: 2022/04/23 17:35:58 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		union_len;
	char	*join;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	union_len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * union_len + 1);
	if (!join)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		join[i] = s1[i];
		i++;
	}	
	while (i - ft_strlen(s1) < ft_strlen(s2))
	{
		join[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	join[i] = 0;
	return (join);
}
