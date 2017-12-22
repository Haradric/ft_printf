#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbraslav <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 14:06:34 by mbraslav          #+#    #+#              #
#    Updated: 2017/02/01 14:06:36 by mbraslav         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SOURCE =	ft_printf.c\
			read_modifiers.c\
			read_modifiers2.c\
			read_arguments.c\
			read_arguments2.c\
			clean_description.c\
			useful_things.c\
			processing.c\
			processing_percent.c\
			processing_x.c\
			processing_s.c\
			processing_ls.c\
			processing_c.c\
			processing_o.c\
			processing_di.c\
			processing_u.c\
			processing_p.c\
			wchar.c

OBJECT = $(SOURCE:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECT)
	@echo "\033[34mcreating $(NAME)\033[39m"
	@ar rc $(NAME) $(OBJECT)
	@echo "\033[34madding libft objects to $(NAME)"
	ar r $(NAME) libft/*.o
	@echo "\033[34mgenerating index to $(NAME)\033[39m"
	@ranlib $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@make clean -C libft
	@echo "\033[34mremoving object files of libftprintf\033[39m"
	@rm -f $(OBJECT)

fclean:
	@make fclean -C libft
	@echo "\033[34mremoving object files of libftprintf\033[39m"
	@rm -f $(OBJECT)
	@echo "\033[34mremoving $(NAME)\033[39m"
	@rm -f $(NAME)

re: fclean all
