#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <omp.h>

#define N 100000000
int a[N], b[N];

int main()
{
    LARGE_INTEGER t1, t2, f;
    srand(time(NULL));
    int i;
    for (i = 0; i < N; i++) {
        a[i] = 0;
    }
    for (i = 0; i < N; i++) {
        b[i] = rand() % (N-1);
    }

    QueryPerformanceCounter(&t1);
    #pragma omp parallel
    for (i = 0; i < N; i++) {
    #pragma omp atomic
        a[b[i]]++;
    }

    QueryPerformanceCounter(&t2);
    QueryPerformanceFrequency(&f);
    double sec = (double)(t2.QuadPart - t1.QuadPart) / f.QuadPart;
    printf("it took %f seconds to execute \n", sec);
    return 0;
}
