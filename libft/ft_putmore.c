/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmore.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:54:52 by twinters          #+#    #+#             */
/*   Updated: 2022/05/31 13:04:06 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putpointer(unsigned long int nb)
{
	int	j;

	j = 0;
	if (nb == 0)
	{
		j += write(1, "(nil)", 5);
		return (j);
	}
	j += write(1, "0x", 2);
	j += ft_putphexa(nb);
	return (j);
}

int	ft_putphexa(unsigned long int nb)
{
	char	*base;
	int		j;

	j = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		j += ft_putphexa(nb / 16);
		nb %= 16;
	}
	if (nb < 16)
		j += ft_putchar(base[nb]);
	return (j);
}
