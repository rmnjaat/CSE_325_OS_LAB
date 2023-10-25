#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>



int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	
		pid_t p=fork();
		
		if(p == -1) {
         
            		printf("Fork failed!\n");
            		return 1;
        
        	} 
        	else if(p == 0) {
         
            		
		        printf("Child process created: %d\n", getpid()		);
          
        	}
        	else{
        	wait(NULL);
        	
        	}		
	}

}


