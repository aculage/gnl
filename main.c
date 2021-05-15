#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char 	*str;
	int fd1 = open("sample.txt", O_RDONLY);
	int fd2 = open("sampl2.txt", O_RDONLY);
	int fd3 = open("sampl3.txt", O_RDONLY);

	printf("%lu\n", sizeof(t_list));
	printf("%lu\n", sizeof(t_buffer));
	printf("%d\t",get_next_line(fd1, &str));
	printf("%s\n",str);
	free(str);
	printf("%d\t",get_next_line(fd2, &str));
	printf("%s\n",str);
	free(str);
	get_next_line(55, &str);
	free(str);
	printf("%d\t",get_next_line(fd3, &str));
	printf("%s\n",str);
	free(str);
	printf("%d\t",get_next_line(fd3, &str));
	printf("%s\n",str);
	free(str);
	/*
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
	free(str);*/
	while (1)
	{
		(void) str;	
	}
}