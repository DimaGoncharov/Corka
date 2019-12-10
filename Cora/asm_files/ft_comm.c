

#include "asm.h"

int		ft_comm(int c)
{
	return (c == '#' || c == ';' ? 1 : 0);
}
