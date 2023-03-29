/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 23:51:49 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/29 02:07:27 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_instruction(char *line, t_list **a, t_list **b)
{
	if (!ft_strncmp(line, "pa\n", 3))
		pa(a, b, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(a, b, 0);
	else if (!ft_strncmp(line, "sa\n", 3))
		sa(a, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(b, 0);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(a, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(b, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(a, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(b, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b, 0);
	else
		error_message();
}

int main(int ac, char **av)
{
	int i;
    char *line;

	i = 0;

	if (ac < 2)
		return (0);
	char **args = get_args(av);
	while (args[i])
	{
		is_number(args[i]);
		i++;
	}
	i = 0;
	t_list **a = malloc(sizeof(t_list *));
	*a = NULL;
	t_list *node;
	while (args[i])
	{
		node = ft_newnode(args[i]);
		ft_addback(a, node);
		i++;
	}
	check_doubles(a);
	if (!is_sorted(a))
		return (0);
	t_list *b;
	b = NULL;
    while(1)
    {
        line = get_next_line(0);
		if (!line)
			break ;
		check_instruction(line, a, &b);
		free(line);
    }
	if (!is_sorted(a) && b == NULL)
		ft_putstr("\033[1;32mOK\033[0m\n");
	else
		ft_putstr("\033[1;31mKO\n\033[0m\n");
}