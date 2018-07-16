#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/05 10:43:55 by atlekbai          #+#    #+#              #
#    Updated: 2018/06/06 08:56:18 by atlekbai         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CW = corewar
ASM = asm

all:
	@make -C vm
	@make -C assem
	@cp vm/$(CW) $(CW)
	@cp assem/$(ASM) $(ASM)

clean:
	@make -C vm clean
	@make -C assem clean

fclean:
	@make -C vm fclean
	@make -C assem fclean
	@rm -f $(CW)
	@rm -f $(ASM)

re: 	fclean all