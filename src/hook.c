/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:03:17 by akhellad          #+#    #+#             */
/*   Updated: 2023/02/06 15:28:33 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom(int x, int y, t_param *v, double z)
{
	double	w;
	double	h;
	double	nw;
	double	nh;

	w = (v->xmax - v->xmin) * (v->zoom);
	h = (v->ymax - v->ymin) * (v->zoom);
	nw = (v->xmax - v->xmin) * (v->zoom * z);
	nh = (v->ymax - v->ymin) * (v->zoom * z);
	v->zoom *= z;
	v->offx -= ((double)x / WIN_WIDTH) * (nw - w);
	v->offy -= ((double)y / WIN_HEIGHT) * (nh - h);
}

void	move(int key, t_mlx *mlx)
{
	double	w;
	double	h;

	w = (mlx->param.xmax - mlx->param.xmin) * mlx->param.zoom;
	h = (mlx->param.ymax - mlx->param.ymin) * mlx->param.zoom;
	if (key == KEY_UP)
		mlx->param.offy -= h * 0.05f;
	if (key == KEY_DOWN)
		mlx->param.offy += h * 0.05f;
	if (key == KEY_LEFT)
		mlx->param.offx -= w * 0.05f;
	if (key == KEY_RIGHT)
		mlx->param.offx += w * 0.05f;
	if (key == KEY_P)
		mlx->mouselock = 1 - mlx->mouselock;
}

void	change_frac(int key, t_mlx *mlx)
{
	if (key == KEY_ONE_PAD)
		mlx->fr = fractal_match("Mandel");
	if (key == KEY_TWO_PAD)
		mlx->fr = fractal_match("Julia");
	if (key == KEY_THREE_PAD)
		mlx->fr = fractal_match("Burning_ship");
	if (key == KEY_FOUR_PAD)
		mlx->fr = fractal_match("multibrot");
	render(mlx);
}

int	key_hook(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		exit(EXIT_SUCCESS);
	if (key == KEY_ZERO)
		reset_param(mlx);
	if (key == KEY_O)
		mlx->param.max *= 1.3;
	if (key == KEY_I)
		if (mlx->param.max / 2 >= 2)
			mlx->param.max /= 1.3;
	if (key == KEY_PLUS)
		zoom(WIN_WIDTH / 2, WIN_HEIGHT / 2, &mlx->param, 1 / ZOOM);
	if (key == KEY_MINUS)
		zoom(WIN_WIDTH / 2, WIN_HEIGHT / 2, &mlx->param, ZOOM);
	change_frac(key, mlx);
	move(key, mlx);
	color_change(key, mlx);
	render(mlx);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	if (button == 4)
	{
		zoom(x, y, &mlx->param, 1 / ZOOM);
		render(mlx);
	}
	else if (button == 5)
	{
		zoom(x, y, &mlx->param, ZOOM);
		render(mlx);
	}
	if (y < 0)
		return (0);
	return (0);
}
