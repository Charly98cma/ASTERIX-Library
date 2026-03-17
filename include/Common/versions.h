/**
 * @file versions.h
 * @brief Configuration header to manage the target category of the library
 */

#ifndef VERSIONS_H
#define VERSIONS_H

#ifdef __cplusplus
extern "C" {
#endif

/* ================== Category 021 - ADS-B Target Reports ================== */

#ifndef EDITION_NUMBER_I021
    #define EDITION_NUMBER_I021   2
#endif

#ifndef VERSION_NUMBER_I021 
    #define VERSION_NUMBER_I021   7
#endif

#ifndef EDITION_NUMBER_I021_RE
    #define EDITION_NUMBER_I021_RE   2
#endif

#ifndef VERSION_NUMBER_I021_RE
    #define VERSION_NUMBER_I021_RE   2
#endif

/* =============== Category 034 - Mono Radar Service Messages ============== */

#ifndef EDITION_NUMBER_I034
    #define EDITION_NUMBER_I034   1
#endif

#ifndef VERSION_NUMBER_I034 
    #define VERSION_NUMBER_I034   29
#endif

/* ========================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* VERSIONS_H */
