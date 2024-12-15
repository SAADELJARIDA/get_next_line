#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <string.h>
int main()
{
	int fd = open("saad.txt",O_RDONLY);
	char *a;
	int i =2;
	while (i--) {
		a = get_next_line(fd);
		printf("%s",a);
		free(a);
	}
}

