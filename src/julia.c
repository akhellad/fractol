/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:15:55 by akhellad          #+#    #+#             */
/*   Updated: 2023/02/06 15:16:33 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia_hook_mousemove(int x, int y, t_mlx *mlx)
{
	mlx->mouse.lastx = mlx->mouse.x;
	mlx->mouse.lasty = mlx->mouse.y;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	if (!mlx->mouselock)
		mlx->param.mouse = convert(x, y, &mlx->param);
	if (mlx->fr->mouse && !mlx->mouselock)
		render(mlx);
	return (0);
}

t_pixel	julia_set(int x, int y, t_param *v, t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;
	t_complex	temp;
	int			i;

	(void)mlx;
	z = convert(x, y, v);
	c = v->mouse;
	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < v->max)
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = z.r * z.i * 2 + c.i;
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

void	julia_param(t_param *v)
{
	v->xmin = -2.0f;
	v->xmax = 2.0f;
	v->ymin = -2.0f;
	v->ymax = 2.0f;
}
