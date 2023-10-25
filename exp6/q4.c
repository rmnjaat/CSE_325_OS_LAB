#include<stdio.h>
#include<pthread.h>

int arr[10] = {99, 22, 00, 88, 11, 100, 33, 66, 44, 55};


int arrfirsthalf[5], arrsecondhalf[5], finalarr[10];


void *final_merge_sort(){

	for(int i=0; i<5; i++){
		finalarr[i] = arrfirsthalf[i];
		finalarr[i+5] = arrsecondhalf[i];
	}
	
	printf("merged array is: ");
	for(int i=0; i<10; i++){
		printf("%d ", finalarr[i]);
	}
	printf("\n");
	
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			if(finalarr[i] < finalarr[j]){
				int temp = finalarr[i];
				finalarr[i] = finalarr[j];
				finalarr[j] = temp;
			}
		}
	}

	printf("final merged & Sorted array is: ");
	for(int i=0; i<10; i++){
		printf("%d ", finalarr[i]);
	}
	printf("\n");
	printf("\n");

	pthread_exit(NULL);
}


void *individual_sort(){
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			if(arrfirsthalf[i] < arrfirsthalf[j]){
				int temp = arrfirsthalf[i];
				arrfirsthalf[i] = arrfirsthalf[j];
				arrfirsthalf[j] = temp;
			}
			if(arrsecondhalf[i] < arrsecondhalf[j]){
				int temp = arrsecondhalf[i];
				arrsecondhalf[i] = arrsecondhalf[j];
				arrsecondhalf[j] = temp;	
			}
		}
	}
		
	pthread_exit(NULL);
}


int main()
{
	
	

		
	printf("array is: ");
	for(int i=0; i<10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	
	for(int i=0; i<5; i++){
		arrfirsthalf[i] = arr[i];
		arrsecondhalf[i] = arr[i+5];
	}
	
	
	
	pthread_t parent_thread;
	pthread_create(&parent_thread, NULL, individual_sort, NULL);
	pthread_join(parent_thread, NULL);
	
	printf(" first half sorted aray is: ");
	for(int i=0; i<5; i++){
		printf("%d ", arrfirsthalf[i]);
	}
	printf("\n");
	
	
	printf(" second half sorted aray is: ");
	for(int i=0; i<5; i++){
		printf("%d ", arrsecondhalf[i]);
	}
	printf("\n");
	
	pthread_create(&parent_thread, NULL, final_merge_sort, NULL);
	pthread_join(parent_thread, NULL);
	
	return 0;
} 
