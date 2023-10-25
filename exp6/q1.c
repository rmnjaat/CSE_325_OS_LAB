
#include<string.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>

struct s{
	char  s1[100];
	char  s2[100];
	char s3[200];
};



void* fn(void * i){

	struct s *oo=(struct s *)i;


 	strcat(oo->s3,oo->s1);
 	
 	strcat(oo->s3,oo->s2);
	
	 
}


int main(){


	pthread_t  pid;
	
	struct s o;
	//o.s1="abc";
	//o.s2="def";
	strcpy(o.s1,"abc");
	strcpy(o.s2,"def");
	
	pthread_create(&pid,NULL ,fn ,(void*)&o);
	
	
	void * res;
	
	pthread_join(pid,NULL);

	
	printf("%s \n" ,o.s3);
	
	
}




