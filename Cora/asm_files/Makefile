

NAME = ../asm

FLAGS = -Wall -Werror -Wextra 

SRC = main.c
SRC += op.c
SRC += head_file.c
SRC += initializer.c
SRC += changer.c
SRC += ft_comm.c
SRC += recovery.c
SRC += ft_manag_head.c
SRC += ft_manag_name.c
SRC += ft_manag_comm.c
SRC += ft_out.c
SRC += free_all_data.c
SRC += recovery_instruc.c
SRC += noleaks.c
SRC += check_arg.c
SRC += check_type.c
SRC += which_arg.c
SRC += trad.c
SRC += trad_reg_ind.c
SRC += ft_label_char.c
SRC += common.c
SRC += ft_manag_lab.c
SRC += label.c
SRC += label_1.c
SRC += final_trad.c
SRC += create_file.c
SRC += initializer1.c
SRC += recovery_label.c
SRC += define_arg.c
SRC += trad_dir.c
SRC += label_2.c
SRC += ft_hextoi.c
SRC += reverse_hexdump.c
SRC += add_f.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) ../libftprintf/libft.a

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $< -Iincludes

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
