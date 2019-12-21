# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/21 17:38:50 by ptorchbu          #+#    #+#              #
#    Updated: 2019/12/21 17:38:55 by ptorchbu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_COR = corewar
NAME_ASM = asm
ASM = asm_files/
COR = VM/
PRINTF = libftprintf/

all: cor asm

libft:
	make -C $(PRINTF) all
cor: libft
	make -C $(COR) all
asm: libft
	make -C $(ASM) all
	
clean:
	@make -C $(PRINTF) clean
	make -C $(COR) clean
	make -C $(ASM) clean

fclean: clean
	@make -C $(PRINTF) fclean
	rm -f $(NAME_COR)
	rm -f $(NAME_ASM)

re: fclean all

.PHONY: re clean fclean all asm cor
