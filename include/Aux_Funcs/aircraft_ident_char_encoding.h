/**
 * @file aircraft_ident_char_encoding.h
 * @brief Values and functions to encode/decode the A/C identification chars
 */

#ifndef AIRCRAFT_IDENT_CHAR_ENCODING_H
#define AIRCRAFT_IDENT_CHAR_ENCODING_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Characters codes
 ******************************************************************************/

#define CHAR_A_ENCODING     0x01         /// Char A in binary  = 000001
#define CHAR_B_ENCODING     0x02         /// Char B in binary  = 000010
#define CHAR_C_ENCODING     0x03         /// Char C in binary  = 000011
#define CHAR_D_ENCODING     0x04         /// Char D in binary  = 000100
#define CHAR_E_ENCODING     0x05         /// Char E in binary  = 000101
#define CHAR_F_ENCODING     0x06         /// Char F in binary  = 000110
#define CHAR_G_ENCODING     0x07         /// Char G in binary  = 000111
#define CHAR_H_ENCODING     0x08         /// Char H in binary  = 001000
#define CHAR_I_ENCODING     0x09         /// Char I in binary  = 001001
#define CHAR_J_ENCODING     0x0A         /// Char J in binary  = 001010
#define CHAR_K_ENCODING     0x0B         /// Char K in binary  = 001011
#define CHAR_L_ENCODING     0x0C         /// Char L in binary  = 001100
#define CHAR_M_ENCODING     0x0D         /// Char M in binary  = 001101
#define CHAR_N_ENCODING     0x0E         /// Char N in binary  = 001110
#define CHAR_O_ENCODING     0x0F         /// Char O in binary  = 001111
#define CHAR_P_ENCODING     0x10         /// Char P in binary  = 010000
#define CHAR_Q_ENCODING     0x11         /// Char Q in binary  = 010001
#define CHAR_R_ENCODING     0x12         /// Char R in binary  = 010010
#define CHAR_S_ENCODING     0x13         /// Char S in binary  = 010011
#define CHAR_T_ENCODING     0x14         /// Char T in binary  = 010100
#define CHAR_U_ENCODING     0x15         /// Char U in binary  = 010101
#define CHAR_V_ENCODING     0x16         /// Char V in binary  = 010110
#define CHAR_W_ENCODING     0x17         /// Char W in binary  = 010111
#define CHAR_X_ENCODING     0x18         /// Char X in binary  = 011000
#define CHAR_Y_ENCODING     0x19         /// Char Y in binary  = 011001
#define CHAR_Z_ENCODING     0x1A         /// Char Z in binary  = 011010
#define CHAR_SP_ENCODING    0x20         /// Char SP in binary = 100000
#define CHAR_0_ENCODING     0x30         /// Char 0 in binary  = 110000
#define CHAR_1_ENCODING     0x31         /// Char 1 in binary  = 110001
#define CHAR_2_ENCODING     0x32         /// Char 2 in binary  = 110010
#define CHAR_3_ENCODING     0x33         /// Char 3 in binary  = 110011
#define CHAR_4_ENCODING     0x34         /// Char 4 in binary  = 110100
#define CHAR_5_ENCODING     0x35         /// Char 5 in binary  = 110101
#define CHAR_6_ENCODING     0x36         /// Char 6 in binary  = 110110
#define CHAR_7_ENCODING     0x37         /// Char 7 in binary  = 110111
#define CHAR_8_ENCODING     0x38         /// Char 8 in binary  = 111000
#define CHAR_9_ENCODING     0x39         /// Char 9 in binary  = 111001

#define INVALID_ENCODING 0x00
#define INVALID_CHAR     '\0'

/*******************************************************************************
 * Fast Lookup Table
 ******************************************************************************/ 

static uint8_t char_to_encoding[128] = {
    // Space character
    [32] = CHAR_SP_ENCODING,
    
    // Numbers from 0 to 9
    [48] = CHAR_0_ENCODING,  [49] = CHAR_1_ENCODING,  [50] = CHAR_2_ENCODING,
    [51] = CHAR_3_ENCODING,  [52] = CHAR_4_ENCODING,  [53] = CHAR_5_ENCODING,
    [54] = CHAR_6_ENCODING,  [55] = CHAR_7_ENCODING,  [56] = CHAR_8_ENCODING,
    [57] = CHAR_9_ENCODING,
    
    // Chars from A to Z
    [65] = CHAR_A_ENCODING, [66] = CHAR_B_ENCODING, [67] = CHAR_C_ENCODING,
    [68] = CHAR_D_ENCODING, [69] = CHAR_E_ENCODING, [70] = CHAR_F_ENCODING,
    [71] = CHAR_G_ENCODING, [72] = CHAR_H_ENCODING, [73] = CHAR_I_ENCODING,
    [74] = CHAR_J_ENCODING, [75] = CHAR_K_ENCODING, [76] = CHAR_L_ENCODING,
    [77] = CHAR_M_ENCODING, [78] = CHAR_N_ENCODING, [79] = CHAR_O_ENCODING,
    [80] = CHAR_P_ENCODING, [81] = CHAR_Q_ENCODING, [82] = CHAR_R_ENCODING,
    [83] = CHAR_S_ENCODING, [84] = CHAR_T_ENCODING, [85] = CHAR_U_ENCODING,
    [86] = CHAR_V_ENCODING, [87] = CHAR_W_ENCODING, [88] = CHAR_X_ENCODING,
    [89] = CHAR_Y_ENCODING, [90] = CHAR_Z_ENCODING

    // The remaining values are initialized to '0' (invalid encoding)
};

static const char encoding_to_char[64] = {
    // Chars from A to Z
    [CHAR_A_ENCODING] = 'A', [CHAR_B_ENCODING] = 'B', [CHAR_C_ENCODING] = 'C',
    [CHAR_D_ENCODING] = 'D', [CHAR_E_ENCODING] = 'E', [CHAR_F_ENCODING] = 'F',
    [CHAR_G_ENCODING] = 'G', [CHAR_H_ENCODING] = 'H', [CHAR_I_ENCODING] = 'I',
    [CHAR_J_ENCODING] = 'J', [CHAR_K_ENCODING] = 'K', [CHAR_L_ENCODING] = 'L',
    [CHAR_M_ENCODING] = 'M', [CHAR_N_ENCODING] = 'N', [CHAR_O_ENCODING] = 'O',
    [CHAR_P_ENCODING] = 'P', [CHAR_Q_ENCODING] = 'Q', [CHAR_R_ENCODING] = 'R',
    [CHAR_S_ENCODING] = 'S', [CHAR_T_ENCODING] = 'T', [CHAR_U_ENCODING] = 'U',
    [CHAR_V_ENCODING] = 'V', [CHAR_W_ENCODING] = 'W', [CHAR_X_ENCODING] = 'X',
    [CHAR_Y_ENCODING] = 'Y', [CHAR_Z_ENCODING] = 'Z',

    // Space character
    [CHAR_SP_ENCODING] = ' ',

    // Numbers from 0 to 9
    [CHAR_0_ENCODING] = '0', [CHAR_1_ENCODING] = '1', [CHAR_2_ENCODING] = '2',
    [CHAR_3_ENCODING] = '3', [CHAR_4_ENCODING] = '4', [CHAR_5_ENCODING] = '5',
    [CHAR_6_ENCODING] = '6', [CHAR_7_ENCODING] = '7', [CHAR_8_ENCODING] = '8',
    [CHAR_9_ENCODING] = '9'

    // The remaining values are initialized to '\0' (invalid encoding)
};

#ifdef __cplusplus
}
#endif

#endif // AIRCRAFT_IDENT_CHAR_ENCODING_H