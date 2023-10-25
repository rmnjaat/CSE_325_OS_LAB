#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>


int main(){
	pid_t p1=getpid();
	
	pid_t p2=fork();
	
	
	
	if(p2==0){
		
		pid_t p3=fork(); 
		
		if(p3==0){
			printf("I am p3 id is  :%d \n",getpid());
			printf("I am p3  parent id is  :%d \n",getppid());
		}
	
		else{
			wait(NULL);
			printf("I am p2 id is  :%d \n",getpid());
			printf("I am p2  parent id is  :%d \n",getppid());
		}
		
		
	}
	
	
	else {
		
		wait(NULL);

		pid_t p4=fork();
		if(p4==0){
		
			pid_t p5=fork();
			
			
			
			if(p5==0){		
				printf("I am p5 id is  :%d \n",getpid());
				
				printf("I am p5  parent id is  :%d \n",getppid());
			}
			
			else{
			
			printf("I am p4 id is  :%d \n",getpid());
			printf("I am p4  parent id is  :%d \n",getppid());
			
			sleep(20);//stimmulate p5 as a zombie process
			}
		}
		else{
		//stimulating p4 as a orphan
		printf("I am p1 id is  :%d \n",getpid());
		}
			
	}



}



