/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:21:24 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/29 07:12:08 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_wc(char const *s, char c)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c || s[i] == '\t'))
			i++;
		if (s[i])
			k++;
		while (s[i] && s[i] != c && s[i] != '\t')
			i++;
	}
	return (k);
}

static void	*ft_free(char	**strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free (strs[i]);
		i++;
	}
	free (strs);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	strs = ft_calloc((ft_wc(s, c) + 1), sizeof(char *));
	if (!strs)
		return (NULL);
	while (s[i])
	{
		while (s[i] && (s[i] == c || s[i] == '\t'))
			i++;
		j = i;
		while (s[i] && s[i] != c && s[i] != '\t')
			i++;
		if (s[j])
		{
			strs[k] = ft_substr(s, j, i - j);
			if (!strs[k++])
				return (ft_free(strs));
		}
	}
	return (strs);
}
