/**
 * @file Header.h
 * @brief 
 * @version 0.1
 * @date 2026-03-07
 * 
 * @copyright Copyright (c) 2026 
 */

#ifndef HEADER_H
#define HEADER_H

/* Standard libraries */
#include <stdint.h>

/* Project libraries */
#include <Infra/infra.h>
#include <Common/visibility.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ================================= MACROS ================================= */

/* ================================== ENUMS ================================= */

/* ================================ STRUCTS ================================= */

/**
 * @typedef Header
 * @brief Header type of ASTERIX messages
 * 
 * Type used to represent the header of any ASTERIX message,
 * with the category and length (in Bytes) of the message.
 */
typedef struct Header
{
    /// @brief Asterix category (range from 0 to 255)
    u8 CAT;
    /// @brief Full length of the message
    u16 LEN;
} Header;

/* ============================== EXTRA FUNCS ============================== */

#ifdef __cplusplus
}
#endif

#endif /* HEADER_H */
