/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 23:58:06 by ahamou            #+#    #+#             */
/*   Updated: 2023/03/29 02:03:50 by ahamou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	line_exist(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*return_line(char **s)
{
	int		i;
	char	*line;
	char	*tmp;

	i = line_exist(*s);
	if (i < 0)
	{
		line = ft_substrs(*s, 0, ft_strlen(*s) - 1);
		free(*s);
		*s = NULL;
		return (line);
	}
	line = ft_substrs(*s, 0, i);
	tmp = ft_substrs(*s, i + 1, ft_strlen(*s) - 1);
	free (*s);
	*s = tmp;
	return (line);
}

char	*ft_free(char *copy, char **str)
{
	if (*str)
	{
		free (*str);
		*str = NULL;
	}
	free (copy);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			*copy;
	static char		*str;
	ssize_t			n;

	if (fd < 0)
		return (NULL);
	copy = malloc (sizeof(char) * 2);
	if (!copy)
		return (NULL);
	n = 1337;
	while (line_exist(str) == -1 && n > 0)
	{
		n = read(fd, copy, 1);
		if (n < 0)
			return (ft_free(copy, &str));
		copy[n] = '\0';
		str = ft_strjoins(str, copy);
		if (!str)
			return (ft_free(copy, &str));
		if (!str[0])
			return (ft_free(copy, &str));
	}
	free (copy);
	return (return_line(&str));
}