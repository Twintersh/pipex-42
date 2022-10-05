/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:02:59 by twinters          #+#    #+#             */
/*   Updated: 2022/04/23 17:42:56 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*new_lst;
	t_list	*new_element;

	current = lst;
	new_lst = NULL;
	while (current)
	{
		new_element = ft_lstnew((*f)((void *)current->content));
		if (!new_element)
			ft_lstclear(&new_lst, del);
		ft_lstadd_back(&new_lst, new_element);
		current = current->next;
	}
	return (new_lst);
}
