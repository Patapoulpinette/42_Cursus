#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*result = NULL;

	fd = open("test.txt", O_RDONLY);
	printf("open : %d\n", fd);
	if (fd == -1)
		return (0);
	while (1)
	{
		result = get_next_line(fd);
		if (!result)
			break ;
		printf("GNL : %s\n", result);
		free(result);
	}
	result = get_next_line(fd);
	printf("GNL : %s\n", result);
	free(result);
	close(fd);
	return (0);
}
