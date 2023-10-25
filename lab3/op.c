#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){

	int n,m;
	int l=0;
	int wc=0;
	int c=0;
	
	char buff[1];
	n= open("apple.txt",O_RDWR | O_APPEND);
	//m= open("mango.txt", O_CREAT | O_RDWR | O_APPEND,0777);
	
	//printf("Enter 15 character");
		
	//printf("sucessfull");
	
	
	/*
	while(read(n,buff,1)>0){
		lseek(n,c,SEEK_SET);		
		if(buff[0]=='\n'){
			wc=wc+1;
			l++;
		}
		c=c+1;
		//write(m,buff,1);	
	}
	
	
	printf(" \n %d \n ",l);
	
	*/
	
	
	
	/*
	read(0,buff,1);
	
	while(buff[0]!='$'){
	
		write(n,buff,1);
		
		read(0,buff,1);	
	
	}
	
	*/
	
	

}
