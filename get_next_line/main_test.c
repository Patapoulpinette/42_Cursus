#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	buf[32];
	int		size;
	char	*result;

	fd = open("test.txt", O_RDONLY);
	printf("open : %d\n", fd);
	if (fd == -1)
		return (0);

/* 	puts("\n1ER ROUND\n");
	result = get_next_line(fd);
	printf("GNL : %s\n", result);
	free(result);

	puts("\n2EME ROUND\n");
	result = get_next_line(fd);
	printf("GNL : %s\n", result);
	free(result);

	puts("\n3EME ROUND\n");
	result = get_next_line(fd);
	printf("GNL : %s\n", result);
	free(result);

	puts("\n4EME ROUND\n");
	result = get_next_line(fd);
	printf("GNL : %s\n", result);
	free(result);

	puts("\n5EME ROUND\n");
	result = get_next_line(fd);
	printf("GNL : %s\n", result);
	free(result);

	puts("\n6EME ROUND\n");
	result = get_next_line(fd);
	printf("GNL : %s\n", result);
	free(result); */

	while (result)
	{
		result = get_next_line(fd);
		printf("GNL : %s\n", result);
		free(result);
	}

	close(fd);

	return (0);
}
