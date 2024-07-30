#include <mlx.h>
#include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	put_pixel(t_data *data, int x, int y, int color);

int	main(void)
{
	void	*mlx;
	void	*window;
	t_data	img;
	int		x;
	int		y;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1280, 1080, "Example Test");
	img.img = mlx_new_image(mlx, 1280, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, & img.endian);

	//Print yellow rectangle
	y = 32;
	while (y < 72)
	{
		x = 80;
		while(x < 120)
		{
			if ((y >= 32 && y < 37) || ((y >= 37 && y < 67) && ((x >= 80 && x < 85) || (x >= 115 && x < 120))) || (y >= 67 && y < 72))
				put_pixel(&img, x, y, 0x00FFFF00);
			x++;
		}
		y++;
	}
	//Print blue rectangle
	y = 20;
	while (y < 60)
	{
		x = 60;
		while(x < 100)
		{
			if ((y >= 20 && y < 25) || ((y >= 25 && y < 55) && ((x >= 60 && x < 65) || (x >= 95 && x < 100))) || (y >= 55 && y < 60))
				put_pixel(&img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
	//Print green rectangle
	y = 32;
	while (y < 72)
	{
		x = 40;
		while(x < 80)
		{
			if ((y >= 32 && y < 37) || ((y >= 37 && y < 67) && ((x >= 40 && x < 45) || (x >= 75 && x < 80))) || (y >= 67 && y < 72))
				put_pixel(&img, x, y, 0x0000FF00);
			x++;
		}
		y++;
	}
	//Print red rectangle
	y = 20;
	while (y < 60)
	{
		x = 20;
		while(x < 60)
		{
			if ((y >= 20 && y < 25) || ((y >= 25 && y < 55) && ((x >= 20 && x < 25) || (x >= 55 && x < 60))) || (y >= 55 && y < 60))
				put_pixel(&img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	
	mlx_loop(mlx);
}


void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}