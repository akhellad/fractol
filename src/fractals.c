#include "fractol.h"

void	mendel(t_w *w)
{

	w->f.x1 = (w->f.nx + (-2.0 * w->f.h));
	w->f.x2 = (w->f.nx + (0.6 * w->f.h));
	w->f.y1 = (w->f.ny + (-1.2 * w->f.h));
	w->f.y2 = (w->f.ny + (1.2 * w->f.h));
	w->f.image_x = w->f.w_len;
	w->f.image_y = w->f.w_len;
	w->f.iteration_max = 30;
	w->f.x = 0;
	w->f.y = 0;

	w->f.zoom_x = (w->f.image_x / (w->f.x2 - w->f.x1));
	w->f.zoom_y = (w->f.image_y / (w->f.y2 - w->f.y1));

	while(w->f.x < w->f.image_x)
	{
		while(w->f.y < w->f.image_y)
		{
			w->f.cx = (w->f.x / w->f.zoom_x + w->f.x1);
			w->f.cy = (w->f.y / w->f.zoom_y + w->f.y1);
			w->f.zx = 0;
			w->f.zy = 0;
			w->f.count = 0;
			count(w);
			draw(w);
			w->f.y ++;
		}
		w->f.y = 0;
		w->f.x ++;
		mlx_put_image_to_window(w->mlx, w->mlx_w, w->img1.img, 0, 0);
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
	w->f.iteration_max = 100 * w->f.m;
	w->f.x = 0;
	w->f.y = 0;


	w->f.zoom_x = w->f.image_x / (w->f.x2 - w->f.x1);
	w->f.zoom_y = w->f.image_y / (w->f.y2 - w->f.y1);

	while(w->f.x < w->f.image_x)
	{
		while(w->f.y < w->f.image_y)
		{
			w->f.zx = w->f.x / w->f.zoom_x + w->f.x1;
			w->f.zy = w->f.y / w->f.zoom_y + w->f.y1;
			w->f.cx = 0.285 * w->f.p;
			w->f.cy = 0.01 * w->f.p;
			w->f.count = 0;
			count(w);
			draw(w);
			w->f.y ++;
		}
		w->f.y = 0;
		w->f.x ++;
	}
	mlx_put_image_to_window(w->mlx, w->mlx_w, w->img1.img, 0, 0);
}