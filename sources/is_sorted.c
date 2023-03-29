/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:48:36 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/29 05:57:54 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **a)
{
	t_list	*curr;

	curr = *a;
	while (curr->next)
	{
		if (curr->n > curr->next->n)
			return (1);
		curr = curr->next;
	}
	return (0);
}
