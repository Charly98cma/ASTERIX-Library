/**
 * @file cat021_item008.c
 * @brief Implementation of the Category 21 Item 008 functions
 */

#include "cat021_item008.h"
#include "constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the TCAS Resolution Advisory status (RA) from I021/008.
 * 
 * Portable access to the RA bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item008 structure.
 * @return uint8_t Value of RA (0: not active, 1: active)
 */
uint8_t get_cat021_item008_RA(const cat021_item008 * item)
{
    return GET_BITS((item)->raw, 8, MASK_01_BITS);
}

/**
 * @brief Get the Target Trajectory Change Report Capability (TC) from I021/008.
 * 
 * Portable access to the TC bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item008 structure.
 * @return uint8_t Value of TC (0: no capability, 1: TC+0 reports only, 2: multiple TC reports, 3: reserved)
 */
uint8_t get_cat021_item008_TC(const cat021_item008 * item)
{
    return GET_BITS((item)->raw, 6, MASK_02_BITS);
}

/**
 * @brief Get the Target State Report Capability (TS) from I021/008.
 * 
 * Portable access to the TS bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item008 structure.
 * @return uint8_t Value of TS (0: no capability, 1: capability supported)
 */
uint8_t get_cat021_item008_TS(const cat021_item008 * item)
{
    return GET_BITS((item)->raw, 5, MASK_01_BITS);
}

/**
 * @brief Get the Air-Referenced Velocity Report Capability (ARV) from I021/008.
 * 
 * Portable access to the ARV bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item008 structure.
 * @return uint8_t Value of ARV (0: no capability. 1: capability supported)
 */
uint8_t get_cat021_item008_ARV(const cat021_item008 * item)
{
    return GET_BITS((item)->raw, 4, MASK_01_BITS);
}

/**
 * @brief Get the Cockpit Display of Traffic Information airborne (CDTI) from I021/008.
 * 
 * Portable access to the CDTI bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item008 structure.
 * @return uint8_t Value of CDTI (0: not operational, 1: operational)
 */
uint8_t get_cat021_item008_CDTI(const cat021_item008 * item)
{
    return GET_BITS((item)->raw, 3, MASK_01_BITS);
}

/**
 * @brief Get the Not TCAS System Status (NTCAS) from I021/008.
 * 
 * Portable access to the NTCAS bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item008 structure.
 * @return uint8_t Value of NTCAS (0: operational, 1: not operational)
 */
uint8_t get_cat021_item008_NTCAS(const cat021_item008 * item)
{
    return GET_BITS((item)->raw, 2, MASK_01_BITS);
}

/**
 * @brief Get the Single Antenna (SA) from I021/008.
 * 
 * Portable access to the SA bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item008 structure.
 * @return uint8_t Value of SA (0: antenna diversity, 1: single antenna only)
 */
uint8_t get_cat021_item008_SA(const cat021_item008 * item)
{
    return GET_BITS((item)->raw, 1, MASK_01_BITS);;
}

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Set the TCAS Resolution Advisory status (RA) into the raw field.
 * 
 * @param item Pointer to cat021_item008 structure.
 * @param value Value of RA
 */
void set_cat021_item008_RA(cat021_item008 * item, uint8_t value)
{
    SET_BITS(&((item)->raw), value, MASK_01_BITS, 8);
}

/**
 * @brief Set the Target Trajectory Change Report Capability (TC) into the raw field.
 * 
 * @param item Pointer to cat021_item008 structure.
 * @param value Value of TC
 */
void set_cat021_item008_TC(cat021_item008 * item, uint8_t value)
{
    SET_BITS(&((item)->raw), value, MASK_02_BITS, 6);
}

/**
 * @brief Set the Target State Report Capability (TS) into the raw field.
 * 
 * @param item Pointer to cat021_item008 structure.
 * @param value Value of TS
 */
void set_cat021_item008_TS(cat021_item008 * item, uint8_t value)
{
    SET_BITS(&((item)->raw), value, MASK_01_BITS, 5);
}

/**
 * @brief Set the Air-Referenced Velocity Report Capability (ARV) into the raw field.
 * 
 * @param item Pointer to cat021_item008 structure.
 * @param value Value of ARV
 */
void set_cat021_item008_ARV(cat021_item008 * item, uint8_t value)
{
    SET_BITS(&((item)->raw), value, MASK_01_BITS, 4);
}

/**
 * @brief Set the Cockpit Display of Traffic Information airborne (CDTI) into the raw field.
 * 
 * @param item Pointer to cat021_item008 structure.
 * @param value Value of CDTI
 */
void set_cat021_item008_CDTI(cat021_item008 * item, uint8_t value)
{
    SET_BITS(&((item)->raw), value, MASK_01_BITS, 3);
}

/**
 * @brief Set the Not TCAS System Status (NTCAS) into the raw field.
 * 
 * @param item Pointer to cat021_item008 structure.
 * @param value Value of NTCAS
 */
void set_cat021_item008_NTCAS(cat021_item008 * item, uint8_t value)
{
    SET_BITS(&((item)->raw), value, MASK_01_BITS, 2);
}

/**
 * @brief Set the Single Antenna (SA) into the raw field.
 * 
 * @param item Pointer to cat021_item008 structure.
 * @param value Value of SA
 */
void set_cat021_item008_SA(cat021_item008 * item, uint8_t value)
{
    SET_BITS(&((item)->raw), value, MASK_01_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT 021 / Item 008.
 *
 * This function prints the values of the main byte.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a cat021_item008 structure.
 */
void print_cat021_item008(const cat021_item008 *item)
{
    printf("CAT021 / Item 008 - Aircraft Operational Status\n");
    printf("  RA: %d\n", get_cat021_item008_RA(item));
    printf("  TC: %d\n", get_cat021_item008_TC(item));
    printf("  TS: %d\n", get_cat021_item008_TS(item));
    printf("  ARV: %d\n", get_cat021_item008_ARV(item));
    printf("  CDTI: %d\n", get_cat021_item008_CDTI(item));
    printf("  NTCAS: %d\n", get_cat021_item008_NTCAS(item));
    printf("  SA: %d\n\n", get_cat021_item008_SA(item));
}
