/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 23:07:07 by dkros             #+#    #+#             */
/*   Updated: 2024/06/06 18:21:17 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_stack(char *argv[], t_stack *a)
{
	int		i;
	long	num;

	i = 1;
	while (argv[i])
		i++;
	i--;
	while (i >= 1)
	{
		if (check_format(argv[i]) == 0)
			return (-1);
		num = ft_atol(argv[i]);
		if (num == LONG_MIN || ft_doubles(a, num) == 0)
			return (-1);
		if (fillstack(a, num) == -1)
			return (-1);
		i--;
	}
	return (1);
}

t_node	*create_node(long data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	create_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;

	*stack_a = (t_stack *)malloc(sizeof(t_stack));
	a = *stack_a;
	*stack_b = (t_stack *)malloc(sizeof(t_stack));
	b = *stack_b;
	if (!stack_a || !stack_b)
		return ;
	a->top = NULL;
	a->id = 'a';
	a->size = 0;
	b->top = NULL;
	b->id = 'b';
	b->size = 0;
	return ;
}

int	fillstack(t_stack *stack_x, long data)
{
	t_node	*new_node;

	if (data > INT_MAX || data < INT_MIN)
		return (-1);
	new_node = create_node(data);
	stack_x->size++;
	if (!stack_x->top)
		stack_x->top = new_node;
	else
	{
		new_node->next = stack_x->top;
		stack_x->top->prev = new_node;
		stack_x->top = new_node;
	}
	return (0);
}

void	free_stack(t_stack **stack_x)
{
	t_stack	*tempstack;
	t_node	*tempnode;

	tempstack = *stack_x;
	if (tempstack->top == NULL)
	{
		free(tempstack);
		tempstack = NULL;
		return ;
	}
	tempnode = tempstack->top;
	while (tempnode->next != NULL)
	{
		tempnode = tempnode->next;
		free(tempnode->prev);
	}
	free(tempnode);
	tempnode = NULL;
	free(*stack_x);
	stack_x = NULL;
	return ;
}
