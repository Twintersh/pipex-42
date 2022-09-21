/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:37:24 by twinters          #+#    #+#             */
/*   Updated: 2022/04/23 17:38:21 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nblen(int n)
{
	int	i;

	i = -1;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (i++, n != 0)
		n /= 10;
	return (i);
}

char	*ft_itoa(int nl)
{
	long	n;
	char	*ns;
	int		nb_len;

	n = (long)nl;
	nb_len = nblen(n);
	ns = ft_calloc((nb_len + 1), sizeof(char));
	if (!ns)
		return (NULL);
	if (n == 0)
		ns[0] = '0';
	if (n < 0)
	{
		n *= -1;
		ns[0] = '-';
	}
	nb_len-- ;
	while (n != 0)
	{
		ns[nb_len--] = (n % 10) + '0';
		n /= 10;
	}
	return (ns);
}
