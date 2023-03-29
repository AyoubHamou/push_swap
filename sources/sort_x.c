/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:49:54 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/29 06:36:42 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_index(t_list **a)
{
	int index;
	t_list *curr;
	int *arr;

	index = 0;
	curr = *a;
	arr = malloc(ft_lstsize(*a) * sizeof(int));
	for (int i = 0; i < ft_lstsize(*a); i++)
	{
		arr[i] = curr->n;
		curr = curr->next;
	}
	for (int i = 0; i < ft_lstsize(*a); i++)
	{
		for (int j = i + 1; j < ft_lstsize(*a); j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	curr = *a;
	for (int i = 0; i < ft_lstsize(*a); i++)
	{
		while (curr != NULL)
		{
			if (curr->n == arr[i])
			{
				curr->rank = i;
				break;
			}
			curr = curr->next;
		}
		curr = *a;
	}
}

int get_index(t_list **a, int start, int end)
{
	t_list *curr;
	int i;

	i = 0;
	curr = *a;
	while (curr)
	{
		if (curr->rank >= start && curr->rank <= end)
			return (i);
		curr = curr->next;
		i++;
	}
	return (-1);
}

void push_to_b(t_list **a, t_list **b, int start, int end)
{
	int index;
	int size;

	index = get_index(a, start, end);
	size = ft_lstsize(*a);
	while (*a && index != -1)
	{
		if ((*a)->rank >= start && (*a)->rank <= end)
		{
			pb(a, b, 1);
			size = ft_lstsize(*a);
			index = get_index(a, start, end);
			if ((*a && !((*a)->rank >= start && (*a)->rank <= end) && ((*b)->rank <= (start + end) / 2)))
				rr(a, b, 1);
			else if ((*b)->rank <= (start + end) / 2)
				rb(b, 1);
		}
		else if (*a && index >= size / 2)
			rra(a, 1);
		else
			ra(a, 1);
	}
}

void push_max(t_list **a, t_list **b, int size)
{
	while (*b)
	{
		if ((*b)->rank == size - 1)
		{
			pa(a, b, 1);
			return;
		}
		else
			rb(b, 1);
	}
}

void push_back_to_a(t_list **a, t_list **b, int size)
{
	t_list *last_a;
	push_max(a, b, size);
	int numbers = size;
	size--;
	while (*b || is_sorted(a))
	{
		last_a = ft_lastnode(*a);
		if ((last_a->rank + 1) == (*a)->rank)
		{
			rra(a, 1);
		}
		else if (*b && ((*b)->rank + 1) == (*a)->rank)
		{
			pa(a, b, 1);
			size--;
		}
		else if (*b && (last_a->rank == numbers - 1 || last_a->rank < (*b)->rank))
		{
			pa(a, b, 1);
			size--;
			ra(a, 1);
		}
		else if (*b && get_index(b, ((*a)->rank - 1), ((*a)->rank - 1)) >= size / 2)
			rrb(b, 1);
		else if (*b && get_index(b, ((*a)->rank - 1), ((*a)->rank - 1)) < size / 2)
			rb(b, 1);
	}
}

void sort_all(t_list **a, t_list **b)
{
	int size;
	int i;

	size = ft_lstsize(*a);
	i = 25;
	while (*a)
	{
		push_to_b(a, b, (size / 2) - i, (size / 2) + i);
		i += 25;
	}
	push_back_to_a(a, b, size);
}