#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>



void * fn (void * i){

char * msg;
msg= (char *) i;


printf("%s\n",msg);



}
int main(){


pthread_t  p1,p2;

char * s1="raman";
char * s2="hjdfv";

int ret1,ret2;

ret1=pthread_create(&p1,NULL,fn,(void *) s1);
ret2=pthread_create(&p2,NULL,fn,(void *) s2);

printf("%d \n %d \n",ret1,ret2);

pthread_join(p1,NULL);
pthread_join(p2,NULL);






}
