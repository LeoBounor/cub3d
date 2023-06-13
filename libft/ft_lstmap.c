/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:24:27 by vducoulo          #+#    #+#             */
/*   Updated: 2021/11/16 16:59:35 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*dest;

	dest = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp->content)
			ft_lstdelone(tmp, del);
		lst = lst->next;
		ft_lstadd_back(&dest, tmp);
	}
	return (dest);
}
