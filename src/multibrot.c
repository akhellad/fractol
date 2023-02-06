/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:20:48 by akhellad          #+#    #+#             */
/*   Updated: 2023/02/06 15:28:33 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	multibrot_param(t_param *v)
{
	v->xmin = -2.0f;
	v->xmax = 2.0f;
	v->ymin = -2.0f;
	v->ymax = 2.0f;
}

t_pixel	multibrot_set(int x, int y, t_param *v, t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	int			i;

	(void)mlx;
	z = convert(x, y, v);
	c = convert(x, y, v);
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < v->max)
	{
		temp.r = (z.r * z.r * z.r * z.r * z.r) - (10 * (z.r * z.r * z.r) * \
				(z.i * z.i)) + (5 * z.r * (z.i * z.i * z.i * z.i)) + c.r;
		temp.i = (5 * (z.r * z.r * z.r * z.r) * z.i) - (10 * (z.r * z.r) * \
				(z.i * z.i * z.i)) + (z.i * z.i * z.i * z.i * z.i) + c.i;
		if (z.r == temp.r && z.i == temp.i)
		{
			i = v->max;
			break ;
		}
		z.r = temp.r;
		z.i = temp.i;
		i++;
	}
	return ((t_pixel){.c = z, .i = i});
}
