/**
 * @file asterix_log.h
 * @brief Logger file header
 */

#ifndef ASTERIX_LOG_H
#define ASTERIX_LOG_H

#include <stdio.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

// Logging levels
#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_INFO  1
#define LOG_LEVEL_WARN  2
#define LOG_LEVEL_ERROR 3

#ifndef LOG_LEVEL
    #define LOG_LEVEL LOG_LEVEL_INFO
#endif

// ANSI colors for terminal output
#define COLOR_RESET     "\x1b[0m"
#define COLOR_RED       "\x1b[31m"
#define COLOR_YELLOW    "\x1b[33m"
#define COLOR_GREEN     "\x1b[32m"
#define COLOR_CYAN      "\x1b[36m"

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/// @brief Output file for logging (optional)
static FILE* log_output_file = NULL;

ASTERIX_API void log_set_file(FILE* fp);
ASTERIX_API const char* current_time_str(char* buffer, size_t size);
ASTERIX_API void log_message(int level, const char* color, const char* tag, const char* fmt, ...);

/*******************************************************************************
 * Macros for logger
 ******************************************************************************/

// Disable all logging macros (flag '-DDISABLE_ASTLOG' on compilation)
#ifdef DISABLE_ASTLOG
    #define ASTLOG_DEBUG(fmt)
    #define ASTLOG_DEBUGF(fmt, ...)
    #define ASTLOG_INFO(fmt)
    #define ASTLOG_INFOF(fmt, ...)
    #define ASTLOG_WARN(fmt)
    #define ASTLOG_WARNF(fmt, ...)
    #define ASTLOG_ERROR(fmt)
    #define ASTLOG_ERRORF(fmt, ...)
#else
    // Logging macros to support both text-only and formatted logs
    #define ASTLOG_DEBUG(fmt) log_message(LOG_LEVEL_DEBUG, COLOR_CYAN,  "DEBUG", fmt)
    #define ASTLOG_DEBUGF(fmt, ...) log_message(LOG_LEVEL_DEBUG, COLOR_CYAN,  "DEBUG", fmt, ##__VA_ARGS__)
    #define ASTLOG_INFO(fmt)  log_message(LOG_LEVEL_INFO,  COLOR_GREEN, "INFO",  fmt)
    #define ASTLOG_INFOF(fmt, ...)  log_message(LOG_LEVEL_INFO,  COLOR_GREEN, "INFO",  fmt, ##__VA_ARGS__)
    #define ASTLOG_WARN(fmt)  log_message(LOG_LEVEL_WARN,  COLOR_YELLOW,"WARN",  fmt)
    #define ASTLOG_WARNF(fmt, ...)  log_message(LOG_LEVEL_WARN,  COLOR_YELLOW,"WARN",  fmt, ##__VA_ARGS__)
    #define ASTLOG_ERROR(fmt) log_message(LOG_LEVEL_ERROR, COLOR_RED,   "ERROR", fmt)
    #define ASTLOG_ERRORF(fmt, ...) log_message(LOG_LEVEL_ERROR, COLOR_RED,   "ERROR", fmt, ##__VA_ARGS__)
#endif // DISABLE_ASTLOG

#ifdef __cplusplus
}
#endif

#endif // ASTERIX_LOG_H