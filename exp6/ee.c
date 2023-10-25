#include<unistd.h>
#include<stdio.h>
#include<pthread.h>


void * fn(void * i){

printf("hello inside thread \n");

printf("  %d  \n",(int *) i);


//int k=20;
//int * p2=&k;
  


pthread_exit(" exit \n");


}



int main(){
	
	pthread_t td1;
	
	void *res;
	int i = 10;
	
	int * p=&i;
	
	pthread_create(&td1,NULL,fn,(void *)i);
	
	pthread_join(td1,&res);
	
	
	printf("%s",res);
	
}

