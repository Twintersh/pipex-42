/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:30:46 by twinters          #+#    #+#             */
/*   Updated: 2022/04/22 21:37:55 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	size;
	int	lstlen;

	size = 0;
	lstlen = ft_lstsize(lst);
	while (size < lstlen - 1)
	{
		size++;
		lst = lst->next;
	}
	return (lst);
}
