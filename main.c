#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char 	*str;
	int fd = open("sample.txt", O_RDONLY);
	printf("%lu\n", sizeof(t_list));
	printf("%lu\n", sizeof(t_buffer));
	printf("%d\t",get_next_line(fd, &str));
	printf("%s\n",str);
	free(str);
	printf("%d\t",get_next_line(fd, &str));
	printf("%s\n",str);
	free(str);
	get_next_line(55, &str);
	free(str);
	/*printf("%d\t",get_next_line(fd, &str));
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
	free(str);*/
	while (1)
	{
		(void) str;	
	}
}