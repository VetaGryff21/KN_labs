#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <omp.h>

#define N 100000
int a[N], b[N];

int main()
{
    LARGE_INTEGER t1, t2, f;
    srand(time(NULL));
    int i, j;
    for (i = 0; i < N; i++) {
        a[i] = 0;
    }
    for (i = 0; i < N; i++) {
        b[i] = rand() % (N - 1);
    }
    int step = N / 4;
    QueryPerformanceCounter(&t1);
#pragma omp parallel for
    for (int k = 0; k < N; k += step)
        for (i = k; i < k + step; i++)
            for (j = 0; j < N; j++) {
                if (b[j] == i)
                    a[i]++;
            }


    QueryPerformanceCounter(&t2);
    QueryPerformanceFrequency(&f);
    double sec = (double)(t2.QuadPart - t1.QuadPart) / f.QuadPart;
    printf("a[0] = %d\n", a[0]);
    printf("it took %f seconds to execute \n", sec);
    return 0;
}
