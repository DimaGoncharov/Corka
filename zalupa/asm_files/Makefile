# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/21 17:39:09 by ptorchbu          #+#    #+#              #
#    Updated: 2019/12/21 17:39:15 by ptorchbu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../asm

FLAGS = -Wall -Werror -Wextra 

SRC = main.c
SRC += op.c
SRC += head_file.c
SRC += initializer.c
SRC += changer.c
SRC += ft_comm.c
SRC += vosstanovilka.c
SRC += ft_manag_head.c
SRC += ft_manag_name.c
SRC += ft_manag_comm.c
SRC += ft_out.c
SRC += clean_all.c
SRC += rec_instruct.c
SRC += leak_off.c
SRC += args_checkus.c
SRC += check_type.c
SRC += choose_args.c
SRC += trade.c
SRC += trans_reg.c
SRC += ft_label_char.c
SRC += general.c
SRC += ft_manag_lab.c
SRC += label.c
SRC += label_1.c
SRC += ultimate_trans.c
SRC += create_file.c
SRC += initializer1.c
SRC += rec_lab.c
SRC += determ_arg.c
SRC += transdir.c
SRC += label_2.c
SRC += hexta.c
SRC += hexta_reverse.c
SRC += func_add.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) ../libft/libft.a

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $< -Iincludes

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
