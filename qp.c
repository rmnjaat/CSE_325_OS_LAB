#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>

#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<pthread.h>
#include<string.h>
#include<semaphore.h>
#include<sys/shm.h>
#include<sys/ipc.h>


int main(){

int shmid = shmget((key_t)123,2048,0666 | IPC_CREAT);

void * shm = shmat(shmid,NULL,0);

pid_t p;

p=fork();

if(p==0){

char p[10];
strcpy(p,shm);

printf("Child get %s",p);

}

else{

char s[10]="Raman jaat";
strcpy(shm,s);

printf("Parent send %s",s);

}


}




/*
void * f1(void * s){

char * p= (char *)s;

printf("length is  %d ",strlen(p));

}

int main(){

pthread_t  p1;

char s[5] = "Raman";

char * pp=s;

pthread_create(&p1,NULL,f1,(void*)pp);

pthread_join(p1,NULL);



}

*/


/*

int main(){

char s[1];
char p[1];

int fd = open("hello.txt",O_CREAT |O_RDWR ,0777);

read(0,s,1);

while(s[0]!='@'){

	write(fd,s,1);
	read(0,s,1);
}


}


*/

/*
int main(){

mkdir("jp",0777);

DIR * dp;

struct dirent 	* s;

dp=opendir("jp");

int fd=open("./jp/rp",O_CREAT | O_RDONLY,0777);

while(NULL != (s=readdir(dp))){
	printf("%s",s->d_name);
}

}

*/
