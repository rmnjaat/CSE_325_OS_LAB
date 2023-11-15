#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

#include<fcntl.h>
#include<stdio.h>


int main(){

	int n,m,l ;
	n= open("hello.txt",O_RDWR);
	m=open("mango.txt",O_CREAT | O_RDWR , 0777 );
	
	l=lseek(n,0,SEEK_END);
	l=l/2;	
	char buff[l];
	lseek(n,0,SEEK_SET);
	read(n,buff,l);
	
	write(m,buff,l);
	
	}
