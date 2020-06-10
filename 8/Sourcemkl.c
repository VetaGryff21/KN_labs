#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#ifdef __INTEL_COMPILER
#include<mkl_cblas.h> // C-интерфейс BLAS (заголовочный файл из MKL)
#else
#include<cblas.h> // C-интерфейс BLAS (стандартный заголовочный файл)
#endif

#define M 100
#define N 1000
#define K 10000

double *a, *b, *sum;

int main()
{
    LARGE_INTEGER t1, t2, f;
    srand(time(NULL));
    a = (double*)malloc(M * K * sizeof(double));
    b = (double*)malloc(K * N * sizeof(double));
    sum = (double*)malloc(M * N * sizeof(double));

    for (int i = 0; i < M; i++)
        for (int j = 0; j < K; j++)
            a[i*K+j] = rand() % 10;

    for (int i = 0; i < K; i++)
        for (int j = 0; j < N; j++)
            b[i*N+j] = rand() % 10;

    QueryPerformanceCounter(&t1);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
        M, N, K, 1.0, a, K, b, N, 0.0, sum, N);
    QueryPerformanceCounter(&t2);
    QueryPerformanceFrequency(&f);
    double sec = (double)(t2.QuadPart - t1.QuadPart) / f.QuadPart;
    
    printf("%.2f \n", sum[15]);
    printf("it took %f seconds to execute \n", sec);
    free(a);
    free(b);
    free(sum);
    return 0;
}
//
//int main()
//{
//    LARGE_INTEGER t1, t2, f;
//    srand(time(NULL));
//    double* a = (double*)malloc(N * K * sizeof(double));
//    double* b = (double*)malloc(K * M * sizeof(double));
//    double* sum = (double*)malloc(N * M * sizeof(double));
//
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < K; j++) {
//            a[i*K+j] = rand() % 10;
//        }
//    for (int i = 0; i < K; i++)
//        for (int j = 0; j < M; j++) {
//            a[i * M + j] = rand() % 10;
//        }
//
//    QueryPerformanceCounter(&t1);
//    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
//        N, M, K, 1.0, a, K, b, N,0.0, sum, M);
//    QueryPerformanceCounter(&t2);
//    QueryPerformanceFrequency(&f);
//
//    double sec = (double)(t2.QuadPart - t1.QuadPart) / f.QuadPart;
//    printf("sum[0][0] = %f \n", sum[0]);
//    printf("it took %f seconds to execute \n", sec);
//    return 0;
//}

