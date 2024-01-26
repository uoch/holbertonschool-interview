#include <stdio.h>
#include <stdlib.h>

int _putchar(char c);

/**
 * print_number - prints a long long integer
 * @n: long long integer to be printed
 */
void print_number(long long n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n / 10 != 0)
		print_number(n / 10);

	_putchar(n % 10 + '0');
}

/**
 * is_digit_str - checks if a string contains only digits
 * @str: input string
 * Return: 1 if all characters are digits, 0 otherwise
 */
int is_digit_str(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return 0;
		str++;
	}
	return 1;
}

/**
 * exit_error - prints "Error" and exits with status 98
 */
void exit_error(void)
{
	char error[] = "Error\n";
	int i = 0;
	while (error[i])
	{
		_putchar(error[i]);
		i++;
	}
	exit(98);
}

long long mul(long long a, long long b)
{
	return (a * b);
}

int main(int argc, char *argv[])
{
	long long a, b, product;

	if (argc != 3 || !is_digit_str(argv[1]) || !is_digit_str(argv[2]))
	{
		exit_error();
	}

	a = atoll(argv[1]);
	b = atoll(argv[2]);
	product = mul(a, b);

	if (product < 0)
	{
		_putchar('-');
		product = -product;
	}

	if (product == 0)
	{
		_putchar('0');
	}
	else
	{
		print_number(product);
	}

	_putchar('\n');

	return 0;
}
