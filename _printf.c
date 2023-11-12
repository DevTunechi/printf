#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Customized printf function
 * @format: Format string
 * Olatunji Oluwadare and Goodnews Akpan
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
int i, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list a_list;
char buffer[BUFF_SIZE];

if (format == NULL)
return (-1);

va_start(a_list, format);

for (i = 0; format && format[i] != '\0'; i++)
{
if (format[i] != '%')
{
buffer[buff_ind++] = format[i];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);

/* write(1, &format[i], 1);*/
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(format, &i);
width = get_width(format, &i, a_list);
precision = get_precision(format, &i, a_list);
size = get_size(format, &i);
++i;
printed = handle_print(format, &i, a_list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}

print_buffer(buffer, &buff_ind);

va_end(a_list);

return (printed_chars);
}

/**
 * print_buffer - Outputs the contents of the buffer, if it is not empty
 * @buffer: Array of characters to be displayed
 * @buff_ind: Index indicating the length of the buffer
 */


void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);

*buff_ind = 0;
}
