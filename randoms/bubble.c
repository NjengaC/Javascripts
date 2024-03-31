#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubblesort(int arr[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
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

	bubblesort(arr, n);
	printA(arr, n);

	return (0);
}
