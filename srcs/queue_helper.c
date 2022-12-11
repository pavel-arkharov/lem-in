/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parkharo <parkharo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:53:13 by marius            #+#    #+#             */
/*   Updated: 2022/12/10 17:18:43 by parkharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	set_to_n(int **set, int length, int n)
{
	int	index;

	index = -1;
	while (++index < length)
		set[0][index] = n;
	return (0);
}

int	initialise_queue(t_queue *queue, t_farm *farm)
{
	int	index;

	index = 0;
	queue->length = farm->room_nb;
	queue->queue = NULL;
	queue->prev = NULL;
	queue->flow = NULL;
	queue->visited = NULL;
	if (!(malloc_q(queue)))
		return (-1);
	while (index < queue->length)
	{
		queue->flow[index] = ft_memalloc(sizeof(int) * queue->length);
		if (!(queue->flow[index++]))
			return (-1);
	}
	set_to_n(&queue->queue, queue->length, -1);
	set_to_n(&queue->prev, queue->length, -1);
	reset_queue(queue, farm->start->id, -1);
	return (0);
}

void	reset_queue(t_queue *queue, int start, int end)
{
	queue->queue[0] = start;
	queue->visited[start] = 1;
	queue->position = 1;
	if (end >= 0)
		queue->visited[end] = 0;
}

void	clear_queue(t_queue *queue)
{
	set_to_n(&queue->prev, queue->length, -1);
	set_to_n(&queue->queue, queue->length, -1);
}

void	free_queue(t_queue *queue)
{
	int	index;

	index = 0;
	while (index < queue->length)
	{
		ft_memdel((void *)&queue->flow[index]);
		++index;
	}
	if (queue->flow != NULL)
		free(queue->flow);
	if (queue->prev != NULL)
		free(queue->prev);
	if (queue->queue != NULL)
		free(queue->queue);
	if (queue->visited != NULL)
		free(queue->visited);
}
