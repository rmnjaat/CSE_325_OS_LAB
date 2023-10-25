#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void * fn(){

	sleep(5);
	
	printf("printing thread \n");
	
	printf("printing thread id %ld \n",pthread_self());

}

int main(){
	pthread_t thread_id;//var dec
	printf("before thread \n");
	
	//creating thread
	
	pthread_create(&thread_id,NULL,fn,NULL);
	
	printf("done creation\n");
	
	pthread_join(thread_id,NULL);

	printf("done main\n");


}
