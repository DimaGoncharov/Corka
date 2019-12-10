

#include "asm.h"

static void	mini_iscomment(int *i, int *j)
{
	*i += 1;
	*j = 0;
}

static void	comment_found(t_data *data, int *i, int *j, int *comment)
{
	*j += 8;
	*comment = ft_manag_comm(data, i, j);
	*j += 1;
}

static void	name_found(t_data *data, int *i, int *j, int *name)
{
	*j += 5;
	*name = ft_manag_name(data, i, j);
	*j += 1;
}

static void	error_manager(t_data *data, int comment, int name)
{
	if (comment == 1)
		ft_out(data, "Error after comment\n");
	else if (name == 1)
		ft_out(data, "Error after name\n");
	else
		ft_out(data, "Missing header\n");
}

int			ft_manag_head(t_data *data)
{
	int		i;
	int		j;
	int		comment;
	int		name;

	i = 0;
	j = 0;
	comment = 0;
	name = 0;
	while (i < data->nb_lines && (comment == 0 || name == 0))
	{
		if (ft_isspace(data->file[i][j]) != 0)
			j++;
		else if (ft_comm(data->file[i][j]) != 0 ||
			data->file[i][j] == '\0')
			mini_iscomment(&i, &j);
		else if (ft_strncmp(&data->file[i][j], ".comment", 8) == 0)
			comment_found(data, &i, &j, &comment);
		else if (ft_strncmp(&data->file[i][j], ".name", 5) == 0)
			name_found(data, &i, &j, &name);
		else
			error_manager(data, comment, name);
	}
	return ((comment == 0 || name == 0) ? 0 : i + 1);
}
