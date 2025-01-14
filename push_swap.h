/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:52:40 by dkros             #+#    #+#             */
/*   Updated: 2024/06/13 18:20:05 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"
# include <limits.h>

# ifndef MAX_SIZE
#  define MAX_SIZE 100
# endif

typedef struct s_node
{
	long			data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	char	id;
	int		size;
}	t_stack;

int		get_stack(char *argv[], t_stack *a);
int		ft_max_bits(t_stack *s);
void	free_stack(t_stack **stack_x);
void	swap(t_stack *a);
long	ft_pop(t_stack *stack);
t_node	*create_node(long data);
void	create_stacks(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack *stack_a, t_stack *stack_b);
void	rotate_stack(t_stack *stack);
void	rotate_reverse(t_stack *stack_x);
int		fillstack(t_stack *stack_x, long data);
int		ft_bottom(t_stack *stack_x);
int		is_sorted(t_stack *stack_x);
void	ft_sort_three(t_stack *x);
int		is_empty(t_stack *stack_x);
int		check_push(t_stack *a, t_stack *b, int *highest);
void	radix_sort(t_stack *a, t_stack *b, int biggest);
int		*count_bits(t_stack *stack);
long	find_second_min(t_stack *a);
long	find_min(t_stack *a);
void	ft_sort_five(t_stack *a, t_stack *b);
void	ft_end(t_stack **a, t_stack **b, char message);
void	ft_sort_two(t_stack *x);
int		check_format(char *str);
long	ft_atol(const char *str);
int		ft_doubles(t_stack *stack_x, long num);
int		create_index(t_stack *a, t_stack *b);
int		count_smaller_elements(t_stack *a, t_node *current_node);
void	fill_rank_array(t_stack *a, int *rank_array);
void	update_stack_with_ranks(t_stack *a, int *rank_array);
// void	printstack(t_stack *stack_x);

#endif