#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/**
 * @brief Factorial function
 * @param n number whose factoriel to be calc 
 * @return long factorial of the input
 * 
 * @par Requirement Traceability
 *  - @ref SRS_EXA_BOOT_01
 * @par Test Traceability
 *  - @ref TS_BOOT_00
 */
long fact(long n) {
    if (n < 1)
        return 1;
    return n * fact(n - 1);
}

void *task1(void *vargp)
{
    while(1)
    {
        //printf("Task 1 \n");
        usleep(100 * 1000);
    }
    
    return NULL;
}

void *task2(void *vargp)
{
    while(1)
    {
        //printf("Task 2 \n");
        usleep(200 * 1000);
    }
    
    return NULL;
}


/**
 * @brief Main entry of the app
 * 
 * @param a 
 * @return 0 if run completed w/o errors
 * @return int if run terminated with the error code
 */
int __mainvolkan()
{
    pthread_t thread_id_task1;
    pthread_t thread_id_task2;
    pthread_t thread_id2;
    printf("Before init\n");
    pthread_create(&thread_id_task1, NULL, task1, NULL);
    pthread_create(&thread_id_task2, NULL, task2, NULL);

    while(1)
    {
        printf("Main Loop \n");
        int c;
        c = getchar();
        if (c == 'q')
        {
            break;
        }
        
        //sleep(2);
    }
    
    printf("After Thread\n");
    exit(0);
}




/**
 * @brief Bootload function 
 * @par Details
 * This is the function which boots the application
 * @param a adress of the boatloader
 * @return true in case succesfull run
 * @return false in case boot failed
 * @par Requirement Traceability
 *  - @ref SRS_EXA_BOOT_01
 * @par Test Traceability
 *  - @ref TS_BOOT_00
 */
bool boot(int a)
{
    return true;
}