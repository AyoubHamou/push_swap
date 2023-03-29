/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:09:52 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/29 07:12:04 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void hasValue(char *str)
{
	int i = 0;
	int v = 0;
	if (!str[i])
		error_message();
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			v = 1;
		i++;
	}
	if (!v)
		error_message();
}

char	**get_args(char **str)
{
	char	*tmp;
	int		i;

	if (!str[1][0])
		error_message();
	tmp = ft_strdup(str[1]);
	i = 2;
	while (str[i])
	{
		hasValue(str[i]);
		char *ptr = tmp;
		tmp = ft_strjoin(tmp, str[i]);
		free(ptr);
		i++;
	}
	str = ft_split(tmp, ' ');
	free(tmp);
	return (str);
}