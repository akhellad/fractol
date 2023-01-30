#include "../includes/fractol.h"


void    display_controls(t_mlx *mlx)
{
    mlx_string_put(mlx->mlx, mlx->window, 10, 10, 0xffffff, "Fleches : Deplacer la fractale");
    mlx_string_put(mlx->mlx, mlx->window, 10, 30, 0xffffff, "O / I : + / - d'iterations max");
    mlx_string_put(mlx->mlx, mlx->window, 10, 50, 0xffffff, "Iterations max : ");
    mlx_string_put(mlx->mlx, mlx->window, 175, 50, 0xffffff, ft_itoa(mlx->param.max));
    mlx_string_put(mlx->mlx, mlx->window, 10, 70, 0xffffff, "P : Mode photo Julia");
    mlx_string_put(mlx->mlx, mlx->window, 10, 90, 0xffffff, "NUMPAD (1 < > 4) : Changer couleur");
    mlx_string_put(mlx->mlx, mlx->window, 10, 110, 0xffffff, "+ / - NUMPAD / molette souris : + / - zoom");
    mlx_string_put(mlx->mlx, mlx->window, 10, 130, 0xffffff, "0 NUMPAD : Reset frac");
    mlx_string_put(mlx->mlx, mlx->window, 10, 150, 0xffffff, "Fractale : ");
    mlx_string_put(mlx->mlx, mlx->window, 120, 150, 0xffffff, mlx->fr->name);
    mlx_string_put(mlx->mlx, mlx->window, 10, 170, 0xffffff, "NUM (1 < > 3) : changer fractale");
}