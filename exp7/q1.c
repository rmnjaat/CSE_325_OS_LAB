#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include <time.h>


pthread_mutex_t  lock;

int  size=5;

int buffe[5];


int last_index=-1;




void * f1(); //producer fn

void * f2();  /// consumer fn

int main(){

	pthread_t prod,cons;
	
	pthread_mutex_init(&lock,NULL);
	pthread_create(&prod,NULL,f1,NULL);
	pthread_create(&cons,NULL,f2,NULL);

	pthread_join(prod,NULL);
	
	
	
	pthread_join(cons,NULL);
	
}

void * f1(){
	
	printf("Producer is requesting to produce \n");
	
	if(last_index==size-1){
	
		printf("Producer cannot produce \n ");
		
	}
	
	else{
		pthread_mutex_lock(&lock);
		
		printf("Producer locked \n");
		
		printf("Producer is producing ");
		
		
		//sleep(5);
		
		while(last_index != size-1){
				int temp=rand() % 10;
				
				buffe[last_index+1]=temp;
				
				last_index++;
					
		}
		
		
		printf("producer completed its production \n");
		
		pthread_mutex_unlock(&lock);
		
		printf("Producer released \n");
		
		
	}



}

void * f2(){
	
	printf(" consummer requesting for data \n");
	
	
	
	if(last_index<0){
		
		printf("consumer can't consume ,bcz buffer is empty \n");
	
	}
	else{
	
		printf("Curret buff is -> ");
	
		for(int i=0;i<size;i++){
		
			printf("%d ",buffe[i]);	

		}
		
		printf("\n");
	
		pthread_mutex_lock(&lock);
		
		printf("Consumer locked \n");
			
		printf(" consumer is consuming data \n");
		
		printf("Consumer consumed  %d \n",buffe[last_index]);
		
		last_index =last_index-1;
		
		pthread_mutex_unlock(&lock);
		
		printf("Consumer released \n");
			
		
	}
}
