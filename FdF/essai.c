

#include "minilibx_macos/mlx.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*window;
	int		x;
	int		y;

	x = 1;
	y = 1;
	mlx_ptr = mlx_init();
	window = mlx_new_window(mlx_ptr, 500, 500, "New window");
	while (x > 0 && x < 500 && y > 0 && y < 500)
	{
		mlx_pixel_put(mlx_ptr, window, x, y, 16751103);
		x++;
		y++;
	}
	x = 499;
	y = 1;
	while (x > 0 && x < 500 && y > 0 && y < 500)
	{
		mlx_pixel_put(mlx_ptr, window, x, y, 16751103);
		x--;
		y++;
	}
	mlx_string_put(mlx_ptr, window, 225, 50, 49151, "hello");
	mlx_loop(mlx_ptr);
}

// cc -I/usr/local/include essai.c -L minilibx_macos -lmlx -framework OpenGL -framework AppKit && ./a.out