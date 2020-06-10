#include <stdio.h> 
#include <time.h>

#include <Windows.h>
#include <omp.h>

int main()
{
	int count = 1, N;
	printf("Calculation of the number of primes 2 to N\nInput N:");
	scanf_s("%d", &N);
	LARGE_INTEGER t1, t2, f;
	QueryPerformanceCounter(&t1);
	#pragma omp parallel for reduction(+: count)
	for (int i = 2; i < N; i++)
	{
		int prime = 1;

		for (int j = 2; j * j <= i; j++)
		{
			if (i % j == 0)
			{
				prime = 0;
				break;
			}
		}
		if (prime == 1) {
			count++;
		}
	}
	QueryPerformanceCounter(&t2);
	QueryPerformanceFrequency(&f);
	double sec = (double)(t2.QuadPart - t1.QuadPart) / f.QuadPart;
	printf("count = %d \n", count);
	printf("it took %f seconds to execute \n", sec);
	return 0;
}
