/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:06:58 by akhellad          #+#    #+#             */
/*   Updated: 2023/02/06 15:08:54 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->adrr + (y * data->lengh + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

t_img	*del_image(t_mlx *mlx, t_img *img)
{
	if (img != NULL)
	{
		if (img->img != NULL)
			mlx_destroy_image(mlx->mlx, img->img);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

t_img	*new_image(t_mlx *mlx)
{
	t_img		*img;

	img = ft_memalloc(sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (img->img == NULL)
		return (del_image(mlx, img));
	img->adrr = mlx_get_data_addr(img->img, &img->bpp, &img->lengh,
			&img->endian);
	img->bpp /= 8;
	return (img);
}
