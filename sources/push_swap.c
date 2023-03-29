/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:08:36 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/29 08:37:30 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**args;
	t_list	**a;
	t_list	*node;
	t_list	**b;
	int		i;

	i = 0;
	if (ac < 2)
		return (0);
	args = get_args(av);
	if (!args[i])
		error_message();
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
	b = malloc(sizeof(t_list *));
	*b = NULL;
	if (!is_sorted(a))
		return (0);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) == 4)
		sort_forth(a, b);
	else if (ft_lstsize(*a) == 5)
		sort_five(a, b);
	else
	{
		set_rank(a);
		sort_all(a, b);
	}
}
