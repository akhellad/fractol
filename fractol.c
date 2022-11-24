#include "./mlx/mlx.h"


typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

typedef struct couleurs_s
{
	int R;
	int G;
	int B;
} Couleur_t;


int main ()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	Couleur_t couleur;
	couleur -> R = 255;

	int y = 100;
	int x = 100;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "first window");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (y++ < 300)
		my_mlx_pixel_put(&img, x, y, couleur);
	while (x ++ < 300)
		my_mlx_pixel_put(&img, x, y, 0xff0000);
	while (y -- > 100)
		my_mlx_pixel_put(&img, x, y, 0xff0000);
	while (x -- > 100)
		my_mlx_pixel_put(&img, x, y, 0xff0000);		
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}