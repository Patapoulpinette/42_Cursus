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

	/*	On ouvre le fichier : en fait on recupere un fd sur le fichier*/
	fd = open("test.txt", O_RDONLY);
	printf("open : %d\n", fd);
	if (fd == -1)
		return 0;

	/*	on passe a read : */
/* 	size = read (fd, buf, 32);
	printf("size : %d\n", size); */

	result = get_next_line(fd);
	printf("GNL : %s\n", result);
	free(result);

/* 	buf[size] = 0;
	printf("buffer : %s\n", buf); */

	/*	Ne pas oublier de libérer fd */
	close(fd);

	return (0);
}