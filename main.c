#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char 	*str;
	int fd = open("sample.txt", O_RDONLY);
	printf("%d\t",get_next_line(fd, &str));
	printf("%s\n",str);
	free(str);
	printf("%d\t",get_next_line(fd, &str));
	printf("%s\n",str);
	free(str);
	printf("%d\t",get_next_line(fd, &str));
	printf("%s\n",str);
	free(str);
	printf("%d\t",get_next_line(fd, &str));
	printf("%s\n",str);
	free(str);
	printf("%d\t",get_next_line(fd, &str));
	printf("%s\n",str);
	free(str);
	printf("%d\t",get_next_line(fd, &str));
	printf("%s\n",str);
	free(str);
	printf("%d\t",get_next_line(fd, &str));
	printf("%s\n",str);
	free(str);
	printf("%d\t",get_next_line(fd, &str));
	printf("%s\n",str);
	free(str);
	printf("%d\t",get_next_line(fd, &str));
	printf("%s\n",str);
	free(str);
	printf("%d\t",get_next_line(fd, &str));
	printf("%s\n",str);
	free(str);
}