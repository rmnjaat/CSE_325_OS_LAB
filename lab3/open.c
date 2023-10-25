#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>


int main(){

	int n;
	
	char arr[20];
	
	n=open("apple.txt",);
	
	int m;
	
	m= read(0,arr,10);
		
	write(n,arr,m);
	
	printf("  \n file discripter value %d :\n character appended : \n",n);
	
	//write(1,arr,m);
	
	printf("  \n number of char appended  %d \n",m);
	
	printf("  sucessfull \n ");
	
	
	
}
