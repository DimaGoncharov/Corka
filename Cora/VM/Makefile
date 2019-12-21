# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptorchbu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/21 17:46:23 by ptorchbu          #+#    #+#              #
#    Updated: 2019/12/21 17:46:27 by ptorchbu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../corewar

FLAGS = -Wall -Werror -Wextra

SRC = main.c
SRC += error_core.c
SRC += checker.c
SRC += create_champ.c
SRC += ft_print_memory.c
SRC += memory.c
SRC += hextoa.c
SRC += get_cont.c
SRC += hextoi.c
SRC += init_map.c
SRC += starting.c
SRC += aff.c
SRC += fork.c
SRC += process_next.c
SRC += cmd_ld.c
SRC += cmd_lfork.c
SRC += cat_bit.c
SRC += cmd_ldi.c
SRC += cmd_st.c
SRC += cmd_add.c
SRC += cmd_sub.c
SRC += jmp.c
SRC += get_type.c
SRC += cmd_lld.c
SRC += get_cmd_size.c
SRC += lldi.c
SRC += cmd_and.c
SRC += cmd_or.c
SRC += cmd_xor.c
SRC += argval_get.c
SRC += name_of_reg.c
SRC += isdir.c
SRC += isind.c
SRC += isreg.c
SRC += sticmd.c
SRC += live.c
SRC += iscmd.c
SRC += dead_proc_exec.c
SRC += add_dir_reg.c
SRC += verbose.c
SRC += setup_ncurses.c
SRC += ncurs_end.c
SRC += print_map.c
SRC += next.c
SRC += verbs2.c
SRC += prog_lp.c
SRC += err_manage.c
SRC += bytes_rev.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) ../libftprintf/libft.a -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
