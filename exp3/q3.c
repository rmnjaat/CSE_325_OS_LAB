#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>

int main(){
	
	int n;
	char c;
	
	n=open("apple.txt", O_RDWR );
	
	while(read(n,&c,1)>0){
		write(1,&c,1);	
		
	}	
	
}
