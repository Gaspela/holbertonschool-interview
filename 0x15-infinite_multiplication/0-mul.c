#include "holberton.h"
#include <stdlib.h>

/**
 * print - entry point
 * @str: char variable
 * @l: int variable
*/
void print(char *str, int l)
{
	int i, j;

	i = j = 0;
	while (i < l)
	{
		if (str[i] != '0')
			j = 1;
		if (j || i == l - 1)
			_putchar(str[i]);
		i++;
	}

	_putchar('\n');
	free(str);
}

/**
 * multiplies - that multiplies two positive numbers
 * @n: char variable
 * @num1: char variable
 * @num2: int variable
 * @d1: char variable
 * @d2: int variable
 * Return: d1
*/
char *multiplies(char n, char *num1, int num2, char *d1, int d2)
{
	int i, j, multiplies, resul, unid, carrier;

	resul = carrier = 0;
	for (i = num2, j = d2; i >= 0; i--, j--)
	{
		multiplies = (n - '0') * (num1[i] - '0') + resul;
		resul = multiplies / 10;
		unid = (d1[j] - '0') + (multiplies % 10) + carrier;
		carrier = unid / 10;
		d1[j] = unid % 10 + '0';
	}
	for (carrier += resul; j >= 0 && carrier; j--)
	{
		unid = (d1[j] - '0') + carrier;
		carrier = unid / 10;
		d1[j] = unid % 10 + '0';
	}
	if (carrier)
	{
		return (NULL);
	}

	return (d1);

}

/**
 * check_number - check number zero digits
 * @av: char variable
 * Return: always 0
*/
int check_number(char **av)
{
	int i, j;

	for (i = 1; i < 3; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
		}
	}

	return (0);
}

/**
 * set_zeros_matrix - set zeros matrix
 * @str: char variable
 * @l: int variable
*/
void set_zeros_matrix(char *str, int l)
{
	int i;

	for (i = 0; i < l; i++)
		str[i] = '0';
	str[i] = '\0';
}

/**
 * main - prints the number of arguments passed into it.
 * @argc: int variable
 * @argv: char variable
 * Return: always 0
*/
int main(int argc, char *argv[])
{
	int i, j, len1, len2, len;
	char *num1;
	char *num2;
	char e[] = "Error\n";

	if (argc != 3 || check_number(argv))
	{
		for (i = 0; e[i]; i++)
			_putchar(e[i]);
		exit(98);
	}
	for (len1 = 0; argv[1][len1]; len1++)
		;
	for (len2 = 0; argv[2][len2]; len2++)
		;
	len = len1 + len2 + 1;
	num1 = malloc(len * sizeof(char));
	if (num1 == NULL)
	{
		for (i = 0; e[i]; i++)
			_putchar(e[i]);
		exit(98);
	}
	set_zeros_matrix(num1, len - 1);
	for (i = len2 - 1, j = 0; i >= 0; i--, j++)
	{
		num2 = multiplies(argv[2][i], argv[1], len1 - 1, num1, (len - 2) - j);
		if (num2 == NULL)
		{
			for (i = 0; e[i]; i++)
				_putchar(e[i]);
			free(num1);
			exit(98);
		}
	}
	print(num1, len - 1);

	return (0);

}
