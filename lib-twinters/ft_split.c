/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:45:16 by twinters          #+#    #+#             */
/*   Updated: 2022/04/23 17:37:40 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbwords(char *s, char c)
{
	int	nbmots;
	int	i;

	i = 0;
	nbmots = 0;
	while (s[i])
	{
		if (s[i] != c && ((i == 0 && s[i] != c) || (i > 0 && s[i - 1] == c)))
			nbmots++;
		i++;
	}
	return (nbmots);
}

static char	**get_words(char **splited, char *s, char c, int i)
{
	unsigned int	nbletters;
	int				nbwords;

	nbwords = -1;
	nbletters = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (s[i] != c && ((i == 0 && s[i] != c)
					|| (i > 0 && s[i - 1] == c)))
				nbwords++;
			nbletters = 0;
			while (s[i] != c && s[i])
			{
				nbletters++;
				i++;
			}
			splited[nbwords] = ft_calloc((nbletters + 1), sizeof(char));
		}
		if (!s[i])
			return (splited);
		i++;
	}
	return (splited);
}

static char	**set_words(char **splited, char *s, char c, int i)
{
	unsigned int	nbletters;
	int				nbwords;

	nbwords = -1;
	nbletters = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (s[i] != c && ((i == 0 && s[i] != c)
					|| (i > 0 && s[i - 1] == c)))
				nbwords++;
			nbletters = 0;
			while (s[i] != c && s[i])
			{
				splited[nbwords][nbletters] = s[i];
				nbletters++;
				i++;
			}
		}
		if (!s[i])
			return (splited);
		i++;
	}
	return (splited);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;
	int		s_words;

	if (!s)
		return (NULL);
	s_words = nbwords((char *)s, c);
	splited = ft_calloc((s_words + 1), sizeof(char *));
	if (!splited)
		return (NULL);
	splited[s_words] = NULL;
	splited = get_words(splited, (char *)s, c, 0);
	if (!splited)
		return (NULL);
	splited = set_words(splited, (char *)s, c, 0);
	return (splited);
}
