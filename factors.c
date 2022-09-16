#include <stdio.h>

/**
 * get_least - Gets the least factor of
 * the number passed as argument.
 * @n: the number to factorise and get the least factor.
 *
 * Return: The least factor of the argument.
 */

size_t get_least(unsigned long long int n)
{
	int f = 3;

	if (n % 2 == 0)
		return (2);
	while (f <= n)
	{
		if (n % f == 0)
			return (f);
		f += 2;
	}
	return (1);
}

/**
 * print_product - prints result of the product
 * of two factors of the result.
 * @n: The number to factorise.
 *
 * Return: void.
 */

void print_product(unsigned long long int n)
{
	size_t min_factor;

	min_factor = get_least(n);
	printf("%llu = %llu * %ld\n", n, n/min_factor, min_factor);
}
