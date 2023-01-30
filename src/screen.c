#include "../includes/fractol.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../includes/stb_image_write.h"

void capture_image_mlx(void *mlx_img, int width, int height)
{
    int bits_per_pixel;
    int size_line;
    int endian;

    void *data = mlx_get_data_addr(mlx_img, &bits_per_pixel, &size_line, &endian);

    stbi_write_png("screenshot.png", width, height, bits_per_pixel / 8, data, size_line);
}