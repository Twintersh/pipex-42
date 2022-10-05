/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:02:18 by twinters          #+#    #+#             */
/*   Updated: 2022/05/31 13:03:33 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_args(va_list lst, const char *str, int i)
{
	int	j;

	j = 0;
	i++;
	if (str[i] == 'd' || str[i] == 'i')
		j += ft_putnbr(va_arg(lst, int));
	else if (str[i] == 'c')
		j += ft_putchar(va_arg(lst, int));
	else if (str[i] == 's')
		j += ft_putstr(va_arg(lst, char *));
	else if (str[i] == 'x')
		j += ft_puthexa(va_arg(lst, int), 0);
	else if (str[i] == 'X')
		j += ft_puthexa(va_arg(lst, int), 16);
	else if (str[i] == '%')
		j += ft_putchar('%');
	else if (str[i] == 'u')
		j += ft_putunbr(va_arg(lst, unsigned int));
	else if (str[i] == 'p')
		j += ft_putpointer(va_arg(lst, unsigned long int));
	return (j);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		i;
	int		j;

	va_start(lst, str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
			j += ft_print_args(lst, str, i++);
		else
			j += ft_putchar(str[i]);
		i++;
	}
	va_end(lst);
	return (j);
}
