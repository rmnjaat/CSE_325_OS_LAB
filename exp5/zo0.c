#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
	printf("hii\n");

	pid_t p=fork();
//	printf("%d  ",p);
//	printf("hello\n");


//	int pp=getpid();

//	printf("%d",pp);

		
	if(p==0){//child section
		
		printf("child id is %d  \n",getpid());
		printf("iam  child my pparent pid is %d\n",getppid());
	}
	else{//parent section
	
		printf("parent  id is %d \n",getpid());
		printf("my child is %d\n",p);
		sleep(10);
	}
	
	

}
