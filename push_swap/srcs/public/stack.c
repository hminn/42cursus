/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:15:12 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/01 16:35:28 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/stack.h"

t_node	*create_node(int new_value)
{
	t_node *new_node;

	if (!(new_node = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	new_node->value = new_value;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	delete_node(t_node *remove_node)
{
	free(remove_node);
}

void	delete_stack(t_stack *stack)
{
	t_node *temp_node;

	while (stack->size)
	{
		temp_node = pop(stack);
		delete_node(temp_node);
	}
	free(stack);
}

void	push(t_stack *stack, t_node *new_node)
{
	if (stack->size == 0)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		new_node->next = stack->top;
		new_node->prev = stack->top->prev;
		stack->top->prev = new_node;
		stack->bottom->next = new_node;
		stack->top = new_node;
	}
	stack->size++;
}

t_node	*pop(t_stack *stack)
{
	t_node *temp_node;

	if (stack->size == 0)
		temp_node = NULL;
	else
	{
		temp_node = stack->top;
		stack->top = temp_node->next;
		stack->top->prev = temp_node->prev;
		stack->bottom->next = stack->top;
		if (stack->size == 1)
		{
			stack->top = NULL;
			stack->bottom = NULL;
		}
		stack->size--;
	}
	return (temp_node);
}
