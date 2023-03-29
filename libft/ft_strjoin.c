/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:11:44 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/29 05:56:36 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*a;

	i = 0;
	j = 0;
	a = malloc (ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!a)
		return (NULL);
	while (s1[i])
	{
		a[i] = s1[i];
		i++;
	}
	a[i++] = ' ';
	while (s2[j])
	{
		a[i + j] = s2[j];
		j++;
	}
	a[i + j] = '\0';
	return (a);
}
