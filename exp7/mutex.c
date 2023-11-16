/*
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


pthread_mutex_t l;



int shared=1;


void* f1();
void* f2();

int main(){
	
	pthread_mutex_init(&l,NULL);
	pthread_t t1,t2;
	
	pthread_create(&t1,NULL,f1,NULL);
	pthread_create(&t2,NULL,f2,NULL);
	
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	
	printf("  final value in main : %d \n",shared);
	return 0;

}

void* f1(){
	
	printf("t1 trying to  get  enter in CS \n");
	
	
	
	pthread_mutex_lock(&l);
	
	printf(" t1 got access \n");
	int x;
	x=shared;
	
	x++;
	
	sleep(3);
	
	shared=x;
	
	pthread_mutex_unlock(&l);
	printf("t1 released lock\n");
	
	printf("Value inside t1  :  %d \n",shared);



}

void* f2(){

	printf("t2 trying to  get  enter in CS \n");
	
	pthread_mutex_lock(&l);
	
	printf(" t2 got access \n");
	
	int y;
	
	y=shared;
	
	y--;
	
	sleep(3);
	
	shared=y;
	
	pthread_mutex_unlock(&l);
	
	printf("t2 released lock\n");
	
	printf("Value inside t2  :  %d \n",shared);

}
*/


#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t  l;

int shared =1;

void*f1();

void*f2();

int main(){

	pthread_mutex_init(&l);
		
	pthread_t p1,p2;
	
	pthread_create(&p1,NULL,f1,NULL);
	pthread_create(&p2,NULL,f2,NULL);
	
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	
	printf("Final value of shared var is %d :",shared);
	
}

void * f1(){
	
	printf("\n p1 trying to access \n");
	
	pthread_mutex_lock(&l);
	
	printf(" \n p1 got access \n");
	
	int x=shared;

	x++;
	
	sleep(3);
	
	shared=x;
	
	pthread_mutex_unlock(&l);
	
	printf(" \n p1 releasing  lock \n");
	
}

void * f2(){
	
	printf("\n p2 trying to access \n");
	
	pthread_mutex_lock(&l);
	
	printf(" \n p2 got access \n");
	
	int y=shared;
	
	y--;
	
	sleep(3);
	
	shared=y;
	
	pthread_mutex_unlock(&l);
	
	printf(" \n p2 releasing  lock \n");
	
}


































