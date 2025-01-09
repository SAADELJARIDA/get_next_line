#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <string.h>
int main()
{
	int fd = open("salam.txt",O_RDONLY);
	char *a;
	int i =4;
	while (i--) {
		a = get_next_line(fd);
		printf("%s",a);
		free(a);
	}
}

