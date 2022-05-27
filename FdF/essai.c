
#include "essai.h"

static int	press_key(int key, t_mlx_params *mlx_params)
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

static int	exit_program(void)
{
	dprintf(2, "exit with mouse\n");
	exit(0);
}


void bhm_line(t_mlx_params *mlx_params, int x1, int y1, int x2, int y2, int c)
{
	int x,y,dx,dy,dx1,dy1,px,py,xe,ye;

	dx = x2 - x1;
	dy = y2 - y1;
	dx1 = abs(dx);
	dy1 = abs(dy);
	px = 2 * dy1 - dx1;
	py = 2 * dx1 - dy1;
	if (dy1 <= dx1)
	{
		if (dx >= 0)
		{
			x = x1;
			y = y1;
			xe = x2;
		}
		else
		{
			x = x2;
			y = y2;
			xe = x1;
		}
		mlx_pixel_put(mlx_params->mlx, mlx_params->window, x, y, c);
		while (x < xe)
		{
			x = x + 1;
			if (px < 0)
			{
				px = px + 2 * dy1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
				{
					y = y + 1;
				}
				else
				{
					y = y - 1;
				}
				px = px + 2 * (dy1 - dx1);
			}
			mlx_pixel_put(mlx_params->mlx, mlx_params->window, x, y, c);
		}
	}
	else
	{
		if (dy >= 0)
		{
			x = x1;
			y = y1;
			ye = y2;
		}
		else
		{
			x = x2;
			y = y2;
			ye = y1;
		}
		mlx_pixel_put(mlx_params->mlx, mlx_params->window, x, y, c);
		while (y < ye)
		{
			y = y + 1;
			if (py <= 0)
			{
				py = py + 2 * dx1;
			}
			else
			{
				if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
				{
					x = x + 1;
				}
				else
				{
					x = x - 1;
				}
				py = py + 2 * (dx1 - dy1);
			}
			mlx_pixel_put(mlx_params->mlx, mlx_params->window, x, y, c);
		}
	}
}


static void	print_pixel_in_window(t_mlx_params *mlx_params)
{
	bhm_line(mlx_params, 50, 0, 50, 50, 16751103);
	bhm_line(mlx_params, 250, 0, 250, 50, 16751103);
	bhm_line(mlx_params, 450, 150, 450, 200, 16751103);
	bhm_line(mlx_params, 450, 150, 500, 150, 16751103);
	bhm_line(mlx_params, 500, 150, 500, 200, 16751103);
	bhm_line(mlx_params, 450, 200, 500, 200, 16751103);

	bhm_line(mlx_params, 0, 150, 50, 150, 16751103);
	bhm_line(mlx_params, 0, 350, 50, 350, 16751103);
	bhm_line(mlx_params, 150, 550, 200, 550, 16751103);
}

int	main(void)
{
	t_mlx_params	mlx_params;
//	t_algo_params	algo_params;

	mlx_params.x_win = 1500;
	mlx_params.y_win = 1200;
	mlx_params.mlx = mlx_init();
	mlx_params.window = mlx_new_window(mlx_params.mlx, mlx_params.x_win, mlx_params.y_win, "New window");
	//printing pixels in a window & draw line between pixels
	print_pixel_in_window(&mlx_params);
	//printing image in a window
//	mlx_params.img_path = "./ampoule.xpm";
//	mlx_params.img = mlx_xpm_file_to_image(mlx_params.mlx, mlx_params.img_path, &mlx_params.img_width, &mlx_params.img_height);
//	mlx_put_image_to_window(mlx_params.mlx, mlx_params.window, mlx_params.img, mlx_params.x_win / 3, mlx_params.y_win / 2);
//	mlx_params.img_path = "./leaf-1.xpm";
//	mlx_params.img = mlx_xpm_file_to_image(mlx_params.mlx, mlx_params.img_path, &mlx_params.img_width, &mlx_params.img_height);
//	mlx_put_image_to_window(mlx_params.mlx, mlx_params.window, mlx_params.img, mlx_params.x_win / 3, mlx_params.y_win / 4);
	//printing string in a window
//	mlx_string_put(mlx_params.mlx, mlx_params.window, mlx_params.x_win / 2, mlx_params.y_win / 2, 8765929, "hello");
	//do something when pressing key in a window
	mlx_key_hook(mlx_params.window, press_key, &mlx_params);
	//do something when pressing mouse button
	mlx_hook(mlx_params.window, 17, 1L << 5, exit_program, (void *)0);
	mlx_loop(mlx_params.mlx);
	dprintf(2, "end of main\n");
	return (0);
}

// compile with :
// cc -I/usr/local/include essai.c -L minilibx_macos -lmlx -framework OpenGL -framework AppKit && ./a.out