#include "main.h"

/************************* PRINT UNSIGNED NUMBER WITH GIVEN ARGUMENTS ************************/
/**
 * print_unsigned - Printing of unsigned number with given arguments
 * @types: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active flags for formatting
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * Olatunji Oluwadare and Goodnews Akpan (authors)
 * Return: Number of characters printed
 */


int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);

num = convert_size_unsgnd(num, size);

if (num == 0)
buffer[i--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}

i++;

return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* FUNCTION TO PRINT UNSIGNED NUMBER IN OCTAL  ****************/

/**
 * print_octal - Handles printing unsigned num in octal notation
 * @types: List of arguments
 * @buffer: Buffer array for printing
 * @flags: Active flags for formatting
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */


int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{

int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(width);

num = convert_size_unsgnd(num, size);

if (num == 0)
buffer[i--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[i--] = (num % 8) + '0';
num /= 8;
}

if (flags & F_HASH && init_num != 0)
buffer[i--] = '0';

i++;

return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** FUNCTION TO PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/

/**
 * print_hexadecimal - printing unsigned number in hexadecimal notation
 * @types: List arguments
 * @buffer: Buffer array for printing
 * @flags: Active flags for formatting
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */


int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}

/************* FUNCTION TO PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - prints an unsigned num in uppercase hexadecimal notation
 * @types: Arguments list
 * @buffer: Buffer array for printing
 * @flags: Active flags for formatting
 * @width: Width specification
 * @precision: Precision specification
 * @size: Specifier
 * Return: Number characters printed
 */


int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}

/************** PRINT HEXADECIMAL NUMBERS IN LOWER OR UPPER CASE **************/

/**
 * print_hexa - Prints hexadecimal num in lower || uppercase
 * @types: Arguments list
 * @map_to: Array of valuess
 * @buffer: Buffer array for printing
 * @flags: Active for formatting
 * @flag_ch: Active for character mapping
 * @width: Width specification
 * @precision: Specification
 * @size: Specifier
 * Return: Number of characters printed
 */


int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(width);

num = convert_size_unsgnd(num, size);

if (num == 0)
buffer[i--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[i--] = map_to[num % 16];
num /= 16;
}

if (flags & F_HASH && init_num != 0)
{
buffer[i--] = flag_ch;
buffer[i--] = '0';
}

i++;

return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
