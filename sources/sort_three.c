/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:47:11 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/29 01:51:11 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **lst)
{
	if ((*lst)->n > (*lst)->next->n && (*lst)->n < (*lst)->next->next->n)
		sa(lst, 1);
	else if ((*lst)->n < (*lst)->next->n && (*lst)->n > (*lst)->next->next->n)
		rra(lst, 1);
	else if ((*lst)->n < (*lst)->next->n && (*lst)->next->n > (*lst)->next->next->n)
	{
		sa(lst, 1);
		ra(lst, 1);
	}
	else if ((*lst)->n > (*lst)->next->n && (*lst)->next->n < (*lst)->next->next->n)
		ra(lst, 1);
	else if ((*lst)->n > (*lst)->next->n && (*lst)->next->n > (*lst)->next->next->n)
	{
		sa(lst, 1);
		rra(lst, 1);
	}
}