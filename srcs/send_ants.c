/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:53:27 by marius            #+#    #+#             */
/*   Updated: 2022/12/10 15:48:14 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	find_last_ant(t_farm *farm, int *path)
{
	int	index;

	index = 0;
	while (path[index] != farm->end->id)
		++index;
	while (index != 0 && farm->id_table[path[index]]->empty == -1)
		--index;
	return (index + 1);
}

static int	reach_finish(int *path, t_farm *farm, int index, int *x, int flag, int *first)
{
	if (path[index] == farm->end->id)
	{
		if (!(flag & FLAG_JSON))
		{
			x[0] = check_print_space(x[0]);
			ft_printf("L%d-%s", farm->id_table[path[index - 1]]->empty,
				farm->id_table[path[index]]->name);
		}
		else
		{
			print_json_move(farm->id_table[path[index - 1]]->empty, farm->id_table[path[index]]->name, first[0]);
			first[0] = 0;
		}
		if (index >= 1)
			farm->id_table[path[index - 1]]->empty = -1;
		return (1);
	}
	return (0);
}

static void	move_the_ant(int *path, t_farm *f, int i, int *x, int flag, int *first)
{
	if (f->id_table[path[i]]->empty == -1 \
		&& i > 1 && f->id_table[path[i - 1]]->empty != -1)
	{
		if (!(flag & FLAG_JSON))
		{
			x[0] = check_print_space(x[0]);
			f->id_table[path[i]]->empty = f->id_table[path[i - 1]]->empty;
			f->id_table[path[i - 1]]->empty = -1;
			ft_printf("L%d-%s", f->id_table[path[i]]->empty,
				f->id_table[path[i]]->name);
		}
		else
		{
			f->id_table[path[i]]->empty = f->id_table[path[i - 1]]->empty;
			f->id_table[path[i - 1]]->empty = -1;
			print_json_move(f->id_table[path[i]]->empty, f->id_table[path[i]]->name, first[0]);
			first[0] = 0;
		}
	}
}

static void	move_ants_on_path(t_farm *farm, int *path, int *fin_ants, int *x, int flag, int *first)
{
	int		index;

	index = find_last_ant(farm, path);
	if (path[0] == farm->start->id && path[1] == farm->end->id)
		return ;
	while (index != 0)
	{
		if ((reach_finish(path, farm, index, x, flag, first)) == 1)
			++fin_ants[0];
		else if (fin_ants[0] < farm->ant_nb)
			move_the_ant(path, farm, index, x, flag, first);
		--index;
	}
}

int	send_ants(t_farm *farm, t_path *paths, int mv_ants, int flag)
{
	int		fin_ants;
	int		index1;
	int		index2;
	int		x;
	int		first;
	t_path	*path;

	mv_ants = 0;
	index2 = 0;
	fin_ants = 0;
	while (fin_ants < farm->ant_nb && (++index2 || 1))
	{
		if (flag & FLAG_JSON)
			print_json_turn_start(index2);
		first = 1;
		path = reset_ants(&x, &index1, paths);
		while (++index1 < paths->max)
		{
			move_ants_on_path(farm, path->path, &fin_ants, &x, flag, &first);
			if (mv_ants < farm->ant_nb && paths->division[index1] > 0)
			{
				if (!(flag & FLAG_JSON))
					x = check_print_space(x);
				mv_ants = send_new_ant(farm, path->path, mv_ants, &fin_ants, flag, &first);
				--paths->division[index1];
			}
			path = path->next;
		}
		if (flag & FLAG_JSON)
			print_json_turn_end();
		else
			ft_putchar('\n');
	}
	return (index2);
}
