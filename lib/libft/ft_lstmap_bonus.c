/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:41:26 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/16 13:23:34 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;

	new_lst = NULL;
	if (!f || !del)
		return (NULL);
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&new_lst, del);
			while (lst)
			{
				del(lst->content);
				lst = lst->next;
			}
			return (NULL);
		}
		ft_lstadd_back(&new_lst, tmp);
		lst = lst->next;
	}
	return (new_lst);
}
