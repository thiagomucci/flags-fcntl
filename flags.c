#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
	if(argc != 2)
	{
		write(STDERR_FILENO, "try: ./prog <file>\n", sizeof("try: ./prog <file>\n") -1);
	}
	int fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if(fd < 0)
	{
		perror("open\n");
		exit(1);
	}
	int flag = fcntl(fd, F_GETFL);
	if(flag < 0)
	{
		perror("fcntl\n");
		exit(1);
	}
	switch(flag & O_ACCMODE)
	{
    case O_RDONLY:
        printf("read only\n");
        break;

    case O_WRONLY:
        printf("write only\n");
        break;

    case O_RDWR:
        printf("read and write\n");
        break;
	}
	if(flag & O_APPEND)
	{
		printf("append mode\n");
	}
	if(flag & O_NONBLOCK)
	{
		printf("nonblock mode\n");
	}
	if((close(fd) < 0))
	{
		perror("close\n");
		exit(1);
	}
	return 0;
}
