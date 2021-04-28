#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char 	*str;
	int fd = open("sample.txt", O_RDONLY);
	get_next_line(fd, &str);
	printf("%s", str);
}