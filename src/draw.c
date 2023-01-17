/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:38:04 by akhellad          #+#    #+#             */
/*   Updated: 2023/01/17 16:23:45 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw(t_w *w)
{
	int		color;
	double	n_color;

	if (w->f.count == w->f.iteration_max)
		my_mlx_pixel_put(&w->img1, w->f.x, w->f.y, w->f.colors_in);
	if (w->f.count != w->f.iteration_max)
	{
		color = w->f.count * 256 / w->f.iteration_max;
		n_color = 0;
		n_color = w->f.colors_out + (0 << 24 | (color) << 16 \
								| (color) << 8 | (color));
		my_mlx_pixel_put(&w->img1, w->f.x, w->f.y, n_color);
	}
}

void	count(t_w *w)
{
	while (w->f.zx * w->f.zx + w->f.zy * w->f.zy < 4 && \
						w->f.count < w->f.iteration_max)
	{
		w->f.tempx = w->f.zx;
		w->f.zx = w->f.zx * w->f.zx - w->f.zy * w->f.zy + w->f.cx;
		w->f.zy = 2 * w->f.zy * w->f.tempx + w->f.cy;
		w->f.count += 1;
	}
}

void	count_burning_ship(t_w *w)
{
	while (w->f.zx * w->f.zx + w->f.zy * w->f.zy < 4 && \
						w->f.count < w->f.iteration_max)
	{
		w->f.tempx = w->f.zx;
		w->f.zx = w->f.zx * w->f.zx - w->f.zy * w->f.zy + w->f.cx;
		w->f.zy = 2 * fabs(w->f.zy * w->f.tempx) + w->f.cy;
		w->f.count += 1;
	}
}

void	pick_color(int keycode, t_w *w)
{
	pick_color_012(keycode, w);
	pick_color_345(keycode, w);
}
