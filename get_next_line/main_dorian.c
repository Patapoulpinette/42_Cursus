
#include <stdio.h>
#include <stdlib.h>

#include "get_next_line.h"

int main() {
	char *line;
	while ((line = get_next_line(STDIN_FILENO))) {
		puts(line);
		free(line);
	}
}
