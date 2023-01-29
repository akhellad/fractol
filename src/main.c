#include "../includes/fractol.h"

int		error(char *reason)
{
	ft_putendl(reason);
	return (1);
}

int main(int ac, char **av)
{
    t_mlx   *mlx;
    t_fr   *fr;

    if (ac < 2)
        return(error("Pas assez d'arguments !"));
    fr = fractal_match(av[1]);
    if (!fr->name)
        return (error("Veuillez choisir entre :\nMandel\nJulia\nBurning_ship\n"));
    mlx = init_mlx(fr);
    if (mlx == NULL)
        return (error("Erreur a la création de la fenêtre"));
    reset_param(mlx);
    render(mlx);
    mlx_key_hook(mlx->window, key_hook, mlx);
    mlx_hook(mlx->window, 4, 1L << 2, mouse_hook, mlx);
    mlx_hook(mlx->window, 6, 1L << 6, julia_hook_mousemove, mlx);
    mlx_loop(mlx->mlx);
    return (0);
}