#include<stdio.h>

#include<pthread.h>

#include<stdlib.h>

struct s1{
	int a;
	int b;

};

void *fn(void * i){

	struct s1 *o;
	o=(struct s1 *)i;

	int * t=malloc(sizeof(int));

	*t=o->a+o->b;
	printf("%d",o->a+o->b);

	pthread_exit( t);

}

int main(){

	pthread_t p;

	struct s1 obj;

	obj.a=8;
	obj.b=9;

	int * res;
	pthread_create(&p,NULL,fn,(void*)&obj);
	pthread_join(p,&res);

	printf(" sum is %d  ",*res);

}
