/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:53:36 by akhellad          #+#    #+#             */
/*   Updated: 2023/01/17 15:35:13 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mendel_calc(t_w *w)
{
	while (w->f.y < w->f.image_y)
	{
		w->f.x = 0;
		while (w->f.x < w->f.image_x)
		{
			w->f.cx = (w->f.x / w->f.zoom_x + w->f.x1);
			w->f.cy = (w->f.y / w->f.zoom_y + w->f.y1);
			w->f.zx = 0;
			w->f.zy = 0;
			w->f.count = 0;
			count(w);
			draw(w);
			w->f.x ++;
		}
		w->f.y ++;
	}
}

void	mendel(t_w *w)
{
	w->f.x1 = (w->f.nx + (-1.2 * w->f.h) - 0.6);
	w->f.x2 = (w->f.nx + (1.2 * w->f.h) - 0.6);
	w->f.y1 = (w->f.ny + (-1.2 * w->f.h));
	w->f.y2 = (w->f.ny + (1.2 * w->f.h));
	w->f.image_x = w->f.w_len;
	w->f.image_y = w->f.w_len;
	w->f.x = 0;
	w->f.y = 0;
	w->f.iteration_max = 150;
	w->f.zoom_x = (w->f.image_x / (w->f.x2 - w->f.x1));
	w->f.zoom_y = (w->f.image_y / (w->f.y2 - w->f.y1));
	mendel_calc(w);
	mlx_put_image_to_window(w->mlx, w->mlx_w, w->img1.img, 0, 0);
}
