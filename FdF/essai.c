
#include "fdf.h"

int	press_key(int key, t_mlx_params *mlx_params)
{
	if (key == 8)
		mlx_clear_window(mlx_params->mlx, mlx_params->window);
	else if (key == 53)
	{
		mlx_destroy_window(mlx_params->mlx, mlx_params->window);
		dprintf(2, "exit with ESC\n");
		exit(0);
	}
	else
		dprintf(2, "key number : %d\n", key);
	return (0);
}

int	exit_program(void)
{
	dprintf(2, "exit with mouse\n");
	exit(0);
}

void	print_pixel_in_window(t_mlx_params *mlx_params)
{
	int	x;
	int	y;

	x = 100;
	y = 100;
	while (x >= 100 && x <= mlx_params->x_win - 100)
	{
		mlx_pixel_put(mlx_params->mlx, mlx_params->window, x, y, 16751103);
		x++;
	}
	x = 100;
	y = mlx_params->y_win - 100;
	while (x >= 100 && x <= mlx_params->x_win - 100)
	{
		mlx_pixel_put(mlx_params->mlx, mlx_params->window, x, y, 16751103);
		x++;
	}
	x = 100;
	y = 100;
	while (y >= 100 && y <= mlx_params->y_win - 100)
	{
		mlx_pixel_put(mlx_params->mlx, mlx_params->window, x, y, 16751103);
		y++;
	}
	x = mlx_params->x_win - 100;
	y = 100;
	while (y >= 100 && y <= mlx_params->y_win - 100)
	{
		mlx_pixel_put(mlx_params->mlx, mlx_params->window, x, y, 16751103);
		y++;
	}
}

int	main(void)
{
	t_mlx_params	mlx_params;

	mlx_params.x_win = 700;
	mlx_params.y_win = 500;
	mlx_params.mlx = mlx_init();
	mlx_params.window = mlx_new_window(mlx_params.mlx, mlx_params.x_win, mlx_params.y_win, "New window");

	//printing pixels in a window
	print_pixel_in_window(&mlx_params);

	//printing image in a window
	mlx_params.img_path = "./ampoule.xpm";
	mlx_params.img = mlx_xpm_file_to_image(mlx_params.mlx, mlx_params.img_path, &mlx_params.img_width, &mlx_params.img_height);
	mlx_put_image_to_window(mlx_params.mlx, mlx_params.window, mlx_params.img, mlx_params.x_win / 3, mlx_params.y_win / 2);

	mlx_params.img_path = "./leaf-1.xpm";
	mlx_params.img = mlx_xpm_file_to_image(mlx_params.mlx, mlx_params.img_path, &mlx_params.img_width, &mlx_params.img_height);
	mlx_put_image_to_window(mlx_params.mlx, mlx_params.window, mlx_params.img, mlx_params.x_win / 3, mlx_params.y_win / 4);

	//printing string in a window
	mlx_string_put(mlx_params.mlx, mlx_params.window, mlx_params.x_win / 2, mlx_params.y_win / 2, 8765929, "hello");

	//do something when pressing key in a window
	mlx_key_hook(mlx_params.window, press_key, &mlx_params);

	//do something when pressing mouse button
	mlx_hook(mlx_params.window, 17, 1L << 5, exit_program, (void *)0);

	mlx_loop(mlx_params.mlx);
	dprintf(2, "end of main\n");
}

// compile with :
// cc -I/usr/local/include essai.c -L minilibx_macos -lmlx -framework OpenGL -framework AppKit && ./a.out