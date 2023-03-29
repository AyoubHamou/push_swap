/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:43:35 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/29 01:49:15 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_swap(t_list **lst)
{
	int	tmp;

	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	tmp = (*lst)->n;
	(*lst)->n = (*lst)->next->n;
	(*lst)->next->n = tmp;
}

void	sa(t_list **lst, int print)
{
	lst_swap(lst);
	if (print)
		write(1, "sa\n", 3);
}
void	sb(t_list **lst, int print)
{
	lst_swap(lst);
	if (print)
		write(1, "sb\n", 3);
}
void	ss(t_list **a, t_list **b, int print)
{
	lst_swap(a);
	lst_swap(b);
	if (print)
		write(1, "ss\n", 3);
}
