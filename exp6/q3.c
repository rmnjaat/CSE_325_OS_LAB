

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct ArrayInfo {
    int *array;
    size_t length;
    int maxx;
    int minn;
};

void *calculateArrayLength(void *arg) {
    struct ArrayInfo *info = (struct ArrayInfo *)arg;
    
    int *array = info->array;
    size_t length = 0;

    while (array[length] != 0) {
        length++;
    }

    info->length = length;
    
    return NULL;
}

void *calculateArrayMin(void *arg) {
    struct ArrayInfo *info = (struct ArrayInfo *)arg;
    
    int *array = info->array;
    int min = array[0];
    
    int i = 1;

    while (array[i] != 0) {
        if (array[i] < min) {
            min = array[i];
        }
        i++;
    }

    info->minn = min;
    
    return NULL;
}

void *calculateArrayMax(void *arg) {
    struct ArrayInfo *info = (struct ArrayInfo *)arg;
    
    int *array = info->array;
    int max = array[0];
    
    int i = 1;

    while (array[i] != 0) {
        if (array[i] > max) {
            max = array[i];
        }
        i++;
    }

    info->maxx = max;
    
    return NULL;
}

int main() {

		// note 0 is a terminator
    int myArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 0}; 
    pthread_t thread;
    struct ArrayInfo info;

    info.array = myArray;
    info.length = 0;

    pthread_create(&thread, NULL, calculateArrayLength, (void *)&info); 
    pthread_join(thread, NULL);

    pthread_t thread2;
    pthread_create(&thread2, NULL, calculateArrayMin, (void *)&info); 
    pthread_join(thread2, NULL);

    pthread_t thread3;
    pthread_create(&thread3, NULL, calculateArrayMax, (void *)&info); 
    pthread_join(thread3, NULL);

    size_t arrayLength = info.length;

    printf("Array length: %zu\n", arrayLength);
    printf("Array min: %d\n", info.minn);
    printf("Array max: %d\n", info.maxx);

    return 0;
}

