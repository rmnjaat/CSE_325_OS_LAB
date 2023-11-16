#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
int main(){
 	DIR * dp;
 	struct dirent *dptr;
 	int b = mkdir("../Desktop/Di",0777);
 	dp = opendir("../Desktop/Di");
 	
 	//FILE * fp= fopen("../Desktop/Di/hello.txt","w");
 
	while(NULL != (dptr = readdir(dp))){
 	
 	printf("%s  \n",dptr->d_name);
 	printf("%d  \n",dptr->d_type);
 	//printf("%d  \n",dptr->d_ino);
 	
 	}  
 	
 	
 	return 0;


}
