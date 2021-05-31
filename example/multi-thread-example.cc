#include "rlog.h"
#include <unistd.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>

int64_t get_current_millis(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (int64_t)tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void* thdo(void* args)
{
    for (int i = 0;i < 1e3; ++i)
    {
        RLOG_ERROR("my number is number my number is my number is my number is my number is my number is my number is %d", i);
        SERVICE_LOG_ERROR("my number is number my number is my number is my number is my number is my number is my number is %d", i);

        
        // log(ERROR, "my number is number my number is my number is my number is my number is my number is my number is %d", i);
    }
}

int main(int argc, char** argv)
{
    int64_t start = get_current_millis();
    LOG_INIT("log", "scanner", 5);
    SEVICE_LOG_INIT("log", "dp2_service", 3);
    pthread_t tids[5];
    for (int i = 0;i < 5; ++i)
    	pthread_create(&tids[i], NULL, thdo, NULL);

    for (int i = 0;i < 5; ++i)
	    pthread_join(tids[i], NULL);
    int64_t end = get_current_millis();
    printf("rlogcost:%u\n", (end -start));
}
