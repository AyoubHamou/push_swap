/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:05:10 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/29 06:55:17 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parc_args(t_list **a, char **av)
{
	char 	**args;
	t_list	*node;
	int 	i;

	args = get_args(av);
	i = 1;
	while (args[i])
	{
		is_number(args[i]);
		i++;
	}
	i = 0;
	a = malloc(sizeof(t_list *));
	*a = NULL;
	while (args[i])
	{
		node = ft_newnode(args[i]);
		ft_addback(a, node);
		i++;
	}
	check_doubles(a);
}