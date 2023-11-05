







#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>


pthread_mutex_t lock;
sem_t lockwriter;

int count = 1 ;
int countreader = 0;

int buff[5]={1,2,3,4,5};

void * f1();
void * f2();


int main()
{
	pthread_mutex_init(&lock,NULL);
	sem_init(&lockwriter,0,1);
	
	
	
	pthread_t reader[5],writer[5];
	
	for(int i=0;i<5;i++)
	{
	pthread_create(&reader[i],NULL,f1,NULL);
	}
	
	for(int i=0;i<5;i++)
	{
	pthread_create(&writer[i],NULL,f2,NULL);
	}
	
	
	for(int i=0;i<5;i++)
	{
	pthread_join(reader[i],NULL);
	}
	
	for(int i=0;i<5;i++)
	{
	pthread_join(writer[i],NULL);
	}
	
}


void * f1()
{
	pthread_mutex_lock(&lock);
	countreader++;
	if(countreader==1){
		sem_wait(&lockwriter);
	}
	
	pthread_mutex_unlock(&lock);
	printf("Reader read  %d \n",count);
	
	pthread_mutex_lock(&lock);
	countreader--;
	if(countreader==0){
		sem_post(&lockwriter);
	}
	
	pthread_mutex_unlock(&lock);
			
}

void * f2()
{

	sem_wait(&lockwriter);
	
	count*=2;

	printf("Writer modified count  to %d \n", count);

	sem_post(&lockwriter);

}





