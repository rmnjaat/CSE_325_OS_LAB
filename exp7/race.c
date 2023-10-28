#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


int shared=1;


void* f1();
void* f2();

int main(){

	pthread_t t1,t2;
	
	pthread_create(&t1,NULL,f1,NULL);
	pthread_create(&t2,NULL,f2,NULL);
	
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	
	printf("  final value in main : %d \n",shared);
	return 0;

}

void * f1(){
	
	int x;
	x=shared;
	
	x++;
	
	sleep(3);
	
	shared=x;
	
	
	printf("Value inside t1  :  %d \n",shared);



}

void * f2(){
	
	int y;
	y=shared;
	
	y--;
	
	sleep(3);
	
	shared=y;
	
	
	printf("Value inside t2  :  %d \n",shared);



}