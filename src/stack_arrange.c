/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_arrange.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:32:27 by mpapin            #+#    #+#             */
/*   Updated: 2025/03/24 15:44:08 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_price = b->current_pos;
		if (!(b->above_median))
			b->push_price = len_b - b->current_pos;
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_pos;
		else
			b->push_price += len_a - b->target_node->current_pos;
		b = b->next;
	}
}

void	set_current_pos(t_stack_node *stack)
{
	int	i;
	int	center;

	i = 0;
	if (stack == NULL)
		return ;
	center = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_pos = i;
		if (i <= center)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	set_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target;
	long			best_match_i;

	while (b)
	{
		best_match_i = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match_i)
			{
				best_match_i = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_i)
			b->target_node = get_smallest(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	t_stack_node	*best_node;
	t_stack_node	*current;
	long			best_val;

	if (b == NULL)
		return ;
	best_val = LONG_MAX;
	best_node = NULL;
	current = b;
	while (current)
	{
		current->cheapest = 0;
		current = current->next;
	}
	current = b;
	while (current)
	{
		if (current->push_price < best_val)
		{
			best_val = current->push_price;
			best_node = current;
		}
		current = current->next;
	}
	if (best_node != NULL)
		best_node->cheapest = 1;
}
