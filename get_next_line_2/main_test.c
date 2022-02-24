#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

/* -------------------------------------------------------------------------- */
/*                              PARTIE OBLIGATOIRE                            */
/* -------------------------------------------------------------------------- */

/* int	main(void)
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
		printf("GNL : %s", result);
		free(result);
	}
	close(fd);
	return (0);
} */

/* -------------------------------------------------------------------------- */
/*                                 PARTIE BONUS                               */
/* -------------------------------------------------------------------------- */

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	/* int		apercebolpb; */
	char	*result1 = NULL;
	char	*result2 = NULL;
	char	*result3 = NULL;
	
	fd1 = open("poeme_1.txt", O_RDONLY);
	printf("open1 : %d\n", fd1);
	if (fd1 == -1)
		return (0);
	fd2 = open("poeme_2.txt", O_RDONLY);
	printf("open2 : %d\n", fd2);
	if (fd2 == -1)
		return (0);
	fd3 = open("poeme_3.txt", O_RDONLY);
	printf("open3 : %d\n", fd3);
	if (fd3 == -1)
		return (0);
	while (1)
	{
		/* apercebolpb = 1;
		if () */
		result1 = get_next_line(fd1);
		printf("GNL1 : %s\n", result1);
		free(result1);
		result2 = get_next_line(fd2);
		printf("GNL2 : %s\n", result2);
		free(result2);
		result3 = get_next_line(fd3);
		printf("GNL3 : %s\n", result3);
		free(result3);
		/* if (apercebolpb = 1) */
		if (!result1 && !result2 && !result3)
			break ;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
