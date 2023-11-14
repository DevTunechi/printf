#include <stdio.h>
#include <stdarg.h>

void print_repr(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%' && *(format + 1) == 'r') {
            char character = va_arg(args, int);
            /**** Print character with special handling for newline and other special characters ****/
            switch (character) {
                case '\n':
                    printf("\\n");

                /******* Add more cases as needed for other special characters *****/
                default:
                    putchar(character);
            }
            format += 2;
        } else {
            putchar(*format);
            format++;
        }
    }

    va_end(args);
}

int main(void) {
    char special_char = '@';
    print_repr("Printing %r and ignoring other specifiers: %d, %f\n", special_char, 42, 3.14);
    return 0;
}
