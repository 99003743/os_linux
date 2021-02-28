#include <stdio.h> 
#include <pthread.h> 
 
#define MAX 16 
  

#define MAX_THREAD 4 
  
int x[] = { 12, 52, 27, 110, 112, 54, 65, 9, 20, 72, 25, 37, 30, 24, 10, 22 }; 
int sum[4] = { 0 }; 
int part = 0; 
  int i;
void* sum_array(void* arg) 
{
    int thread_part = part++; 
    printf("\n thread part:%d",thread_part);
    for (i = thread_part * (MAX / 4); i < (thread_part + 1) * (MAX / 4); i++) 
        sum[thread_part] += x[i];
        printf("\nindex value:%d",i-1);
}
int main() 
{ 
  
    pthread_t threads[MAX_THREAD]; 
    for (int i = 0; i < MAX_THREAD; i++) 
        pthread_create(&threads[i], NULL, sum_array, (void*)NULL); 
    for (int i = 0; i < MAX_THREAD; i++) 
        pthread_join(threads[i], NULL); 
    int total_sum = 0; 
    for (int i = 0; i < MAX_THREAD; i++) 
        total_sum += sum[i]; 
  
    printf("\nsum of array: %d",total_sum);
  
    return 0; 
} 
