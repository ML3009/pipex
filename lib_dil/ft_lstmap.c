/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvautrot <mvautrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:42:57 by mvautrot          #+#    #+#             */
/*   Updated: 2023/01/02 12:11:03 by mvautrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void*(*f)(void *), void(*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;
	t_list	*ptr;

	if (!lst || !f || !del)
		return (NULL);
	tmp = NULL;
	while (lst)
	{
		ptr = f(lst->content);
		newlst = ft_lstnew(ptr);
		if (!newlst)
		{
			if (del)
				(*del)(newlst);
			ft_lstclear(&tmp, del);
			return (0);
		}
		lst = lst->next;
		ft_lstadd_back(&tmp, newlst);
	}
	return (tmp);
}
