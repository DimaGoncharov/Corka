

#include "asm.h"

void		inittmp2(t_tmp2 *tmp2)
{
	tmp2->trad = NULL;
	tmp2->to_trad = NULL;
}

void		inittmp1(t_tmp1 *tmp1)
{
	tmp1->tmp2 = NULL;
	tmp1->nw = NULL;
}

void		initsumary_args(t_sum_args *data)
{
	data->type = 0;
	data->sum = 0;
}

void		initdataline(t_data_line *dline, int index_line)
{
	ft_bzero(dline, sizeof(t_data_line));
	dline->label_called = ft_lstdblnew();
	dline->index = index_line;
}

void		initlab(t_lab *lab, t_data **data)
{
	ft_bzero(lab, sizeof(t_lab));
	if (lab == NULL)
	{
		ft_out(*data, "File malloc error\n");
		return ;
	}
}
