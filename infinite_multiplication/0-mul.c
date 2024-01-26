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
 *
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

/**
 * school_mul - performs multiplication of two large numbers
 * @arr1: array representing the first number
 * @arr2: array representing the second number
 * @len1: length of the first array
 * @len2: length of the second array
 *
 * Return: 0 on success
 */
int school_mul(char *arr1, char *arr2, int len1, int len2)
{
	int i, j, k = 0, carry = 0, sum = 0;
	int *result = malloc(sizeof(int) * (len1 + len2));

	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			sum = (arr1[i] - '0') * (arr2[j] - '0') + result[i + j + 1] + carry;
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}
		result[i + j + 1] = carry;
	}

	while (result[k] == 0)
		k++;

	for (i = k; i < len1 + len2; i++)
		_putchar(result[i] + '0');

	_putchar('\n');
	free(result);
	return (0);
}

/**
 * main - entry point of the program
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !is_digit_str(argv[1]) || !is_digit_str(argv[2]))
		exit_error();

	int len1 = 0, len2 = 0;

	while (argv[1][len1])
		len1++;

	while (argv[2][len2])
		len2++;

	school_mul(argv[1], argv[2], len1, len2);

	return (0);
}
