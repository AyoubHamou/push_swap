/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ffive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:47:55 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/29 01:50:46 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_forth(t_list **a, t_list **b)
{
	int small;
	int index = 0;
	t_list *curr = *a;

	small = (*a)->n;
	while (curr->next)
	{
		curr = curr->next;
		if (small > curr->n)
			small = curr->n;
	}
	curr = *a;
	while (curr)
	{
		if (curr->n == small)
			break;
		curr = curr->next;
		index++;
	}
	while ((*a)->n != small)
	{
		if (index >= 2)
			rra(a, 1);
		else
			ra(a, 1);
	}
	pb(a, b, 1);
	sort_three(a);
	pa(a, b, 1);
}

void	sort_five(t_list **a, t_list **b)
{
	int small;
	int index = 0;
	t_list *curr = *a;

	small = (*a)->n;
	while (curr->next)
	{
		curr = curr->next;
		if (small > curr->n)
			small = curr->n;
	}
	curr = *a;
	while (curr)
	{
		if (curr->n == small)
			break;
		curr = curr->next;
		index++;
	}
	while ((*a)->n != small)
	{
		if (index >= 2)
			rra(a, 1);
		else
			ra(a, 1);
	}
	pb(a, b, 1);
	sort_forth(a, b);
	pa(a, b, 1);
}