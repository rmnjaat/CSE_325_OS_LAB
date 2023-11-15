#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

#include<dirent.h>



/*
int main(){
int fd;
fd = open("rmn.txt",O_RDONLY,777);
printf("\n\n%d file descripter value \n\n",fd);
char buff[10];
int m=lseek(fd,2,SEEK_CUR);
printf(" \n \n c ur po is %d  \n \n",m); 
read(fd,buff,10);
write(1,buff,10);
}*/

int main(){
	int n=mkdir("rmn",0777);
	
	DIR * dp;
	struct  dirent *dptr;
	
	dp=opendir("exp4");
	
	while(NULL!=(dptr=readdir(dp))){
	printf("%s",dptr->d_name);
	}
		
}
