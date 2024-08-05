#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/**
 * _printf _custom printf function
 * @format: format string containing directives
 *
 * Return: Number of characters printed (excluding null byte)
 */

static void int_to_str(int num, char *buffer) {
    int a = 0;
    int b;
    int is_negative = 0;
    if (num < 0) {
        is_negative = 1;
        num = -num;
    }
    if (num == 0) {
        buffer[a++] = '0';
    }
    
    while (num != 0) {
        buffer[a++] = (num % 10) + '0';
        num /= 10;
    }
    if (is_negative) {
        buffer[a++] = '-';
    }
    buffer[a] = '\0';
    for (b = 0; b < a / 2; b++) {
        char temp = buffer[b];
        buffer[b] = buffer[a - b - 1];
        buffer[a - b - 1] = temp;
    }
}

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	const char *ptr;
	char *str;
	char c;
	ssize_t written;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (ptr == '%') {
			ptr++;
		if (ptr == 'd' || ptr == 'i') {
			int num = va_arg(args, int);
			int_to_str(num, str);

			written = write(STDOUT_FILENO, buffer, strlen(str))
				if (written == -1) {
					va_end(args);
					return -1;
				}
			count += written;
		}else {
			written = write(STDOUT_FILENO, "%" , 1);
			if (written == -1){
				va_end(args);
				return -1;
			}
			count += written;

			written = write(STDOUT_FILENO, ptr, 1);
			if (written == -1) {
				va_end(args);
				return -1;

			}
			count += written;

		}
		} else {
			written = write(STDOUT_FILENO, ptr, 1);
			if (written == -1) {
				va_end(args);
				return -1;
			}
			count += written;
		}
	}

	va_end(args)
		return count;
}
