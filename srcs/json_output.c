#include "lemin.h"

void	print_json_map(t_farm *farm)
{
	t_room	*room;
	int		i;
	int		j;
	int		first;

	ft_printf("{\n  \"ants\": %d,\n", farm->ant_nb);
	ft_printf("  \"rooms\": [\n");
	room = farm->first_room;
	while (room)
	{
		ft_printf("    {\"name\": \"%s\", \"x\": %d, \"y\": %d", room->name, room->x, room->y);
		if (room == farm->start)
			ft_printf(", \"role\": \"start\"}");
		else if (room == farm->end)
			ft_printf(", \"role\": \"end\"}");
		else
			ft_printf("}");
		if (room->next && room->next->name)
			ft_printf(",\n");
		else
			ft_printf("\n");
		room = room->next;
	}
	ft_printf("  ],\n  \"links\": [\n");
	first = 1;
	i = 0;
	while (i < farm->room_nb)
	{
		j = i + 1;
		while (j < farm->room_nb)
		{
			if (farm->links[i][j])
			{
				if (!first)
					ft_printf(",\n");
				ft_printf("    {\"from\": \"%s\", \"to\": \"%s\"}", farm->id_table[i]->name, farm->id_table[j]->name);
				first = 0;
			}
			j++;
		}
		i++;
	}
	ft_printf("\n  ],\n  \"turns\": [\n");
}

void	print_json_turn_start(int turn)
{
	if (turn > 1)
		ft_printf(",\n");
	ft_printf("    {\"turn\": %d, \"moves\": [", turn);
}

void	print_json_move(int ant, char *room, int first)
{
	if (!first)
		ft_printf(", ");
	ft_printf("{\"ant\": %d, \"to\": \"%s\"}", ant, room);
}

void	print_json_turn_end(void)
{
	ft_printf("]}");
}

void	print_json_finalize(void)
{
	ft_printf("\n  ]\n}\n");
}
