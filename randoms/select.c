#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void selsort(int arr[], int n)
{
	int i, j, min;

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i+1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		swap(&arr[min], &arr[i]);
	}
}

void printA(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main()
{
	srand(time(NULL));
	int arr[100];

	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand() % 1001;
	}
	int n = sizeof(arr) / sizeof(arr[0]);

	printA(arr, n);

	selsort(arr, n);
	printA(arr, n);

	return (0);
}
