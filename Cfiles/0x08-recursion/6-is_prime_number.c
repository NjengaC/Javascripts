#include "main.h"
int real_prime_number(int n, int x);
/**
 * is_prime_number - function that checks if a number is prime number
 * @n: is the number to check
 *
 * Return: 1 if n is a prime number otherwise 0
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (real_prime_number(n, n - 1));
}


/**
 * real_prime_number - computers recursively if n is a prime number
 * @n: is the number we are checking
 * @x: is the iterator
 *
 * Return: 1 if n is a prime number otherwise 0
 */
int real_prime_number(int n, int x)
{
	if (x == 1)
		return (1);
	if (n % x == 0 && x > 0)
		return (0);
	return (real_prime_number(n, x - 1));
}
