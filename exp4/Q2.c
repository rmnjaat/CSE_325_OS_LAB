#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<dirent.h>

int main()
{
	struct dirent *dptr;
	
	int a = mkdir("Dir_1", 0777);
	int b = mkdir("Dir_Copy", 0777);
	
	int fd1 = open("Dir_1/original.txt", O_CREAT|O_RDWR, 0777);
		
	char c[1000];
	
	printf("input: \n");
	scanf("%[^\n]s", c);
	printf(" \n");
	
	int size=0;
	
	for(int i=0;i<100;i++)
	{
		if(c[i]=='\0'){
			break;
		}
		
		else{
			size++;
		}
	}
	
	write(fd1, c, size);
	
	DIR *dp = opendir("Dir_Copy");
	
	int no_of_files=-2;
	
	while(NULL != (dptr=readdir(dp)))
	{
		no_of_files++;
	}
	
	int fd2 = open("Dir_Copy/original_Copy.txt", O_CREAT | O_RDWR, 0777);
	
	write(fd2, c, size);

	DIR *dp1 = opendir("Dir_Copy");
	
	int new_no_of_files=-2;
	
	while(NULL != (dptr=readdir(dp1)))
	{
		new_no_of_files++;	
	}
	
	return 0;
}
