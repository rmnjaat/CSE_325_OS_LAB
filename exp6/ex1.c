#include <stdio.h>

#include <pthread.h>

#include <unistd.h>

char *a;

void *fn()
{

    // sleep(5);
    printf("printing thread \n");
    printf("printing thread id %ld \n", pthread_self());

    // pthread_exit("hii hello");
    // int i=10;
    int *i = malloc(sizeof(int));

    *i = 10;
  
    // void* ii =&i;;
    
    pthread_exit(i);
    
}

int main()
{
    pthread_t thread_id; // var dec

    void *res;
    int *result;

    printf("before thread \n");
    // creating thread

    pthread_create(&thread_id, NULL, fn, NULL);
    printf("done creation\n");
    
    pthread_join(thread_id, &result);
    // printf("%s \n ",(char*)res);
    printf(" hiii  %d\n ", *result);
    
}
