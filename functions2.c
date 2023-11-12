#include "main.h"

/****************** PRINT THE VALUE OF A POINTER ******************/

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: Arguments list
 * Olatunji Oluwadare and Goodnews Akpan (authors)
 * @buffer: Buffer array
 * @flags: Active flags for formatting
 * @width: Width specification
 * @precision: Specification
 * @size: Specifier
 * Return: Num of characters printed
 */

int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char extra_c = 0, padd = ' ';
int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);

UNUSED(width);
UNUSED(size);

if (addrs == NULL)
return (write(1, "(nil)", 5));

buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);

num_addrs = (unsigned long)addrs;

while (num_addrs > 0)
{
buffer[ind--] = map_to[num_addrs % 16];
num_addrs /= 16;
length++;
}

if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (flags & F_PLUS)
extra_c = '+', length++;
else if (flags & F_SPACE)
extra_c = ' ', length++;

ind++;

return (write_pointer(buffer, ind, length,
width, flags, padd, extra_c, padd_start));
}

/************************* TO PRINT NON-PRINTABLE CHARACTERS *************************/

/**
 * print_non_printable - Prin ASCII codes in hex format/non-printable char
 * @types: List of arguments
 * @buffer: Array for printing
 * @flags: Active flags for formatting
 * @width: Width specification
 * Olatunji Oluwadare and Goodnews Akpan
 * @precision: Specification
 * @size: Specifier
 * Return: Number of characters printed
 */

int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = 0, offset = 0;
char *str = va_arg(types, char *);

UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (str == NULL)
return (write(1, "(null)", 6));

while (str[i] != '\0')
{
if (is_printable(str[i]))
buffer[i + offset] = str[i];
else
offset += append_hexa_code(str[i], buffer, i + offset);

i++;
}

buffer[i + offset] = '\0';

return (write(1, buffer, i + offset));
}

/************************* PRINT A STRING IN REVERSE *************************/

/**
 * print_reverse - Prints a reversed string
 * @types: Lists arguments
 * @buffer: Array for printing
 * @flags: Active flags for formatting
 * @width: Specification
 * @precision: Specification
 * Goodnews Akpan
 * @size: Specifier
 * Return: Number of characters to be printed
 */

int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char *str;
int i, count = 0;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);

str = va_arg(types, char *);

if (str == NULL)
{
UNUSED(precision);

str = ")Null(";
}
for (i = 0; str[i]; i++)
;

for (i = i - 1; i >= 0; i--)
{
char z = str[i];

write(1, &z, 1);
count++;
}
return (count);
}

/************************* PRINT A STRING ENCODED IN ROT13 *************************/

/**
 * print_rot13string - Prints a string encoded in ROT13
 * @types: Lis arguments
 * @buffer: Array for printing
 * @flags: For formatting
 * @width: Width specification
 * @precision: Precision specification
 * Olatunji Oluwadare
 * @size: Specifier
 * Return: Number of characters
 */

int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char x;
char *str;
unsigned int i, j;
int count = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (str == NULL)
str = "(AHYY)";
for (i = 0; str[i]; i++)
{
for (j = 0; in[j]; j++)
{
if (in[j] == str[i])
{
x = out[j];
write(1, &x, 1);
count++;
break;
			}
}
if (!in[j])
{
x = str[i];
write(1, &x, 1);
count++;
}
}

return (count);
}
