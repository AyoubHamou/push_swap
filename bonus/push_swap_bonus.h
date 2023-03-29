/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:55:19 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/29 02:04:20 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define    PUSH_SWAP_BONUS_H

#include "push_swap.h"

//============bonus_utils=============//
char	*get_next_line(int fd);
char	*ft_substrs(char *s, size_t start, size_t end);
char	*ft_strjoins(char *s1, char *s2);
int     ft_strncmp(const char *str1, const char *str2, size_t n);
void    ft_putstr(char *str);

#endif