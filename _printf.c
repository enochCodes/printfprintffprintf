#include "main.h"

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			putchar(*format);
			printed_chars++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				int c = va_arg(args, int);
				putchar(c);
				printed_chars++;
			}
			else if (*format == 's')
			{
				const char *str = va_arg(args, const char *);
				while (*str != '\0')
				{
					putchar(*str);
					str++;
					printed_chars++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				printed_chars++;
			}
			else
			{
				putchar('%');
				putchar(*format);
				printed_chars += 2;
			}
		}
		format++;
	}
	va_end(args);
	return printed_chars;
}
