
/**
 * @file log.h
 * @brief      Mere console logging tool
 * @author     Nathanaël SPRIET
 * @date       15/02/2017
 */

#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define ANSI_COLOR_RED   "\x1B[31m"
#define ANSI_COLOR_GREEN   "\x1B[32m"
#define ANSI_COLOR_YELLOW   "\x1B[33m"
#define ANSI_COLOR_BLUE   "\x1B[34m"
#define ANSI_COLOR_MAGENTA   "\x1B[35m"
#define ANSI_COLOR_CYAN   "\x1B[36m"
#define ANSI_COLOR_WHITE   "\x1B[37m"
#define ANSI_COLOR_RESET "\x1B[0m"

/**
 * @brief      Logs an error.
 *
 * @param      string  The string
 */
void log_error(const char* string, ...);

/**
 * @brief      Logs a warning.
 *
 * @param      string  The string
 */
void log_warning(const char* string, ...);

/**
 * @brief      Logs an information.
 *
 * @param      string  The string
 */
void log_info(const char* string, ...);

/**
 * @brief      Logs a debug.
 *
 * @param      string  The string
 */
void log_debug(const char* string, ...);

/**
 * @brief      Logs a valid.
 *
 * @param      string  The string
 */
void log_valid(const char* string, ...);

/**
 * @brief      Logs a false.
 *
 * @param      string  The string
 */
void log_false(const char* string, ...);

#endif