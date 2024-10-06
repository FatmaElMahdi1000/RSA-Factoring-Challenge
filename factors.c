#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * LIMIT - A macro defining the maximum buffer size.
 */
#define LIMIT 10000

/**
 * factorize - Factorizes number into two smaller factors.
 * @numberStr: A string representation of number
 * Return: A formatted string representing the factorization
 */
void factorize(const char *numberStr)
{
	long long number = atoll(numberStr);
	long long p = 0, q = 0;

	for (long long i = 2; i * i <= number; i++)
	{
		if (number % i == 0)
			p = i;
			q = number / i;
			break;
	}
	if (p != 0 && q != 0)
		printf("%lld = %lld * %lld\n", number, p, q);
}
/**
 *openFile - Opening the file
 *
 * @filename: the file name
 *
 * Return: file opened
 */
void openFile(const char *filename)
{
	char *buffer;

	buffer = (char *)malloc(LIMIT * sizeof(char));

	if (buffer == NULL)
		fprintf(stderr, "Memory allocation failed\n");
		return;

	FILE *fp = fopen(filename, "r");

	if (fp == NULL)
		fprintf(stderr, "ERROR OPENING FILE\n");
		free(buffer);
		return;

	while (fgets(buffer, LIMIT, fp) != NULL)
	{
		buffer[strcspn(buffer, "\n")] = '\0';
		factorize(buffer);
	}
	free(buffer);
	fclose(fp);
}

/**
 * main - Entry point
 * @argc: arg count
 * @argv: arg values
 * Return: 0 success
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}
	openFile(argv[1]);
	return (0);
}
