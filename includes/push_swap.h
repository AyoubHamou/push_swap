/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:09:00 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/29 06:05:58 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				n;
	int				rank;
	struct s_list	*next;
}	t_list;

//============sources=============//
int		is_sorted(t_list **a);
void	sort_three(t_list **lst);
void	sort_forth(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b);
void	sort_all(t_list **a, t_list **b);

//============utils=============//
void	error_message(void);
void	parc_args(t_list **a, char **av);
void	is_number(char *str);
char	**get_args(char **str);
void	check_doubles(t_list **a);
t_list	*ft_newnode(char *str);
t_list	*ft_lastnode(t_list *lst);
void	ft_addback(t_list **lst, t_list *node);
int		ft_lstsize(t_list *lst);
void	pa(t_list **a, t_list **b, int print);
void	pb(t_list **a, t_list **b, int print);
void	sa(t_list **lst, int print);
void	sb(t_list **lst, int print);
void	ss(t_list **a, t_list **b, int print);
void	ra(t_list **a, int print);
void	rb(t_list **b, int print);
void	rr(t_list **a, t_list **b, int print);
void	rra(t_list **a, int print);
void	rrb(t_list **b, int print);
void	rrr(t_list **a, t_list **b, int print);
int		*set_array(t_list **a, int size);
int		*sort_array(int *arr, int size);
void	sort_list(t_list **a, int *arr, int size);
void	set_rank(t_list **a);

//============libft=============//
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char	*s);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void	*b, int c, size_t len);
int		ft_atoi(char *str);

#endif