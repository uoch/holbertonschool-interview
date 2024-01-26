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
 * Return: an array of integers representing the digits of the string
 */
int *is_digit_str(char *str)
{
	int i, *arr;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return NULL;
		i++;
	}

	arr = malloc(sizeof(int) * i);
	if (arr == NULL)
		return NULL;

	while (i--)
	{
		arr[i] = str[i] - '0';
	}

	return arr;
}

/**
 * arr_mul - multiplies two arrays of integers
 * @arr1: first array
 * @arr2: second array
 * @len1: length of the first array
 * @len2: length of the second array
 *
 * Return: an array of integers representing the result of multiplication
 */
int *arr_mul(int *arr1, int *arr2)
{
	int len1, len2, i, j, *result;

	len1 = len2 = i = j = 0;
	while (arr1[len1])
		len1++;
	while (arr2[len2])
		len2++;

	result = malloc(sizeof(int) * (len1 + len2));
	if (result == NULL)
		return NULL;

	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			result[i + j + 1] += arr1[i] * arr2[j];
			result[i + j] += result[i + j + 1] / 10;
			result[i + j + 1] %= 10;
		}
	}

	return result;
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

	int *num1 = is_digit_str(argv[1]);
	int *num2 = is_digit_str(argv[2]);

	if (num1 == NULL || num2 == NULL)
		exit_error();

	int *result = arr_mul(num1, num2);

	if (result == NULL)
		exit_error();

	for (int i = 0; i < len1 + len2; i++)
		_putchar(result[i] + '0');

	_putchar('\n');

	free(num1);
	free(num2);
	free(result);

	return 0;
}
