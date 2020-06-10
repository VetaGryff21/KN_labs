
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#define N 100000000

int main()
{

    float *a, *b, *c, sum = 0;
    LARGE_INTEGER t1, t2, f;
    srand(time(NULL));
    QueryPerformanceCounter(&t1);

    a = malloc(N * sizeof(float));
    b = malloc(N * sizeof(float));
    c = malloc(N * sizeof(float));
    int i;
    for (i = 0; i < N; i++) {
        a[i] = 1;
        b[i] = 1;
    }

    for (i = 0; i < N; i++) {
        c[i] = a[i] * b[i];
    }

    for (i = 0; i < N; i++) {
        sum += c[i];
    }
    QueryPerformanceCounter(&t2);
    QueryPerformanceFrequency(&f);

    double sec = (double)(t2.QuadPart - t1.QuadPart) / f.QuadPart;
    printf("sum = %f \n", sum);
    printf("it took %f seconds to execute \n", sec);
    return 0;
}
