/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:03:02 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/25 15:23:09 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_newnode(char *str)
{
	t_list *new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->n = ft_atoi(str);
	new->rank = 0;
	new->next = NULL;
	return (new);	
}

t_list *ft_lastnode(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_addback(t_list **lst, t_list *node)
{
	if (*lst)
		ft_lastnode(*lst)->next = node;
	else
		*lst = node;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while(lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

