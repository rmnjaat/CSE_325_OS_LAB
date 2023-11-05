#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

#include<semaphore.h>



int shared =1;

sem_t s;


void * f1();
void * f2();

int main()
{
	sem_init(&s,0,1);
	
	
	pthread_t p1,p2;
	
	pthread_create(&p1,NULL,f1,NULL);
	pthread_create(&p2,NULL,f2,NULL);
	
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	
	printf("\n final valur is : %d",shared);
	
	sem_destroy(&s);
		
	
	
}


void *f1()
{
	printf("p1 trying to acess\n");
	
	sem_wait(&s);
	
	printf("p1 got \n");
	int loc=shared;
	
	loc++;
	
	sleep(3);
	
	shared=loc;
	
	sem_post(&s);
	
	printf(" p1 released \n");
	
	printf("  p1  :%d  \n",shared);
	
	return NULL;
} 




void * f2()
{

printf("p2 trying to acess\n");
	
	sem_wait(&s);
	
	printf("p2 got \n");
	
	int loca=shared;
	
	loca--;
	
	sleep(3);
	
	shared=loca;
	
	sem_post(&s);
	
	printf(" p2 released \n");
	
	printf("  p2  :%d  \n",shared);
	
	return NULL;

}


