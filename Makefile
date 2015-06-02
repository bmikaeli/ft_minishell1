# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/09 09:51:36 by bmikaeli          #+#    #+#              #
#    Updated: 2014/01/10 15:12:41 by bmikaeli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_minishell1
GCCW =	cc -Wall -Wextra -Werror

SRC =	main.c \
		exec.c \
		env.c
OBJECT =	$(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECT)
	make -C libft/
	$(GCCW) -o $(NAME) $(LFLAGS) $(OBJECT) libft/libft.a

%.o: %.c
	$(GCCW) -c $^ $(IFLAGS) -o $@

clean:
	make clean -C libft/
	rm -f $(OBJECT)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all


