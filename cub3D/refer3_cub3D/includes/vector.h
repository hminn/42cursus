/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vector.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/02 13:22:33 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/01 03:09:23 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define CARDINALS	"NSWE"
# define PLANES		"EWNS"

typedef enum		e_cardinal
{
	NORTH, SOUTH, WEST, EAST
}					t_cardinal;

typedef struct		s_vector
{
	float	x;
	float	y;
}					t_vector;

typedef struct		s_ivector
{
	int	x;
	int	y;
}					t_ivector;

t_vector			cardinal(t_cardinal direction);
void				vrotate(t_vector *vector, float alpha);

#endif
