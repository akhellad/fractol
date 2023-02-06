/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:32:32 by akhellad          #+#    #+#             */
/*   Updated: 2023/02/06 16:35:33 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_mlx	*mlx_del(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->img != NULL)
		del_image(mlx, mlx->img);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx	*init_mlx(t_fr *f)
{
	t_mlx	*mlx;
	char	*title;

	mlx = ft_memalloc(sizeof(t_mlx));
	if (mlx == NULL)
		return (NULL);
	title = "Fract'ol";
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH, \
					WIN_HEIGHT, title);
	mlx->img = new_image(mlx);
	mlx->data = ft_memalloc(sizeof(t_pixel) * WIN_WIDTH \
								* WIN_HEIGHT);
	if (mlx->mlx == NULL || mlx->window == NULL || mlx->img == NULL || \
		mlx->data == NULL)
		return (mlx_del(mlx));
	mlx->mouse.isdown = 0;
	mlx->fr = f;
	mlx->mouselock = 1 - f->mouse;
	mlx->palette = get_palettes();
	mlx->smooth = 1;
	return (mlx);
}
