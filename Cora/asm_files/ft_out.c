

#include "asm.h"

int		ft_out(t_data *data, char *str)
{
	(void)data;
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
	return (0);
}
