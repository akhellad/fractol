/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:56:49 by akhellad          #+#    #+#             */
/*   Updated: 2023/02/06 16:00:01 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_palette	*get_palettes(void)
{
	static t_palette	array[3];

	array[0] = (t_palette){7, 0, {0x2C3E50, 0x34495E, 0x7F8C8D, \
						0x95A5A6, 0xBDC3C7, 0x16A085, 0x2980B9}};
	array[1] = (t_palette){6, 0, {0xBDC3C7, 0xFF6347, 0xFF4500, \
						0xDC143C, 0xB22222, 0x8B0000}};
	array[2] = (t_palette){6, 0, {0x800080, 0xFF00FF, 0xFFFF00, \
						0x00FF00, 0x00FFFF, 0x0000FF}};
	return (array);
}

t_palette	*get_palettes2(void)
{
	static t_palette	array[2];

	array[0] = (t_palette){6, 0, {0x800080, 0xFF00FF, 0xFFFF00, \
							0x00FF00, 0x00FFFF, 0x0000FF}};
	array[1] = (t_palette){6, 0, {0xF49AC2, 0xF5B183, 0xF5DA81, \
							0xF5E5AA, 0xF5F5DC, 0xF5F5F5}};
	return (array);
}

t_palette	*get_palettes3(void)
{
	static t_palette	array[2];

	array[0] = (t_palette){5, 0, {0x0000FF, 0x00FFFF, 0x00FF00, \
							0xFFFF00, 0xFF0000}};
	array[1] = (t_palette){6, 0, {0x800080, 0xFF00FF, 0xFFFF00, \
							0x00FF00, 0x00FFFF, 0x0000FF}};
	return (array);
}

t_palette	*get_palettes4(void)
{
	static t_palette	array[4];

	array[0] = (t_palette){5, 0, {0xF44336, 0xFF9800, \
					0xFFC107, 0x4CAF50, 0x2196F3}};
	array[1] = (t_palette){6, 0, {0x9C27B0, 0xE91E63, \
					0x3F51B5, 0x2196F3, 0x00BCD4, 0x009688}};
	array[2] = (t_palette){5, 0, {0xFF5722, 0x795548, \
					0x9E9E9E, 0x607D8B, 0x263238}};
	array[3] = (t_palette){5, 0, {0xF44336, 0xE91E63, \
					0x9C27B0, 0x673AB7, 0x3F51B5}};
	return (array);
}

t_palette	*get_palettes5(void)
{
	static t_palette	array[3];

	array[0] = (t_palette){7, 0, {0xF44336, 0xFFEB3B, 0x4CAF50, \
					0x2196F3, 0x9C27B0, 0x3F51B5, 0xE91E63}};
	array[1] = (t_palette){6, 0, {0xFF5733, 0xFFC300, 0x00C851, \
					0x0085C7, 0xBA00FF, 0xC70000}};
	array[2] = (t_palette){6, 0, {0xFFB347, 0xB3E5FC, 0x4DB6AC, \
					0x00ACC1, 0x9FA8DA, 0x880E4F}};
	return (array);
}
