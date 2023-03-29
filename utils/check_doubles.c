/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doubles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:55:49 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/16 00:06:42 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_doubles(t_list **a)
{
	t_list *curr;
	t_list *ptr;
	
	curr = *a;
	while (curr)
	{
		ptr = curr->next;
		while (ptr)
		{
			if (curr->n == ptr->n)
				error_message();
			ptr = ptr->next;
		}
		curr = curr->next;
	}
}