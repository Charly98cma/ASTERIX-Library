/**
 * @file cat021_item040.c
 * @brief Implementation of the Category 21 Item 040 functions
 */

#include "cat021_item040.h"
#include "constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/*==============================*/
/* Main Part Portable Getters   */
/*==============================*/

/**
 * @brief Get the Address Type (ATP) from CAT 021 Item 040 Primary Subfield.
 * 
 * Portable access to the ATP bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040 structure.
 * @return uint8_t Value of ATP (0: ICAO addr,
 *                               1: dup. addr,
 *                               2: surface vehicle addr.
 *                               3: anon. addr,
 *                               4-7: reserved)
 */
uint8_t get_cat021_item040_ATP(const cat021_item040 *item)
{
    return (((item)->raw >> 5) & MASK_03_BITS); // Bits 7-5
}

/**
 * @brief Get the Altitude Reporting Capability (ARC) from CAT 021 Item 040 Primary Subfield.
 * 
 * Portable access to the ARC bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040 structure.
 * @return uint8_t Value of ARC (0: 25 ft, 1: 100 ft, 2: unknown, 3: invalid)
 */
uint8_t get_cat021_item040_ARC(const cat021_item040 *item)
{
    return (((item)->raw >> 3) & MASK_02_BITS);  // Bits 4-3
}

/**
 * @brief Get the Differential Correction (RC) from CAT 021 Item 040 Primary Subfield.
 * 
 * Portable access to the RC bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040 structure.
 * @return uint8_t Value of RC (0: default,
 *                              1: range checked passed, pending CPR validation)
 */
uint8_t get_cat021_item040_RC(const cat021_item040 *item)
{
    return (((item)->raw >> 2) & MASK_01_BITS); // Bit 2
}

/**
 * @brief Get the Report Type (RAB) from CAT 021 Item 040 Primary Subfield.
 * 
 * Portable access to the RAB bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040 structure.
 * @return uint8_t Value of RAB (0: report from target transponder,
 *                               1: report from field fixed transponder)
 */
uint8_t get_cat021_item040_RAB(const cat021_item040 *item)
{
    return (((item)->raw >> 1) & MASK_01_BITS); // Bit 1
}

/**
 * @brief Get the Field Extension (FX) from CAT 021 Item 040 Primary Subfield.
 * 
 * Portable access to the FX bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040 structure.
 * @return uint8_t Value of FX (0: end of item, 1: first extension present)
 */
uint8_t get_cat021_item040_FX(const cat021_item040 *item)
{
    return (((item)->raw) & MASK_01_BITS); // Bit 0
}

/*==============================*/
/* Extension 1 Portable Getters */
/*==============================*/

/**
 * @brief Get the Differential Correction (DCR) from CAT 021 Item 040 First Extension.
 * 
 * Portable access to the DCR bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @return uint8_t Value of DCR (0: No differential correction (ADS-B),
 *                               1: Differential correction (ADS-B))
 */
uint8_t get_cat021_item040_ext1_DCR(const cat021_item040_ext1 *item)
{
    return (((item)->raw) >> 7) & MASK_01_BITS;
}

/**
 * @brief Get the Ground Bit Setting (GBS) from CAT 021 Item 040 First Extension.
 * 
 * Portable access to the GBS bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @return uint8_t Value of GBS (0: Ground Bit not set,
 *                               1: Ground Bit set)
 */
uint8_t get_cat021_item040_ext1_GBS(const cat021_item040_ext1 *item)
{
    return (((item)->raw) >> 6) & MASK_01_BITS;
}

/**
 * @brief Get the Simulated Target (SIM) from CAT 021 Item 040 First Extension.
 * 
 * Portable access to the SIM bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @return uint8_t Value of SIM (0: Actual target report,
 *                               1: Simulated target report)
 */
uint8_t get_cat021_item040_ext1_SIM(const cat021_item040_ext1 *item)
{
    return (((item)->raw) >> 5) & MASK_01_BITS;
}

/**
 * @brief Get the Test Target (TST) from CAT 021 Item 040 First Extension.
 * 
 * Portable access to the TST bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @return uint8_t Value of TST (0: Default,
 *                               1: Test Target)
 */
uint8_t get_cat021_item040_ext1_TST(const cat021_item040_ext1 *item)
{
    return (((item)->raw) >> 4) & MASK_01_BITS;
}

/**
 * @brief Get the Selected Altitude Available (SAA) from CAT 021 Item 040 First Extension.
 * 
 * Portable access to the SAA bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @return uint8_t Value of SAA (0: Equipment capable to provide Selected Altitude,
 *                               1: Equipment not capable to provide Selected Altitude)
 */
uint8_t get_cat021_item040_ext1_SAA(const cat021_item040_ext1 *item)
{
    return (((item)->raw) >> 3) & MASK_01_BITS;
}

/**
 * @brief Get the Confidence Level (CL) from CAT 021 Item 040 First Extension.
 * 
 * Portable access to the CL bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @return uint8_t Value of CL (0: Report valid,
 *                              1: Report suspect,
 *                              2: No information,
 *                              3: Reserved for future use)
 */
uint8_t get_cat021_item040_ext1_CL(const cat021_item040_ext1 *item)
{
    return (((item)->raw) >> 1) & MASK_02_BITS;
}

/**
 * @brief Get the Field Extension (FX) from CAT 021 Item 040 First Extension.
 * 
 * Portable access to the FX bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext1 structure.
 * @return uint8_t Value of FX (0: end of item, 1: second extension present)
 */
uint8_t get_cat021_item040_ext1_FX(const cat021_item040_ext1 *item)
{
    return ((item)->raw) & MASK_01_BITS;
}

/*==============================*/
/* Extension 2 Portable Getters */
/*==============================*/

/**
 * @brief Get the List Lookup Check (LL) from CAT 021 Item 040 Second Extension.
 * 
 * Portable access to the LL bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @return uint8_t Value of LL (0: default,
 *                              1: Target is suspect)
 */
uint8_t get_cat021_item040_ext2_LLC(const cat021_item040_ext2 *item)
{
    return (((item)->raw) >> 6) & MASK_01_BITS;
}

/**
 * @brief Get the Independent Position Check (IP) from CAT 021 Item 040 Second Extension.
 * 
 * Portable access to the IP bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @return uint8_t Value of IP (0: default,
 *                              1: Independent Position Check failed)
 */
uint8_t get_cat021_item040_ext2_IPC(const cat021_item040_ext2 *item)
{
    return (((item)->raw) >> 5) & MASK_01_BITS;
}

/**
 * @brief Get the No-go Bit Status (NO) from CAT 021 Item 040 Second Extension.
 * 
 * Portable access to the NO bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @return uint8_t Value of NO (0: NOGO-bit not set,
 *                              1: NOGO-bit set)
 */
uint8_t get_cat021_item040_ext2_NOGO(const cat021_item040_ext2 *item)
{
    return (((item)->raw) >> 4) & MASK_01_BITS;
}

/**
 * @brief Get the Compact Position Reporting (CP) from CAT 021 Item 040 Second Extension.
 * 
 * Portable access to the CP bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @return uint8_t Value of CP (0: CPR Validation correct),
 *                              1: CPR Validation failed)
 */
uint8_t get_cat021_item040_ext2_CPR(const cat021_item040_ext2 *item)
{
    return (((item)->raw) >> 3) & MASK_01_BITS;
}

/**
 * @brief Get the Local Decoding Position Jump (LD) from CAT 021 Item 040 Second Extension.
 * 
 * Portable access to the LD bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @return uint8_t Value of LD (0: LDPJ not detected,
 *                              1: LDPJ detected)
 */
uint8_t get_cat021_item040_ext2_LDPJ(const cat021_item040_ext2 *item)
{
    return (((item)->raw) >> 2) & MASK_01_BITS;
}

/**
 * @brief Get the Range Check (RCF) from CAT 021 Item 040 Second Extension.
 * 
 * Portable access to the RCF bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @return uint8_t Value of RCF (0: default,
 *                              1: Range Check failed)
 */
uint8_t get_cat021_item040_ext2_RCF(const cat021_item040_ext2 *item)
{
    return (((item)->raw) >> 1) & MASK_01_BITS;
}

/**
 * @brief Get the Field Extension (FX) from CAT 021 Item 040 Second Extension.
 * 
 * Portable access to the FX bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext2 structure.
 * @return uint8_t Value of FX (0: end of item, 1: third extension present)
 */
uint8_t get_cat021_item040_ext2_FX(const cat021_item040_ext2 *item)
{
    return ((item)->raw) & MASK_01_BITS;
}

/*==============================*/
/* Extension 3 Portable Getters */
/*==============================*/

/**
 * @brief Get the raw Total Bits Corrected (TBC) from CAT 021 Item 040 Third Extension.
 * 
 * Portable access to the TBC bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext3 structure.
 * @return uint8_t Raw value of TBC (bit-8 TBC_EP, bits-7/2 TBC_VAL)
 */
uint8_t get_cat021_item040_ext3_TBC(const cat021_item040_ext3 *item)
{
    return (((item)->raw) >> 1) & MASK_07_BITS;
}

/**
 * @brief Get the TBC Element populated (TBC_EP) from CAT 021 Item 040 Third Extension.
 * 
 * Portable access to the TBC_EP bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext3 structure.
 * @return uint8_t Value of TBC_EP (0: element not populated, 1: element populated)
 */
uint8_t get_cat021_item040_ext3_TBC_EP(const cat021_item040_ext3 *item)
{
    return (((item)->raw) >> 7) & MASK_01_BITS;
}

/**
 * @brief Get the TBC Value (TBC_VAL) from CAT 021 Item 040 Third Extension.
 * 
 * Portable access to the TBC_VAL bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext3 structure.
 * @return uint8_t Value of TBC_VAL
 */
uint8_t get_cat021_item040_ext3_TBC_VAL(const cat021_item040_ext3 *item)
{
    return (((item)->raw) >> 1) & MASK_06_BITS;
}

/**
 * @brief Get the Field Extension (FX) from CAT 021 Item 040 Third Extension.
 * 
 * Portable access to the FX bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext3 structure.
 * @return uint8_t Value of FX (0: end of item, 1: fourth extension present)
 */
uint8_t get_cat021_item040_ext3_FX(const cat021_item040_ext3 *item)
{
    return ((item)->raw) & MASK_01_BITS;
}

/*==============================*/
/* Extension 4 Portable Getters */
/*==============================*/

/**
 * @brief Get the raw Maximum Bits Corrected (MBC) from CAT 021 Item 040 Fourth Extension.
 * 
 * Portable access to the MBC bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext4 structure.
 * @return uint8_t Raw value of MBC (bit-8 MBC_EP, bits-7/2 MBC_VAL)
 */
uint8_t get_cat021_item040_ext4_MBC(const cat021_item040_ext4 *item)
{
    return (((item)->raw) >> 1) & MASK_07_BITS;
}

/**
 * @brief Get the MBC Element populated (MBC_EP) from CAT 021 Item 040 Fourth Extension.
 * 
 * Portable access to the MBC_EP bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext4 structure.
 * @return uint8_t Value of MBC_EP (0: element not populated, 1: element populated)
 */
uint8_t get_cat021_item040_ext4_MBC_EP(const cat021_item040_ext4 *item)
{
    return (((item)->raw) >> 7) & MASK_01_BITS;
}

/**
 * @brief Get the MBC Value (MBC_VAL) from CAT 021 Item 040 Fourth Extension.
 * 
 * Portable access to the MBC_VAL bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext4 structure.
 * @return uint8_t Value of MBC_VAL
 */
uint8_t get_cat021_item040_ext4_MBC_VAL(const cat021_item040_ext4 *item)
{
    return (((item)->raw) >> 1) & MASK_06_BITS;
}

/**
 * @brief Get the Field Extension (FX) from CAT 021 Item 040 Fourth Extension.
 * 
 * Portable access to the FX bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item040_ext4 structure.
 * @return uint8_t Value of FX (0: end of item, 1: extension present)
 */
uint8_t get_cat021_item040_ext4_FX(const cat021_item040_ext4 *item)
{
    return ((item)->raw) & MASK_01_BITS;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/



/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT 021 / Item 040 including its extensions.
 *
 * This function prints the values of the main byte and each extension
 * (if present according to the FX bits) to the standard output.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a cat021_item040 structure.
 */
void print_cat021_item040(const cat021_item040 *item)
{
    printf("Category 021 / Item 040 - Target Report Descriptor\n");
    printf("  ATP = %d\n", get_cat021_item040_ATP(item));
    printf("  ARC = %d\n", get_cat021_item040_ARC(item));
    printf("  RC = %d\n", get_cat021_item040_RC(item));
    printf("  RAB = %d\n", get_cat021_item040_RAB(item));
    printf("  FX = %d\n", get_cat021_item040_FX(item));

    if (!get_cat021_item040_FX(item)) return;

    printf("  ext1_DCR = %d", get_cat021_item040_ext1_DCR(item));
    printf("  ext1_GBS = %d", get_cat021_item040_ext1_GBS(item));
    printf("  ext1_SIM = %d", get_cat021_item040_ext1_SIM(item));
    printf("  ext1_TST = %d", get_cat021_item040_ext1_TST(item));
    printf("  ext1_SAA = %d", get_cat021_item040_ext1_SAA(item));
    printf("  ext1_CL = %d", get_cat021_item040_ext1_CL(item));
    printf("  ext1_FX = %d", get_cat021_item040_ext1_FX(item));

    if (!get_cat021_item040_ext1_FX(item)) return;

    printf("  ext2_LLC = %d", get_cat021_item040_ext2_LLC(item));
    printf("  ext2_IPC = %d", get_cat021_item040_ext2_IPC(item));
    printf("  ext2_NOGO = %d", get_cat021_item040_ext2_NOGO(item));
    printf("  ext2_CPR = %d", get_cat021_item040_ext2_CPR(item));
    printf("  ext2_LDPJ = %d", get_cat021_item040_ext2_LDPJ(item));
    printf("  ext2_RCF = %d", get_cat021_item040_ext2_RCF(item));
    printf("  ext2_FX = %d", get_cat021_item040_ext2_FX(item));

    if (!get_cat021_item040_ext2_FX(item)) return;

    printf("  ext3_TBC = %d\n", get_cat021_item040_ext3_TBC(item));
    printf("  ext3_FX = %d\n", get_cat021_item040_ext3_FX(item));

    if(!get_cat021_item040_ext3_FX(item)) return;

    printf("  ext4_MBC = %d\n", get_cat021_item040_ext4_MBC(item));
    printf("  ext4_FX = %d\n\n", get_cat021_item040_ext4_FX(item));
}