/**
 * @file asterix_log.c
 * @brief Implementation of the logger
 */

#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include "asterix_log.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/

/**
 * @brief Sets the logging file for all log messages
 * 
 * @param fp FILE (object) to save log messages
 */
void log_set_file(FILE* fp) {
    log_output_file = fp;
}

/**
 * @brief Returns a string with the current date and time (multi-thread safe)
 * 
 * @return const char* String with the current date and time in the
 *                     format "%Y-%m-%d %H:%M:%S".
 */
const char* current_time_str(char* buffer, size_t size) {
    time_t t = time(NULL);
    struct tm tm_info;
    localtime_r(&t, &tm_info);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", &tm_info);
    return buffer;
}

/**
 * @brief Create log message with the given level, format and arguments
 * 
 * This function writes the given log message to stderr and to the previously
 * set logging tile, specifying the level and timestamp following the given
 * format and values.
 * 
 * @param level Logging level of the message
 * @param color Color of the logging level
 * @param tag String of the logging level
 * @param fmt Format of the message
 * 
 */
void log_message(int level, const char* color, const char* tag, const char* fmt, ...) {
    // Only logging messages with equal or greater criticality
    if (level < LOG_LEVEL) return;

    // Arguments list
    va_list args;

    // Get timestamp (multi-thread safe)
    char timestamp[20]; 
    current_time_str(timestamp, sizeof(timestamp));

    // Write log message to stderr
    va_start(args, fmt);
    fprintf(stderr, "%s[%s] [%s] ", color, timestamp, tag);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "%s\n", COLOR_RESET);
    va_end(args);

    // Write log to file if configured previously
    if (log_output_file) {
        va_start(args, fmt);
        fprintf(log_output_file, "[%s] [%s] ", timestamp, tag);
        vfprintf(log_output_file, fmt, args);
        fprintf(log_output_file, "\n");
        fflush(log_output_file);
        va_end(args);
    }
}