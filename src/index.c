/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:25:59 by dkros             #+#    #+#             */
/*   Updated: 2024/06/13 18:21:57 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_smaller_elements(t_stack *a, t_node *current_node)
{
	int		rank;
	t_node	*temp;

	rank = 0;
	temp = a->top;
	while (temp != NULL)
	{
		if (temp->data < current_node->data)
			rank++;
		temp = temp->next;
	}
	return (rank);
}

void	fill_rank_array(t_stack *a, int *rank_array)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = a->top;
	while (temp != NULL)
	{
		rank_array[i] = count_smaller_elements(a, temp);
		temp = temp->next;
		i++;
	}
}

void	update_stack_with_ranks(t_stack *a, int *rank_array)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = a->top;
	while (temp != NULL)
	{
		temp->data = rank_array[i];
		temp = temp->next;
		i++;
	}
}

int	create_index(t_stack *a, t_stack *b)
{
	int	*rank_array;

	rank_array = (int *)malloc(a->size * sizeof(int));
	if (rank_array == NULL)
	{
		free_stack(&a);
		free_stack(&b);
		return (-1);
	}
	fill_rank_array(a, rank_array);
	update_stack_with_ranks(a, rank_array);
	free(rank_array);
	return (1);
}
