/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:49:30 by dkros             #+#    #+#             */
/*   Updated: 2024/06/13 18:20:11 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	(void)argc;
	create_stacks(&a, &b);
	if (get_stack(argv, a) == -1)
		return (ft_end(&a, &b, 'i'), 1);
	if (create_index(a, b) == -1)
		return (ft_printf("Error"), 1);
	if (a->size <= 2)
		ft_sort_two(a);
	else
	{
		if (!is_sorted(a))
		{
			if (a->size <= 5)
				ft_sort_five(a, b);
			else
				radix_sort(a, b, ft_max_bits(a));
		}
	}
	ft_end(&a, &b, '0');
	return (0);
}

int	is_empty(t_stack *stack_x)
{
	if (stack_x->top == NULL)
		return (1);
	return (0);
}

int	ft_max_bits(t_stack *s)
{
	int		biggest;
	int		max;
	t_node	*temp;

	max = 0;
	temp = s->top;
	biggest = s->top->data;
	while (temp->next != NULL)
	{
		if (temp->data > biggest)
			biggest = temp->data;
		if (temp->next->data > biggest)
			biggest = temp->next->data;
		temp = temp->next;
	}
	while (biggest >= 1)
	{
		biggest /= 2;
		max++;
	}
	return (max);
}

void	ft_end(t_stack **a, t_stack **b, char message)
{
	if (*a != NULL)
		free_stack(a);
	if (*b != NULL)
		free_stack(b);
	if (message == 'i')
		ft_printf("Error\n");
	if (message == 'm')
		ft_printf("Error\n");
	return ;
}

// void	printstack(t_stack *stack_x)
// {
// 	t_node	*temp;

// 	if (!stack_x || stack_x->top == NULL)
// 	{
// 		ft_printf("Stack %c is empty\n", stack_x->id);
// 		return ;
// 	}
// 	temp = stack_x->top;
// 	ft_printf("Stack %c: ", stack_x->id);
// 	while (temp != NULL)
// 	{
// 		ft_printf("%d ", temp->data);
// 		temp = temp->next;
// 	}
// 	ft_printf("\n");
// }
