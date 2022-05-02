

#include "minilibx_macos/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_mlx_params
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*img_path;
	int		img_width;
	int		img_height;
}				t_mlx_params;

int	press_key(int key, t_mlx_params *mlx_params)
{
	if (key == 8)
	{
		mlx_clear_window(mlx_params->mlx, mlx_params->window);
	}
	else if (key == 53)
	{
		mlx_destroy_window(mlx_params->mlx, mlx_params->window);
		exit(1);
	}
	else
	{
		dprintf(2, "key number : %d\n", key);
		write(1, "Hello\n", 6);
	}
	return (0);
}

void	print_pixel_in_window(t_mlx_params *mlx_params)
{
	int	x;
	int	y;

	x = 100;
	y = 100;
	mlx_params->mlx = mlx_init();
	mlx_params->window = mlx_new_window(mlx_params->mlx, 500, 500, "New window");
	while (x >= 100 && x <= 400)
	{
		mlx_pixel_put(mlx_params->mlx, mlx_params->window, x, y, 16751103);
		x++;
	}
	x = 100;
	y = 400;
	while (x >= 100 && x <= 400)
	{
		mlx_pixel_put(mlx_params->mlx, mlx_params->window, x, y, 16751103);
		x++;
	}
	x = 100;
	y = 100;
	while (y >= 100 && y <= 400)
	{
		mlx_pixel_put(mlx_params->mlx, mlx_params->window, x, y, 16751103);
		y++;
	}
	x = 400;
	y = 100;
	while (y >= 100 && y <= 400)
	{
		mlx_pixel_put(mlx_params->mlx, mlx_params->window, x, y, 16751103);
		y++;
	}
}

int	main(void)
{
	t_mlx_params	mlx_params;

	//printing pixels in a window
	print_pixel_in_window(&mlx_params);

	//printing image in a window
	mlx_params.img_path = "./leaf-1.xpm";
	mlx_params.img = mlx_xpm_file_to_image(mlx_params.mlx, mlx_params.img_path, &mlx_params.img_width, &mlx_params.img_height);
	mlx_put_image_to_window(mlx_params.mlx, mlx_params.window, mlx_params.img, 30, 0);

	//printing string in a window
	mlx_string_put(mlx_params.mlx, mlx_params.window, 225, 225, 49151, "hello");

	//do something when pressing key in a window
	mlx_key_hook(mlx_params.window, press_key, &mlx_params);

	mlx_loop(mlx_params.mlx);
	dprintf(2, "end of main\n");
}

// compile with :
// cc -I/usr/local/include essai.c -L minilibx_macos -lmlx -framework OpenGL -framework AppKit && ./a.out