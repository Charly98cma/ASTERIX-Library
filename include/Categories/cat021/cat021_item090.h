/**
 * @file cat021_item090.h
 * @brief Definition of CAT 021 Item 090, and related functions and values
 */

#ifndef CAT021_ITEM090_H
#define CAT021_ITEM090_H

#include <stdint.h>
#include "visibility.h"

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
 * Macros
 ******************************************************************************/

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item090_ext1
 * @brief First extension of the Category 021 / Item 090
 */
typedef struct cat021_item090_ext1 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Navigation Integrity Category for Barometric Altitude
            uint8_t NICbaro    :1;
            /// @brief Surveillance (V1) or Source (V2+) Integrity Level
            uint8_t SIL         :2;
            /// @brief Navigation Accuracy Category for Position
            uint8_t NACp        :4;
            /**
             * @brief Field extension
             * 
             * = 0 end of data item | = 1 next extension
             */
            uint8_t FX          :1;
        };
    };
} cat021_item090_ext1;

/**
 * @typedef cat021_item090_ext1
 * @brief Second extension of the Category 021 / Item 090
 */
typedef struct cat021_item090_ext2 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Spare bits-8/7, set to 0
            uint8_t spare   :2;
            /**
             * @brief SIL-Supplement
             * 
             * = 0: measured per flight-hour | = 1: measured per sample
            */
            uint8_t SILS    :1;
            /// @brief Horizontal Position System Design Assurance Level
            uint8_t SDA     :2;
            /// @brief Geometric Altitude Accuracy
            uint8_t GVA     :2;
            /**
             * @brief Field extension
             * 
             * = 0 end of data item | = 1 next extension
             */
            uint8_t FX      :1;
        };
    };
} cat021_item090_ext2;

/**
 * @typedef cat021_item090_ext1
 * @brief Third extension of the Category 021 / Item 090
 */
typedef struct cat021_item090_ext3 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /** 
             *  @brief Position Integrity Category (check EUROCONTROL table for values)
             *
             *  (check EUROCONTROL conversion table for values explanation)
             */
            uint8_t PIC     :4;
            /// @brief Spare bits-4/2, set to 0
            uint8_t spare   :3;
            /**
             * @brief Field extension
             * 
             * = 0 end of data item | = 1 next extension
             */
            uint8_t FX      :1;
        };
    };
} cat021_item090_ext3;

/**
 * @typedef cat021_item090
 * @brief Category 021 / Item 090 - Quality Indicators
 * 
 * ADS-B quality indicators transmitted by a/c according to MOPS version.
 */
typedef struct cat021_item090 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /**
             * @brief Navigation Uncertainty Category for velocity (NUCr)
             * or the Navigation Accuracy Category for Velocity (NACv)
             */
            uint8_t NUCrNACv       :3;
            /**
             * @brief Navigation Uncertainty Category for Position (NUCp)
             * or Navigation Integrity Category (NIC).
             */
            uint8_t NUCp_NIC        :3;
            /**
             * @brief Field extension
             * 
             * = 0 end of data item | = 1 next extension
             */
            uint8_t FX              :1;
        };
    };
    /// @brief First extension subfield (1 byte)
    cat021_item090_ext1 ext1;
    /// @brief Second extension subfield (1 byte)
    cat021_item090_ext2 ext2;
    /// @brief Third extension subfield (1 byte)
    cat021_item090_ext3 ext3;
} cat021_item090;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN  BYTE =============================== */

/**
 * @brief Get the value of NUCr or NACv from Cat 021 Item 090
 * 
 * Returns the Navigation Uncertainty Category for velocity (NUCr) or
 * the Navigation Accuracy Category for Velocity (NACv).
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to cat021_item090 structure item Pointer to cat021_item090 structure
 * @return uint8_t Value of NUCr or NACv (see MOPS Version and conversion table)
 */
ASTERIX_API uint8_t get_cat021_item090_NUCr_NACv(const cat021_item090 * item);

/**
 * @brief Get the value of NUCp or NIC from Cat 021 Item 090
 * 
 * Returns the Navigation Uncertainty Category for Position (NUCp) or
 * Navigation Integrity Category (NIC).
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to cat021_item090 structure 
 * @return uint8_t Value of NUCp or NIC (see MOPS Version and conversion table)
 */
ASTERIX_API uint8_t get_cat021_item090_NUCp_NIC(const cat021_item090 * item);

/**
 * @brief Get the value of Field Extension (FX) from Cat 021 Item 090
 * 
 * @param item Pointer to cat021_item090 structure 
 * @return uint8_t Value of FX (0: end of item, 1: first extension present)
 */
ASTERIX_API uint8_t get_cat021_item090_FX(const cat021_item090 * item);


/* ============================= FIRST EXTENSION ============================ */

/**
 * @brief Get the value of NIC for Barometric Altitude (NICbaro) from Cat 021
 *        Item 090 First Extension
 * 
 * @param item Pointer to cat021_item090_ext1 structure 
 * @return uint8_t Value of NICbaro (check conversion table)
 */
ASTERIX_API uint8_t get_cat021_item0900_ext1_NICbaro(const cat021_item090_ext1 * item);

/**
 * @brief Get the value of Surveillance (V1) or Source (V2+) Integrity Level
 *        from Cat 021 Item 090 First Extension
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to cat021_item090_ext1 structure 
 * @return uint8_t Value of SIL (check conversion table)
 */
ASTERIX_API uint8_t get_cat021_item0900_ext1_SIL(const cat021_item090_ext1 * item);

/**
 * @brief Get the value of Navigation Accuracy Category for Position (NACp)
 *        from Cat 021 Item 090 First Extension
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to cat021_item090_ext1 structure 
 * @return uint8_t Value of NACp (check conversion table)
 */
ASTERIX_API uint8_t get_cat021_item0900_ext1_NACp(const cat021_item090_ext1 * item);

/**
 * @brief Get the value of Field Extension (FX) from Cat 021 Item 090 First Extension
 * 
 * @param item Pointer to cat021_item090_ext1 structure 
 * @return uint8_t Value of FX (0: end of item, 1: second extension present)
 */
ASTERIX_API uint8_t get_cat021_item0900_ext1_FX(const cat021_item090_ext1 * item);

/* ============================ SECOND EXTENSION ============================ */

/**
 * @brief Get the SIL-Supplement (SILS) from Cat 021 Item 090 Second Extension
 * 
 * @param item Pointer to cat021_item090_ext2 structure 
 * @return uint8_t Value of SIL-Supplement (0: measured per flight-hour,
 *                                          1: measured per sample)
 */
ASTERIX_API uint8_t get_cat021_item0900_ext2_SILS(const cat021_item090_ext2 * item);

/**
 * @brief Get the Horizontal Position System Design Assurance Level (SDA)
 *        from Cat 021 Item 090 Second Extension
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to cat021_item090_ext2 structure 
 * @return uint8_t Value of SDA (check conversion table)
 */
ASTERIX_API uint8_t get_cat021_item0900_ext2_SDA(const cat021_item090_ext2 * item);

/**
 * @brief Get the Geometric Altitude Accuracy (GVA) from Cat 021 Item 090 Second Extension
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to cat021_item090_ext2 structure 
 * @return uint8_t Value of GVA (check conversion table)
 */
ASTERIX_API uint8_t get_cat021_item0900_ext2_GVA(const cat021_item090_ext2 * item);

/**
 * @brief Get the value of Field Extension (FX) from Cat 021 Item 090 Second Extension
 * 
 * @param item Pointer to cat021_item090_ext2 structure 
 * @return uint8_t Value of FX (0: end of item, 1: third extension present)
 */
ASTERIX_API uint8_t get_cat021_item0900_ext2_FX(const cat021_item090_ext2 * item);

/* ============================ THIRD EXTENSION ============================  */

/**
 * @brief Get the Position Integrity Category (PIC) from Cat 021 Item 090 Third Extension
 * 
 * Value used to interpret the other values of this item, referencing the
 * corresponding conversion table.
 * 
 * @param item Pointer to cat021_item090_ext3 structure 
 * @return uint8_t Value of PIC
 */
ASTERIX_API uint8_t get_cat021_item0900_ext3_PIC(const cat021_item090_ext3 * item);

/**
 * @brief Get the value of Field Extension (FX) from Cat 021 Item 090 Third Extension
 * 
 * @param item Pointer to cat021_item090_ext3 structure 
 * @return uint8_t Value of FX (0: end of item, 1: next extension present)
 */
ASTERIX_API uint8_t get_cat021_item0900_ext3_FX(const cat021_item090_ext3 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

/**
 * @brief Set the value for NUCr or NACv into Cat 021 Item 090
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to cat021_item090 structure item
 * @param value New NUCr or NACv value (see MOPS Version and conversion table)
 */
ASTERIX_API void set_cat021_item09_NUCrNACv(cat021_item090 * item, uint8_t value);

/**
 * @brief Set the value for NUCp or NIC into Cat 021 Item 090
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to cat021_item090 structure 
 * @param value New NUCp or NIC value (see MOPS Version and conversion table)
 */
ASTERIX_API void set_cat021_item09_NUCp_NIC(cat021_item090 * item, uint8_t value);

/**
 * @brief Set the value of Field Extension (FX) into Cat 021 Item 090
 * 
 * @param item Pointer to cat021_item090 structure 
 * @param value New value of FX (0: end of item, 1: first extension present)
 */
ASTERIX_API void set_cat021_item09_FX(cat021_item090 * item, uint8_t value);

/* ============================= FIRST EXTENSION ============================ */

/**
 * @brief Get the value of NIC for Barometric Altitude (NICbaro) from Cat 021
 *        Item 090 First Extension
 * 
 * @param item Pointer to cat021_item090_ext1 structure 
 * @param value New NICbaro value (check conversion table)
 */

ASTERIX_API void set_cat021_item090_ext1_NICbaro(cat021_item090_ext1 * item, uint8_t value);

/**
 * @brief Get the value of Surveillance (V1) or Source (V2+) Integrity Level
 *        from Cat 021 Item 090 First Extension
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to cat021_item090_ext1 structure 
 * @param value New SIL value (check conversion table)
 */
ASTERIX_API void set_cat021_item090_ext1_SIL(cat021_item090_ext1 * item, uint8_t value);

/**
 * @brief Get the value of Navigation Accuracy Category for Position (NACp)
 *        from Cat 021 Item 090 First Extension
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to cat021_item090_ext1 structure 
 * @param value New NACp value (check conversion table)
 */
ASTERIX_API void set_cat021_item090_ext1_NACp(cat021_item090_ext1 * item, uint8_t value);

/**
 * @brief Set the value of Field Extension (FX) into Cat 021 Item 090 First Extension
 * 
 * @param item Pointer to cat021_item090_ext1 structure 
 * @param value New FX value (0: end of item, 1: second extension present)
 */
ASTERIX_API void set_cat021_item090_ext1_FX(cat021_item090_ext1 * item, uint8_t value);

/* ============================ SECOND EXTENSION ============================ */

/**
 * @brief Get the SIL-Supplement (SILS) from Cat 021 Item 090 Second Extension
 * 
 * @param item Pointer to cat021_item090_ext2 structure 
 * @param value New SIL-Supplement value (0: measured per flight-hour,
 *                                        1: measured per sample)
 */
ASTERIX_API void set_cat021_item090_ext2_SILS(cat021_item090_ext2 * item, uint8_t value);

/**
 * @brief Get the Horizontal Position System Design Assurance Level (SDA)
 *        from Cat 021 Item 090 Second Extension
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to cat021_item090_ext2 structure
 * @param value New SDA value (check conversion table)  
 */
ASTERIX_API void set_cat021_item090_ext2_SDA(cat021_item090_ext2 * item, uint8_t value);

/**
 * @brief Get the Geometric Altitude Accuracy (GVA) from Cat 021 Item 090 Second Extension
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to cat021_item090_ext2 structure
 * @param value New GVA value (check conversion table)
 */
ASTERIX_API void set_cat021_item090_ext2_GVA(cat021_item090_ext2 * item, uint8_t value);

/**
 * @brief Set the value of Field Extension (FX) into Cat 021 Item 090 Second Extension
 * 
 * @param item Pointer to cat021_item090_ext2 structure 
 * @param value New value of FX (0: end of item, 1: third extension present)
 */
ASTERIX_API void set_cat021_item090_ext2_FX(cat021_item090_ext2 * item, uint8_t value);

/* ============================ THIRD EXTENSION ============================  */

/**
 * @brief Set the Position Integrity Category (PIC) into Cat 021 Item 090 Third Extension
 * 
 * Apart from the “PIC” item, all items are defined as per the respective link
 * technology protocol version (“MOPS version”, see I021/210).
 * 
 * @param item Pointer to cat021_item090_ext3 structure
 * @param value New PIC value between 0 and 15 (check conversion table)
 */
ASTERIX_API void set_cat021_item090_ext3_PIC(cat021_item090_ext3 * item, uint8_t value);

/**
 * @brief Set the value of Field Extension (FX) into Cat 021 Item 090 Third Extension
 * 
 * @param item Pointer to cat021_item090_ext3 structure 
 * @param value New value of FX (0: end of item, 1: next extension present)
 */
ASTERIX_API void set_cat021_item090_ext3_FX(cat021_item090_ext3 * item, uint8_t value);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Count the number of extensions present in the CAT 021 Item 090.
 * 
 * Evaluates each FX bit to determine the number of present extensions.
 * 
 * @param item Pointer to the main cat021_item090 structure.
 * 
 * @return uint8_t Number of present extensions (0 to 3).
 */
ASTERIX_API uint8_t count_cat021_item090_extensions(const cat021_item090 *item);

/**
 * @brief Print the contents of CAT021 Item 090 and its extensions.
 * 
 * @param item Pointer to cat021_item090 structure.
 */
ASTERIX_API void print_cat021_item090(const cat021_item090 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM090_H */