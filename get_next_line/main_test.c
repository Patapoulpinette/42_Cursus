#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int		fd;
	char	buf[32];
	int		size;
 
	/*	On ouvre le fichier : en fait on recupere un fd sur le fichier*/
	fd = open("test.txt", O_RDONLY);
	printf("open : %d\n", fd);
	if (fd == -1)
		return 0;
	
	/*	on passe a read : */
/* 	size = read (fd, buf, 32);
	printf("size : %d\n", size); */
	
	printf("GNL : %s\n", get_next_line(fd));
	/*
		On raoute un '\0' à la fin de la chaine lue, pour être sur d'avoir une chaine de caractères valide.
		size correspondant a l'index du dernier caractere du buffer + 1.
		Ceci est utile si on veut utiliser la chaine de caractères dans une fonction comme strcmp() ou printf()
	*/

/* 	buf[size] = 0;
	printf("buffer : %s\n", buf); */

	/*	Ne pas oublier de libérer fd */
	close(fd);

	return 0;
}