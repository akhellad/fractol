#include "../includes/fractol.h"

void	julia_set(t_w *w)
{
	while(w->f.x < w->f.image_x)
	{
		while(w->f.y < w->f.image_y)
		{
			w->f.zx = w->f.x / w->f.zoom_x + w->f.x1;
			w->f.zy = w->f.y / w->f.zoom_y + w->f.y1;
			w->f.cx = w->j.cx;
			w->f.cy = w->j.cy;
			w->f.count = 0;
			count(w);
			draw(w);
			w->f.y ++;
		}
		w->f.y = 0;
		w->f.x ++;
	}
}

void	julia(t_w *w)
{

	w->f.x1 = w->f.nx + (-1 * w->f.h);
	w->f.x2 = w->f.nx + (1 * w->f.h);
	w->f.y1 = w->f.ny + (-1.2 * w->f.h);
	w->f.y2 = w->f.ny + (1.2 * w->f.h);
	w->f.image_x = w->f.w_len;
	w->f.image_y = w->f.w_len;
	w->f.iteration_max = 150 * w->f.m;
	w->f.x = 0;
	w->f.y = 0;

	julia_set(w);
	w->f.zoom_x = w->f.image_x / (w->f.x2 - w->f.x1);
	w->f.zoom_y = w->f.image_y / (w->f.y2 - w->f.y1);

	mlx_put_image_to_window(w->mlx, w->mlx_w, w->img1.img, 0, 0);
}