#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <mkl.h>

#define N 100
#define M 10000
int main()
{
    LARGE_INTEGER t1, t2, f;
    srand(time(NULL));
    double** a = (double**)malloc(N * sizeof(double*));
    double** b = (double**)malloc(M * sizeof(double*));
    double** sum = (double**)malloc(N * sizeof(double*));

    for (int i = 0; i < N; i++) {
        a[i] = (double*)malloc(M * sizeof(double));
        sum[i] = (double*)malloc(N * sizeof(double));
    }

    for (int i = 0; i < M; i++)
        b[i] = (double*)malloc(N * sizeof(double));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            a[i][j] = rand() % 10;
            b[j][i] = rand() % 10;
        }

    QueryPerformanceCounter(&t1);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            sum[i][j] = 0;
            for (int k = 0; k < M; k++)
                sum[i][j] += a[i][k] * b[k][j];
        }
    QueryPerformanceCounter(&t2);
    QueryPerformanceFrequency(&f);

    double sec = (double)(t2.QuadPart - t1.QuadPart) / f.QuadPart;
    printf("sum[0][0] = %f \n", sum[0][0]);
    printf("it took %f seconds to execute \n", sec);
    return 0;
}
