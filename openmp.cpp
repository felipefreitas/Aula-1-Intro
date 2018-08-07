#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    omp_set_num_threads(2);

    #pragma omp parallel for
    for(int i = 0; i < 10; i++)
    {
        printf("Thread ID: %d -- index: %d\n",
            omp_get_thread_num(), i);
    }
}