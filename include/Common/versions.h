/**
 * @file versions.h
 * @brief Configuration header to manage the target category of the library
 */

#ifndef VERSIONS_H
#define VERSIONS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Category 021 - ADS-B Target Reports */
#ifndef CAT021_ED
    #define CAT021_ED   2
#endif // CAT021_ED
#ifndef CAT021_VN 
    #define CAT021_VN   4
#endif // CAT021_VN


#ifdef __cplusplus
}
#endif

#endif // VERSIONS_H