/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putthings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:28:26 by twinters          #+#    #+#             */
/*   Updated: 2022/05/31 13:03:49 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	int	j;

	j = 0;
	j += write(1, &c, 1);
	return (j);
}

int	ft_putnbr(int nb)
{
	int	j;

	j = 0;
	if (nb == -2147483648)
		j += write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			j += ft_putchar('-');
			nb *= -1;
		}
		if (nb >= 10)
		{
			j += ft_putnbr(nb / 10);
			nb %= 10;
		}
		if (nb < 10)
		{
			j += ft_putchar(nb + '0');
		}
	}
	return (j);
}

int	ft_putunbr(unsigned int nb)
{
	int	j;

	j = 0;
	if (nb >= 10)
	{
		j += ft_putnbr(nb / 10);
		nb %= 10;
	}
	if (nb < 10)
	{
		j += ft_putchar(nb + '0');
	}
	return (j);
}

int	ft_putstr(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!str)
	{
		j += write(1, "(null)", 6);
		return (j);
	}
	while (str[i] != '\0' )
	{
		j += write(1, &str[i], 1);
		i++;
	}
	return (j);
}

int	ft_puthexa(unsigned int nb, int maj)
{
	char	*base;
	int		j;

	j = 0;
	base = "0123456789abcdef0123456789ABCDEFGH";
	if (nb >= 16)
	{
		j += ft_puthexa(nb / 16, maj);
		nb %= 16;
	}
	if (nb < 16)
		j += ft_putchar(base[nb + maj]);
	return (j);
}
