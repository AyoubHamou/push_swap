/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:45:57 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/29 01:47:58 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_rev_rotate(t_list **lst)
{
	t_list	*b_last;

	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	b_last  = *lst;
	while(b_last->next->next)
		b_last = b_last->next;
	b_last->next->next = *lst;
	*lst = b_last->next;
	b_last->next = NULL;
}

void	rra(t_list **a, int print)
{
	lst_rev_rotate(a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, int print)
{
	lst_rev_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, int print)
{
	lst_rev_rotate(a);
	lst_rev_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
}
