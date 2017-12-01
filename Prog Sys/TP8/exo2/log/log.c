/**
 * @file log.h
 * @brief      Mere console logging tool
 * @author     Nathanaël SPRIET
 * @date       15/02/2017
 */

#include "log.h"

void log_error(const char* string, ...)
{
	va_list args;
	va_start(args, string);
	printf(ANSI_COLOR_RED);
	vprintf(string, args);
	printf(ANSI_COLOR_RESET);
	va_end(args);
}
void log_warning(const char* string, ...)
{
	va_list args;
	va_start(args, string);
	printf(ANSI_COLOR_YELLOW);
	vprintf(string, args);
	printf(ANSI_COLOR_RESET);
	va_end(args);
}
void log_info(const char* string, ...)
{
	va_list args;
	va_start(args, string);
	printf(ANSI_COLOR_CYAN);
	vprintf(string, args);
	printf(ANSI_COLOR_RESET);
	va_end(args);
}
void log_debug(const char* string, ...)
{
	va_list args;
	va_start(args, string);
	printf(ANSI_COLOR_BLUE);
	vprintf(string, args);
	printf(ANSI_COLOR_RESET);
	va_end(args);
}
void log_valid(const char* string, ...)
{
	va_list args;
	va_start(args, string);
	printf(ANSI_COLOR_GREEN);
	vprintf(string, args);
	printf(ANSI_COLOR_RESET);
	va_end(args);
}
void log_false(const char* string, ...)
{
	va_list args;
	va_start(args, string);
	printf(ANSI_COLOR_RED);
	vprintf(string, args);
	printf(ANSI_COLOR_RESET);
	va_end(args);
}