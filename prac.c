#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

int main(){


int shmid= shmget((key_t)123,2048,0666 | IPC_CREAT);


void * shm;
shm=shmat(shmid,NULL,0);

char buff[10]="Raman jaat";

strcpy(shm,buff)

}


/*
int main() {
    int fd,k;
    char buff[10] = "Raman jaat";
    char b[20];  // Make sure the buffer is large enough to hold the string

    mkfifo("jk", 0666);

    pid_t p;
    p = fork();

    if (p == 0) {
        // Child process
     
     	
        fd = open("jk", O_WRONLY);
        write(fd, buff, sizeof(buff));
        printf("written %s \n",buff);
        close(fd);
    } else {
      
	printf("wasdfb\n");
        k= open("jk", O_RDONLY);
        printf("wasdfb");
        read(k, b, 10);
        close(k);
        printf("info received: %s\n", b);
        
      
    }

    return 0;
}

*/

/*
int main(){

int fd[2];
pid_t pid;
char buff[10]="Raman jaat";

char b[10];

pipe(fd);

pid=fork();

if(pid==0){

close(fd[0]);
write(fd[1],buff,10);

printf(" child write into pipe  %s \n",buff);

}

else{

close(fd[1]);

read(fd[0],b,10);

printf("read by parent  %s \n",b);


}


}

*/



/*
sem_t s;

int shared=0;

void * f1();
void * f2();

int main(){

pthread_t p1,p2;

sem_init(&s,0,1);

pthread_create(&p1,NULL,f1,NULL);
pthread_create(&p2,NULL,f2,NULL);

pthread_join(p1,NULL);
pthread_join(p2,NULL);

printf(" main   %d \n ",shared);

}

void * f1(){

sem_wait(&s);
int x=shared;
x++;
sleep(2);
shared=x;

sem_post(&s);

printf("p1 %d ",shared);
	}

void * f2(){

sem_wait(&s);
int y=shared;
y-- 	;
sleep(2);
shared=y;

sem_post(&s);

printf("p2 %d ",shared);

	} 

*/

/*
struct s{
int a;
};

void * fn(struct s * rm){

struct s * p= (struct s *)rm;
printf("hello moto , motrola  %d \n",p->a);

int *i= malloc(sizeof(int));

*i=p->a*3;

return  (void *) i;

}

int main()
{
	pthread_t p1,p2 ;
	
	struct s o;
	
	o.a=50;
	
	pthread_create(&p1,NULL,fn,(void*)&o);
	
	
	void * res;
	pthread_join(p1,&res);
	
	printf(" returned value is  %d ", *(int *)res);	

}


*/


/*
int main(){
	pid_t pid;
	pid=getpid();
	pid=fork();
	
	if(pid==0)
	{ 
		printf("child process %d  \n\n",getpid());
		printf("parent process %d \n\n",getppid());
	}
	
	else
	{
		sleep(10);
		printf("current process pid iis   %d \n\n",getpid());
	}
	
	
}


*/
