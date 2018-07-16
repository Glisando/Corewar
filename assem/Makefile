# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgres <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 12:56:36 by bgres             #+#    #+#              #
#    Updated: 2018/02/20 12:56:40 by bgres            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRC = asm.c pars_two.c to_code.c p1.c p2.c p3.c p4.c p5.c p6.c p7.c p10.c p11.c p12.c p13.c p14.c

OBJ = $(SRC:.c=.o)

MAKELIB = make -C libftprintf/

HEADER = asm.h

LIBPATH = libftprintf/libftprintf.a

SFLAG = -c  -O3 -Os -Wall -Wextra -Werror
.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re

all: $(NAME)

$(NAME): $(LIBPATH) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIBPATH) 

$(LIBPATH): 
	make -C libftprintf/

%.o: %.c $(HEADER)
	gcc $(SFLAG)  $< -o $@ 

clean: 
	rm -f $(OBJ)
	make -C libftprintf/ clean

fclean: clean
	rm -f $(NAME)
	make -C libftprintf/ fclean

re: fclean all
