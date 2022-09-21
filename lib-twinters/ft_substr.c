/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:32:36 by twinters          #+#    #+#             */
/*   Updated: 2022/04/23 17:44:58 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*nc_s;
	char			*new_s;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = start;
	nc_s = (char *)s;
	if (len > (unsigned)ft_strlen(s))
		len = ft_strlen(s);
	if ((unsigned int)ft_strlen(nc_s) < start)
		len = 0;
	else if (len + (unsigned)start > (unsigned)ft_strlen(s))
		len = (unsigned)ft_strlen(s) - start;
	new_s = malloc(sizeof(char) * (len + 1));
	if (!new_s)
		return (NULL);
	i = start;
	while ((i - start) < len && nc_s[i])
	{
		new_s[i - start] = nc_s[i];
		i++;
	}
	new_s[i - start] = '\0';
	return (new_s);
}
