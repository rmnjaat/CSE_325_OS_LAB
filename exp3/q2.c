#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

	int n,m;

	char buff[1];
	n= open("apple.txt", O_CREAT | O_RDWR,0777);


	read(0,buff,1);
	
	while(buff[0]!='$'){
	
		write(n,buff,1);
		
		read(0,buff,1);	
	
	}
	
}
