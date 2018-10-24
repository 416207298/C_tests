//C file
/***********************************************
#
#      Filename: main.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 把标准输出流重定向为文件，然后执行exec
#        Create: 2018-09-25 14:07:15
#**********************************************/
#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("need one argument[filename]\n");
		exit(1);
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		exit(1);	
	}
	dup2(fd, STDIN_FILENO);
	close(fd);

	execl("./toupper", "toupper", "testfile", "NULL");
	perror("exec error");
	exit(1);
}