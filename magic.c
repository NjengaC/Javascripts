#include <stdio.h>
 
int magical(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 5;

	else
		return magical(n -1) + magical(n - 2) + 2;
}

int main()
{
	printf("%d\n", magical(3));
	printf("%d\n", magical(5));
}
