/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:47:05 by estettle          #+#    #+#             */
/*   Updated: 2024/10/11 11:47:05 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_item;

	if (!lst)
		return ;
	while (*lst)
	{
		next_item = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_item;
	}
	free(*lst);
	*lst = NULL;
}
