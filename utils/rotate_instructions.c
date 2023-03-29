/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:44:40 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/29 01:48:37 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_rotate(t_list **lst)
{
	t_list	*curr;

	if (!lst|| !(*lst)->next)
		return ;
	curr  = *lst;
	while(curr->next)
		curr = curr->next;
	curr->next = *lst;
	*lst = (*lst)->next;
	curr->next->next = NULL;
}

void	ra(t_list **a, int print)
{
	lst_rotate(a);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_list **b, int print)
{
	lst_rotate(b);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, int print)
{
	lst_rotate(a);
	lst_rotate(b);
	if (print)
		write(1, "rr\n", 3);
}
