/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:09:09 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/24 15:45:14 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *set_array(t_list **a, int size)
{
    t_list  *curr;
    int *arr;
    int i;

    arr = malloc(size * sizeof(int));
    curr = *a;
    i = 0;
    while(i < size)
    {
        arr[i] = curr->n;
		curr = curr->next;
        i++;
    }
    return (arr);
}


int *sort_array(int *arr, int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
            j++;
        }
        i++;
    }
    return (arr);
}

void    sort_list(t_list **a, int *arr, int size)
{
    t_list  *curr;
    int i;
    
    curr = *a;
    i = 0;
    while (i < size)
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
        i++;
    }
}

void    set_rank(t_list **a)
{
    int size;
    int *arr;
    int *arr1;

    size = ft_lstsize(*a);
	arr = set_array(a, size);
	arr1 = sort_array(arr, size);
	sort_list(a, arr, size);
}