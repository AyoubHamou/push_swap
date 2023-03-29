# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamou <ahamou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/28 21:45:38 by ahamou            #+#    #+#              #
#    Updated: 2023/03/29 06:07:00 by ahamou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

CFLAGS += -Wextra -Werror -Wall -I includes -I bonus #-fsanitize=address

SRCS = sources/push_swap.c utils/error_message.c utils/is_number.c utils/get_args.c\
		utils/lists.c utils/push_instructions.c utils/swap_instructions.c sources/is_sorted.c\
		utils/rotate_instructions.c utils/rev_rotate_instructions.c sources/sort_three.c \
		sources/sort_x.c sources/sort_ffive.c utils/parc_args.c\
		utils/check_doubles.c utils/get_rank.c

B_SRCS = bonus/checker.c utils/error_message.c utils/is_number.c utils/get_args.c\
		utils/lists.c utils/push_instructions.c utils/swap_instructions.c sources/is_sorted.c\
		utils/rotate_instructions.c utils/rev_rotate_instructions.c sources/sort_three.c sources/sort_ffive.c\
		utils/check_doubles.c utils/get_rank.c bonus/bonus_utils/get_next_line.c bonus/bonus_utils/get_next_line_utils.c\
		bonus/bonus_utils/ft_strncmp.c bonus/bonus_utils/ft_putstr.c\

LIBFT = libft/ft_strlen.c libft/ft_strjoin.c libft/ft_split.c libft/ft_substr.c libft/ft_strdup.c\
		libft/ft_calloc.c libft/ft_bzero.c libft/ft_memset.c libft/ft_atoi.c

OBJS = $(SRCS:.c=.o) $(LIBFT:.c=.o)

B_OBJS = $(B_SRCS:.c=.o) $(LIBFT:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		@cc $(CFLAGS) $(OBJS) -o $(NAME)

bonus : $(BONUS)

$(BONUS) : $(B_OBJS)
		@cc $(CFLAGS) $(B_OBJS) -o $(BONUS)

clean :
		rm -rf $(OBJS) $(B_OBJS)
		
fclean : clean
		rm -rf $(NAME) $(BONUS)

re : fclean all