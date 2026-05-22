/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:53:33 by marius            #+#    #+#             */
/*   Updated: 2022/12/11 16:12:53 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	print_count(int i)
{
	ft_printf("%d line", i);
	if (i != 1)
		ft_putchar('s');
	ft_putchar('\n');
}

int	solve(t_farm *farm, int flag)
{
	t_queue	queue;
	t_path	*path_list;
	int		i;

	if (initialise_queue(&queue, farm) < 0)
	{
		ft_printf("ERROR\n");
		free_queue(&queue);
		return (-1);
	}
	if (generate(&queue, farm, &path_list, 0) == -1)
	{
		ft_printf("ERROR\n");
		free_queue(&queue);
		free_path(path_list);
		return (-1);
	}
	if (flag & FLAG_JSON)
		print_json_map(farm);
	i = send_ants(farm, path_list, farm->ant_nb, flag);
	if (flag & FLAG_JSON)
		print_json_finalize();
	free_path(path_list);
	free_queue(&queue);
	if (flag & FLAG_LINES)
		print_count(i);
	return (0);
}
