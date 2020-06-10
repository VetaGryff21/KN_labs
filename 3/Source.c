#include <stdio.h>
#include <Windows.h>

#define N 10000
#define M 100000


int main()
{
    int **a = malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++)
        a[i] = malloc(M * sizeof(int));

    LARGE_INTEGER t1, t2, f;
    QueryPerformanceCounter(&t1);
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            a[i][j] = i + j;

    QueryPerformanceCounter(&t2);
    QueryPerformanceFrequency(&f);
    double sec = (double)(t2.QuadPart - t1.QuadPart) / f.QuadPart;
    printf("a[10][15] = %d\n", a[10][15]);
    printf("it took %f seconds to execute \n", sec);
    return 0;
}
