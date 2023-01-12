#include "./mlx/mlx.h"
#include <stdio.h>
#include <math.h>

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef	struct s_frac {
	double x1;
	double y1;
	double zx;
	double zy;
	double cx;
	double tempx;
	double cy;
	double image_x;
	double image_y;
	double x2;
	double y2;
	double zoom_x;
	double zoom_y;
	double pos_x;
	double pos_y;
	int x;
	int y;
	int count;
	int iteration_max;
	int win_len;
	double h;
	double p;
	double m;
	double nx;
	double ny; 
	char *name;
	float Z;
	int colors;
}			t_frac;

typedef struct	s_win {
	void	*mlx;
	void	*mlx_win;
	t_data	img1;
	t_frac	frac;
}				t_win;

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
		{
			i ++;
		}
		else
			return (1);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	mlxinit(t_win *win)
{
	win->mlx = mlx_init();
	win->mlx_win = mlx_new_window(win->mlx, 700, 700, "first window");
	win->img1.img = mlx_new_image(win->mlx, 700, 700);
	win->img1.addr = mlx_get_data_addr(win->img1.img, &win->img1.bits_per_pixel, &win->img1.line_length, &win->img1.endian);
}

void	julia(t_win *win)
{
	int	color;
	double	n_color;

	win->frac.x1 = win->frac.nx + (-1 * win->frac.h);
	win->frac.x2 = win->frac.nx + (1 * win->frac.h);
	win->frac.y1 = win->frac.ny + (-1.2 * win->frac.h);
	win->frac.y2 = win->frac.ny + (1.2 * win->frac.h);
	win->frac.image_x = 700;
	win->frac.image_y = 700;
	win->frac.iteration_max = 100 * win->frac.m;
	win->frac.x = 0;
	win->frac.y = 0;


	win->frac.zoom_x = win->frac.image_x / (win->frac.x2 - win->frac.x1);
	win->frac.zoom_y = win->frac.image_y / (win->frac.y2 - win->frac.y1);

	while(win->frac.x < win->frac.image_x)
	{
		while(win->frac.y < win->frac.image_y)
		{
			win->frac.zx = win->frac.x / win->frac.zoom_x + win->frac.x1;
			win->frac.zy = win->frac.y / win->frac.zoom_y + win->frac.y1;
			win->frac.cx = -0.4 * win->frac.p;
			win->frac.cy = 0.6 * win->frac.p;
			win->frac.count = 0;
			while (win->frac.zx*win->frac.zx + win->frac.zy*win->frac.zy < 4 && win->frac.count < win->frac.iteration_max)
			{
				win->frac.tempx = win->frac.zx;
				win->frac.zx = win->frac.zx * win->frac.zx - win->frac.zy * win->frac.zy + win->frac.cx;
				win->frac.zy = 2 * win->frac.zy * win->frac.tempx + win->frac.cy;
				win->frac.count += 1;
				if (win->frac.count == win->frac.iteration_max)
					my_mlx_pixel_put(&win->img1, win->frac.x, win->frac.y, 0x00000);
			}
			if (win->frac.count != win->frac.iteration_max)
			{
				color = win->frac.count * 256 / win->frac.iteration_max;
				n_color = 0;
				n_color = win->frac.colors + ((color / 8) << 24 | (color) << 16 | (color / 2) << 8 | 0);
				my_mlx_pixel_put(&win->img1, win->frac.x, win->frac.y, n_color);
			}
			win->frac.y ++;
		}
		win->frac.y = 0;
		win->frac.x ++;
	}
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img1.img, 0, 0);
}

int		pick_frac(t_frac *frac)
{
	if (!ft_strcmp(frac->name, "mendel"))
		return (1);
	if (!ft_strcmp(frac->name, "julia"))
		return (2);
	return (0);
}

void	mendel(t_win *window)
{
	int	color;
	double	n_color;

	window->frac.x1 = (window->frac.nx + (-2.0 * window->frac.h));
	window->frac.x2 = (window->frac.nx + (0.6 * window->frac.h));
	window->frac.y1 = (window->frac.ny + (-1.2 * window->frac.h));
	window->frac.y2 = (window->frac.ny + (1.2 * window->frac.h));
	window->frac.image_x = window->frac.win_len;
	window->frac.image_y = window->frac.win_len;
	window->frac.iteration_max = 30;
	window->frac.x = 0;
	window->frac.y = 0;

	window->frac.zoom_x = (window->frac.image_x / (window->frac.x2 - window->frac.x1));
	window->frac.zoom_y = (window->frac.image_y / (window->frac.y2 - window->frac.y1));

	while(window->frac.x < window->frac.image_x)
	{
		while(window->frac.y < window->frac.image_y)
		{
			window->frac.cx = (window->frac.x / window->frac.zoom_x + window->frac.x1);
			window->frac.cy = (window->frac.y / window->frac.zoom_y + window->frac.y1);
			window->frac.zx = 0;
			window->frac.zy = 0;
			window->frac.count = 0;
			while (window->frac.zx*window->frac.zx + window->frac.zy*window->frac.zy < 4 && window->frac.count < window->frac.iteration_max)
			{
				window->frac.tempx = window->frac.zx;
				window->frac.zx = window->frac.zx * window->frac.zx - window->frac.zy * window->frac.zy + window->frac.cx;
				window->frac.zy = 2 * window->frac.zy * window->frac.tempx + window->frac.cy;
				window->frac.count += 1;
				if (window->frac.count == window->frac.iteration_max)
					my_mlx_pixel_put(&window->img1, window->frac.x, window->frac.y, 0x00000);
			}
			if (window->frac.count != window->frac.iteration_max)
			{
				color = window->frac.count * 256 / window->frac.iteration_max;
				n_color = 0;
				n_color =  window->frac.colors + ((color / 8) << 24 | (color) << 16 | (color / 2) << 8 | 0);
				my_mlx_pixel_put(&window->img1, window->frac.x, window->frac.y, n_color);
			}
			window->frac.y ++;
		}
		window->frac.y = 0;
		window->frac.x ++;
		mlx_put_image_to_window(window->mlx, window->mlx_win, window->img1.img, 0, 0);
	}

}


int mouse_hook(int keycode, int x, int y, t_win *window)
{
	if (keycode == 5)
	{
		window->frac.h /= 1.1;
		window->frac.nx += 0.001 * ((x - window->frac.win_len / 2) * (window->frac.h));
		window->frac.ny += 0.001 * ((y - window->frac.win_len / 2) * (window->frac.h));
		window->frac.m *= 1.001;
		if(pick_frac(&window->frac) == 1)
			mendel(window);
		if(pick_frac(&window->frac) == 2)
			julia(window);
	}
	if (keycode == 4)
	{
		printf("zoom = %f\n", window->frac.h);
		window->frac.h *= 1.1;
		window->frac.nx -= 0.001 * ((x - window->frac.win_len / 2) * (window->frac.h));
		window->frac.ny -= 0.001 * ((y - window->frac.win_len / 2) * (window->frac.h));		
		window->frac.m /= 1.001;
		if(pick_frac(&window->frac) == 1)
			mendel(window);
		if(pick_frac(&window->frac) == 2)
			julia(window);
	}
	if (keycode == 1)
	{
		window->frac.h = 1;
		window->frac.nx = 0;
		window->frac.ny = 0;
		window->frac.pos_x = 0;
		window->frac.pos_y = 0;
		if(pick_frac(&window->frac) == 1)
			mendel(window);
		if(pick_frac(&window->frac) == 2)
			julia(window);
	}
	return (0);
}

int	change(int keycode, t_win *win)
{
	printf("%d\n", keycode);
	if (keycode == 31)
	{
		win->frac.p /= 1.001;
		if(pick_frac(&win->frac) == 1)
			mendel(win);
		if(pick_frac(&win->frac) == 2)
			julia(win);
	}
	if (keycode == 34)
	{
		win->frac.p *= 1.001;
		if(pick_frac(&win->frac) == 1)
			mendel(win);
		if(pick_frac(&win->frac) == 2)
			julia(win);
	}
	if(keycode == 124)
	{
		win->frac.nx -= 0.1 * win->frac.h ;
		if(pick_frac(&win->frac) == 1)
			mendel(win);
		if(pick_frac(&win->frac) == 2)
			julia(win);
	}
	if (keycode == 123)
	{
	win->frac.nx += 0.1 * win->frac.h;
	if(pick_frac(&win->frac) == 1)
		mendel(win);
	if(pick_frac(&win->frac) == 2)
		julia(win);
	}
	if (keycode == 126)
	{
		win->frac.ny -= 0.1 * win->frac.h;
		if(pick_frac(&win->frac) == 1)
			mendel(win);
		if(pick_frac(&win->frac) == 2)
			julia(win);
	}
	if (keycode == 125)
	{
		win->frac.ny += 0.1 * win->frac.h;
		if(pick_frac(&win->frac) == 1)
			mendel(win);
		if(pick_frac(&win->frac) == 2)
			julia(win);
	}
	if (keycode == 69)
	{
		win->frac.h /= 1.1;
		win->frac.m *= 1.001;
		if(pick_frac(&win->frac) == 1)
			mendel(win);
		if(pick_frac(&win->frac) == 2)
			julia(win);
	}
	if (keycode == 78)
	{
	win->frac.h *= 1.1;
	win->frac.m *= 1.001;
	if(pick_frac(&win->frac) == 1)
		mendel(win);
	if(pick_frac(&win->frac) == 2)
		julia(win);
	}
	if (keycode == 35)
	{
		win->frac.h = 1;
		win->frac.nx = 0;
		win->frac.ny = 0;
		if(pick_frac(&win->frac) == 1)
			mendel(win);
		if(pick_frac(&win->frac) == 2)
			julia(win);
	}
	if (keycode == 82)
	{
		win->frac.colors = 0;
		if(pick_frac(&win->frac) == 1)
			mendel(win);
		if(pick_frac(&win->frac) == 2)
			julia(win);
	}
	if (keycode == 83)
	{
		win->frac.colors = 327700;
		if(pick_frac(&win->frac) == 1)
			mendel(win);
		if(pick_frac(&win->frac) == 2)
			julia(win);
	}
	if (keycode == 84)
	{
		win->frac.colors = 4850000;
		if(pick_frac(&win->frac) == 1)
			mendel(win);
		if(pick_frac(&win->frac) == 2)
			julia(win);
	}
	if (keycode == 85)
	{
		win->frac.colors = 832100;
		if(pick_frac(&win->frac) == 1)
			mendel(win);
		if(pick_frac(&win->frac) == 2)
			julia(win);
	}
	return 0;
}

int main ()
{
	t_win	win;

	win.frac.h = 1;
	win.frac.p = 1;
	win.frac.m = 1;
	win.frac.pos_x = 0;
	win.frac.pos_y = 0;
	win.frac.name = "julia";
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, 700, 700, "first window");
	win.img1.img = mlx_new_image(win.mlx, 700, 700);
	win.img1.addr = mlx_get_data_addr(win.img1.img, &win.img1.bits_per_pixel, &win.img1.line_length, &win.img1.endian);
	win.frac.win_len = 700;
	mlx_mouse_hook(win.mlx_win, mouse_hook, &win);
	mlx_key_hook(win.mlx_win, change , &win);
	mlx_loop(win.mlx);
}