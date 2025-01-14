/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:11:36 by dkros             #+#    #+#             */
/*   Updated: 2024/06/13 18:12:13 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol(const char *str)
{
	int		c;
	long	num;

	c = 1;
	num = 0;
	while (*str && ((str[0] >= '\t' && str[0] <= '\r') || str[0] == ' '))
		str++;
	while (str[0] == '0')
		str++;
	if ((str[0] == 43 || str[0] == 45) && *str)
	{
		if (str[0] == 45)
			c = -1;
		str++;
	}
	while (str[0] >= '0' && str[0] <= '9' && *str)
	{
		num = num * 10 + (str[0] - '0');
		if ((num * c) > INT_MAX || (num * c) < INT_MIN)
			return (LONG_MIN);
		str++;
	}
	return (num * c);
}

int	check_format(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' '))
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] != '\0')
	{
		if (!(ft_isdigit(str[i]))
			&& !((str[i] == '-') && ft_isdigit(str[i + 1])))
			return (0);
		if (i > 11)
			return (0);
		i++;
	}
	return (1);
}

int	ft_doubles(t_stack *stack_x, long num)
{
	t_node	*current;

	current = stack_x->top;
	while (current != NULL)
	{
		if (current->data == num)
			return (0);
		current = current->next;
	}
	return (1);
}
