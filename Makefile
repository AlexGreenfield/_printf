# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 17:54:28 by acastrov          #+#    #+#              #
#    Updated: 2024/10/15 16:43:29 by acastrov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft.a

LIBFTDIR = ./libft

SRCS = ft_printf.c \
	libft_sub_ft.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Werror -Wextra -Wall

CC = cc

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFTDIR)/$(LIBFT)
	@cp $(LIBFTDIR)/$(LIBFT) $(NAME)
	@ar -rcs $(NAME) $(OBJS)

$(LIBFTDIR)/$(LIBFT):
	@make -C $(LIBFTDIR) CFLAGS="$(CFLAGS)"

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re
