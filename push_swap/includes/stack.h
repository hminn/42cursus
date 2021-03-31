/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:26:25 by hyeokim           #+#    #+#             */
/*   Updated: 2021/03/30 16:40:55 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# define SUCCESS 1
#include <stdlib.h>
#include <stdio.h>

typedef struct		s_node
{

	int				value;
	struct s_node	*prev;
	struct s_node	*next;

}					t_node;

typedef struct		s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;

}					t_stack;

int					create_stack(t_stack **stack);
t_node				*create_node(int new_value);
void				delete_node (t_node *remove_node);
void				delete_stack (t_stack *stack);
void				push(t_stack *stack, t_node *new_node);
t_node				*pop(t_stack *stack);
void				init_stack(t_stack **stack, int argc, char *argv[]);
int					is_it_dup(int argc, char *argv[]);

#endif