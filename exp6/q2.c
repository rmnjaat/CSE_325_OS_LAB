
#include<string.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>




void * fn( void * s){

	char * p ;
	p = (char *) s;
	
	printf("%d",strlen(p));
	
}

int main(){

	pthread_t pi;

	char s[10]={"asdfghjkl"};
	
	char *pe=s;
	
	pthread_create(&pi,NULL,fn,(void *) pe);

	pthread_join(pi,NULL);
	
	

}
