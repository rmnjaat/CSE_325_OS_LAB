#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int arr[]={1,3,2,5,4,9,23,12,0};


struct ArrayInfo{

    int *array;
    
    size_t length;

}




void * fn(void * i){
	struct ArrayInfo *info=(struct  ArrayInfo *)i;
	
	
	





}





int main(){
	
	
	struct ArraInfo info;
	
	info.array = arr;
	info.length = 0;
	
	
	
	pthread_t td1;
	
	
	pthread_create(&td1,NULL,fn,(void *)& info;
	pthread_join
	
		
}

