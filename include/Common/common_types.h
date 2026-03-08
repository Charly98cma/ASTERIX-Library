/**
 * @file common_types.h
 * @brief 
 * @version 0.1
 * @date 2026-02-09
 * 
 * @copyright Copyright (c) 2026
 */

#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

/**
 * @brief Presence/Absence fralg of items and extensions words
 */
typedef enum ePresenceFlag
{
    ePresenceFlag_ABSENT  =  0,
    ePresenceFlag_PRESENT =  1,
} ePresenceFlag;

typedef enum eBoolean
{
    eBoolean_FALSE = 0,
    eBoolean_TRUE  = 1,
} eBoolean;

#endif /* COMMON_TYPES_H */