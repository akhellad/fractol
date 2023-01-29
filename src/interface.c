#include "../includes/fractol.h"

void mlx_fill_rectangle(t_mlx *mlx, int x, int y, int width, int height)
{
    int i = x;
    int j = y;

    while (i < x + height)
    {
        j = y;
        while (j < y + width)
        {
            mlx_pixel_put(mlx->mlx, mlx->window, i, j, 0x222d5a);
            j++;
        }
        i++;
    }
}

void    draw_line_x(t_mlx *mlx, int y0)
{
    int x0;
    int x1;
    int y1;

    y1 = y0 + 3;
    x0 = 600;
    x1 = 780;
    while (y0 < y1)
    {
        while(x0 < x1)
        {
            mlx_pixel_put(mlx->mlx, mlx->window, x0, y0, 0xffffff);
            x0 ++;
        }
        x0 = 600;
        y0++;
    }
    
}

void    draw_line_y(t_mlx *mlx, int x0)
{
    int y0;
    int y1;
    int x1;

    x1 = x0 + 3;
    y0 = 0;
    y1 = 560;
    while (x0 < x1)
    {
        while(y0 < y1)
        {
            mlx_pixel_put(mlx->mlx, mlx->window, x0, y0, 0xffffff);
            y0 ++;
        }
        y0 = 0;
        x0++;
    }
    
}

void draw_limits(t_mlx *mlx)
{
    mlx_fill_rectangle(mlx, 600, 0, 560, 180);
	draw_line_x(mlx, 0);
	draw_line_y(mlx, 777);
	draw_line_x(mlx, 557);
	draw_line_y(mlx, 597);
}

void    display_controls(t_mlx *mlx)
{
    mlx_string_put(mlx->mlx, mlx->window, 650, 15, 0xffffff, "Controles clavier :");
    mlx_string_put(mlx->mlx, mlx->window, 605, 40, 0xffffff, "Fleches : Deplacer la fractale");
    mlx_string_put(mlx->mlx, mlx->window, 605, 55, 0xffffff, "O / I : + / - d'iterations max");
    mlx_string_put(mlx->mlx, mlx->window, 605, 70, 0xffffff, "P : Mode photo Julia");
    mlx_string_put(mlx->mlx, mlx->window, 605, 85, 0xffffff, "NUM (entre 1 et 4) : Changer");
    mlx_string_put(mlx->mlx, mlx->window, 605, 100, 0xffffff, "couleur");
    mlx_string_put(mlx->mlx, mlx->window, 605, 115, 0xffffff, "+ / - NUMPAD : + / - zoom");
    mlx_string_put(mlx->mlx, mlx->window, 605, 130, 0xffffff, "0 NUMPAD : reset zoom");

}