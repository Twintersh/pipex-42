/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:41:03 by twinters          #+#    #+#             */
/*   Updated: 2022/05/31 13:01:26 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoingnl(char *s2, char *s1)
{
	int		union_len;
	char	*new_str;
	int		i;

	if (!s1)
		return (NULL);
	i = 0;
	union_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = ft_calloc(union_len + 1, sizeof(char));
	while (s2[i])
	{
		new_str[i] = s2[i];
		i++;
	}
	while (s1[i - ft_strlen(s2)])
	{
		new_str[i] = s1[i - ft_strlen(s2)];
		i++;
	}
	ft_free(s2);
	return (new_str);
}

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	istherebackn(const char *str, int z)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	if (!z)
		return (0);
	return (i);
}

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
