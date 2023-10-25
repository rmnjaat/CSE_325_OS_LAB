#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){

	pid_t gp=getpid();
	
	pid_t p=fork();
	
	
	if(p==0){
		pid_t pp=fork();
		
		if(pp==0){
			printf("Hii I am P3 ID is %d\n",getpid());
			printf("Hii I am P3 Parent ID is %d\n",getppid());
			printf("Hii I am P3 GrandParent ID is %d\n",gp);
		
		
		}
		
		
		else{
			wait(NULL);
			printf("Hii I am P2 ID is %d\n",getpid());
			printf("Hii I am P2 Parent ID is %d\n",getppid());
		}
		
		
	
	}
	
	
	else{
		wait(NULL);
		printf("Hii I am P1 ID is %d\n",getpid()); 
	}

}
