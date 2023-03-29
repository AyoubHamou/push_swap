/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:23:59 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/29 05:56:42 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*dest;

	if (!s)
		return (0);
	j = ft_strlen(s);
	i = 0;
	k = start;
	if (start >= j)
		return (ft_strdup(""));
	while (i < len && k++ < j)
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	i = 0;
	while (s[start] && i < len)
	{
		dest[i++] = s[start++];
	}
	dest[i] = '\0';
	return (dest);
}
