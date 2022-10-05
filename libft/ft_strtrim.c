/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:48:18 by twinters          #+#    #+#             */
/*   Updated: 2022/04/22 12:07:00 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	set_verif(const char *set, char c)
{
	int	i;

	i = 0;
	if ((char)set[i] == c)
		return (1);
	while ((char)set[i] != c && set[i])
	{
		i++;
		if ((char)set[i] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	left;
	int	right;

	if (!s1 || !set)
		return (NULL);
	right = ft_strlen(s1);
	left = 0;
	while (set_verif(set, s1[left]))
		left++;
	while (set_verif(set, s1[right - 1]))
		right--;
	return (ft_substr(s1, left, right - left));
}
