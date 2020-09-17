/**
 * is_palindrome - checks whether or not a given unsigned integer is a
 * palindrome.
 * @n: the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
*/
int is_palindrome(unsigned long n)
{
	unsigned long len, aux;

	len = n;
	aux = 0;

	while (len != 0)
	{
		aux += len % 10;
		len /= 10;
		if (len != 0)
			aux *= 10;
	}
	if (aux == n)
		return (1);
	return (0);
}
