
#include "asm.h"

int		ft_label_char(int c)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(LABEL_CHARS);
	while (i <= j && c != LABEL_CHARS[i])
		i++;
	if (i < j)
		return (1);
	else
		return (0);
}
