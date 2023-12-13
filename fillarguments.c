#include "main.h"
/**
 * fillarguments - divide a string and fill an array with each word
 * @buffer: buffer which contains the string
 * @separator: separator use to split the buffer
 *
 * Return: array of words
 */
char **fillarguments(char *buffer, char *separator)
{
	char **arr = NULL;
	char *token;
	int i = 0, length;

	if (buffer == NULL && separator == NULL)
		return (NULL);

	arr = malloc(sizeof(char *) * (number_of_words(buffer, separator) + 1));
	if (arr == NULL)
		return (NULL);

	token = _strtok(buffer, separator);
	while (token)
	{
		if (token[0] == '\n')
			break;
		arr[i++] = token;
		token = _strtok(NULL, separator);
	}
	if (i != 0)
	{
		length = _strlen(arr[i - 1]);
		if (arr[i - 1][length - 1] == '\n')
			arr[i - 1][length - 1] = '\0';
	}
	arr[i] = NULL;
	return (arr);
}
