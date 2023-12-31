#include "main.h"

/**
 * is_printable - Evaluate if a character is printable
 * @c: Char to be evaluated
 * Olatunji Oluwadare
 * Return: 1 if c is printable, 0 otherwise
 */

int is_printable(char c)
{
if (c >= 32 && c < 127)
return (1);

return (0);
}

/**
 * append_hexa_code - Appends ASCII in hexadecimal code to buffer
 * @buffer: Array of characters
 * @i: Index to start appending
 * @ascii_code: ASCII
 * Olatunji Oluwadare
 * Return: Always 4
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";

if (ascii_code < 0)
ascii_code *= -1;

buffer[i++] = '\\';
buffer[i++] = 'x';

buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];

return (4);
}

/**
 * is_digit - Verifies if a character is a digit
 * @c: Char to be evaluated
 * Olatunji Oluwadare
 * Return: 1 if c is a digit, 0 otherwise
 */

int is_digit(char c)
{
if (c >= '0' && c <= '9')
return (1);

return (0);
}

/**
 * convert_size_number - Converts a num to specified size type
 * @num: Number to be converted
 * Goodnews Akpan
 * @size: Size specifier indicating the type of conversion
 * Return: Converted value of num
 */

long int convert_size_number(long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((short)num);

return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Numbers to be casted
 * @size: Number indicating the type to be casted
 * Goodnews Akpan
 * Return: Casted value of num
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((unsigned short)num);

return ((unsigned int)num);
}
