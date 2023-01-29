#include "../includes/fractol.h"

t_mlx		*mlx_del(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->img != NULL)
		del_image(mlx, mlx->img);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx		*init_mlx(t_fr *f)
{
	t_mlx	*mlx;
	char	*title;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	title ="Fract'ol";
	if ((mlx->mlx = mlx_init()) == NULL ||
		(mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH * 1.3,
			WIN_HEIGHT, title)) == NULL ||
		(mlx->img = new_image(mlx)) == NULL ||
		(mlx->data = ft_memalloc(sizeof(t_pixel) * WIN_WIDTH
								* WIN_HEIGHT)) == NULL)
		return (mlx_del(mlx));
	mlx->mouse.isdown = 0;
	mlx->fr = f;
	mlx->mouselock = 1 - f->mouse;
	mlx->palette = get_palettes();
	mlx->smooth = 1;
	return (mlx);
}

