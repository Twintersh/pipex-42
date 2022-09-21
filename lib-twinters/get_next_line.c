/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:15:55 by twinters          #+#    #+#             */
/*   Updated: 2022/05/31 13:01:12 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join(char *str, int fd)
{
	char	*buff;
	int		rd;

	rd = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	buff[BUFFER_SIZE] = '\0';
	while (rd && !istherebackn(str, 0))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd < 0)
			return (free(buff), NULL);
		buff[rd] = '\0';
		if (rd == 0 && str[0] == '\0')
			return (free(str), free(buff), NULL);
		str = ft_strjoingnl(str, buff);
	}
	free(buff);
	return (str);
}	

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*str;
	char		*line;
	int			len;
	int			backn_z;

	if (!stash[fd])
		stash[fd] = ft_calloc(1, sizeof(char));
	if (fd < 0 || BUFFER_SIZE < 1 || !stash[fd] || read(fd, stash[fd], 0) < 0)
		return (NULL);
	str = join(stash[fd], fd);
	len = ft_strlen(str);
	backn_z = istherebackn(str, 1);
	line = ft_substr(str, 0, backn_z);
	stash[fd] = ft_substr(str, backn_z, backn_z - len);
	free(str);
	return (line);
}

void	ft_free(void *tab)
{
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void				*ptr;
	unsigned long int	a;
	unsigned char		*tmp;

	a = nmemb * size;
	if (nmemb >= 65535 || size >= 65535)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	ptr = malloc(a);
	if (!ptr)
		return (NULL);
	if (ptr)
	{
		tmp = (unsigned char *)ptr;
		while (a--)
			*tmp++ = 0;
	}
	return (ptr);
}
