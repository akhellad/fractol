#include "./mlx/mlx.h"
#include <stdio.h>

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*mlx_win;
}				t_vars;

typedef	struct s_fractal {
	float xscale;
	float yscale;
	float zx;
	float zy;
	float cx;
	float tempx;
	float cy;
	float xside;
	float yside;
	float top;
	float left;
	int x;
	int y;
	int count;
	int MAXCOUNT;
}			t_fractal;

typedef	struct s_frac {
	float x1;
	float y1;
	float zx;
	float zy;
	float cx;
	float tempx;
	float cy;
	float image_x;
	float image_y;
	float x2;
	float y2;
	float zoom_x;
	float zoom_y;
	int x;
	int y;
	int count;
	int iteration_max;
}			t_frac;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	mlxinit(t_data *img, t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, 1000, 700, "first window");
	img->img = mlx_new_image(vars->mlx, 1000, 700);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

void	julia(t_frac frac, int win_len, t_data *img, t_vars *vars)
{
	frac.x1 = -1;
	frac.x2 = 1;
	frac.y1 = -1.2;
	frac.y2 = 1.2;
	frac.image_x = 1000;
	frac.image_y = 1000;
	frac.iteration_max = 80;
	frac.x = 0;
	frac.y = 0;

	frac.zoom_x = frac.image_x / (frac.x2 - frac.x1);
	frac.zoom_y = frac.image_y / (frac.y2 - frac.y1);

	while(frac.x < frac.image_x)
	{
		while(frac.y < frac.image_y)
		{
			frac.zx = frac.x / frac.zoom_x + frac.x1;
			frac.zy = frac.y / frac.zoom_y + frac.y1;
			frac.cx = 0.285;
			frac.cy = 0.01;
			frac.count = 0;
			while (frac.zx*frac.zx + frac.zy*frac.zy < 4 && frac.count < frac.iteration_max)
			{
				frac.tempx = frac.zx;
				frac.zx = frac.zx * frac.zx - frac.zy * frac.zy + frac.cx;
				frac.zy = 2 * frac.zy * frac.tempx + frac.cy;
				frac.count += 1;
				if (frac.count == frac.iteration_max)
					my_mlx_pixel_put(img, frac.x, frac.y, 0x00000);
			}
			if (frac.count != frac.iteration_max)
				my_mlx_pixel_put(img, frac.x, frac.y, frac.count * 10000);
			frac.y ++;
		}
		frac.y = 0;
		frac.x ++;
	}

}

void	mendel(t_frac frac, int win_len, t_data *img, t_vars *vars)
{
	frac.x1 = -2.1;
	frac.x2 = 0.6;
	frac.y1 = -1.2;
	frac.y2 = 1.2;
	frac.image_x = win_len;
	frac.image_y = win_len;
	frac.iteration_max = 30;
	frac.x = 0;
	frac.y = 0;

	frac.zoom_x = frac.image_x / (frac.x2 - frac.x1);
	frac.zoom_y = frac.image_y / (frac.y2 - frac.y1);

	while(frac.x < frac.image_x)
	{
		while(frac.y < frac.image_y)
		{
			frac.cx = frac.x / frac.zoom_x + frac.x1;
			frac.cy = frac.y / frac.zoom_y + frac.y1;
			frac.zx = 0;
			frac.zy = 0;
			frac.count = 0;
			while (frac.zx*frac.zx + frac.zy*frac.zy < 4 && frac.count < frac.iteration_max)
			{
				frac.tempx = frac.zx;
				frac.zx = frac.zx * frac.zx - frac.zy * frac.zy + frac.cx;
				frac.zy = 2 * frac.zy * frac.tempx + frac.cy;
				frac.count += 1;
				if (frac.count == frac.iteration_max)
					my_mlx_pixel_put(img, frac.x, frac.y, 0x00000);
			}
			if (frac.count != frac.iteration_max)
				my_mlx_pixel_put(img, frac.x, frac.y, frac.count * 10000);
			frac.y ++;
		}
		frac.y = 0;
		frac.x ++;
	}

}

int main ()
{
	t_vars	vars;
	t_data	img;
	t_frac fractal;
	int win_len = 1000;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, win_len, win_len, "first window");
	img.img = mlx_new_image(vars.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	julia(fractal, win_len, &img, &vars);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}