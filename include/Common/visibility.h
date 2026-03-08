/**
 * @file visibility.h
 * @brief Macros to setup the visibility of the library functions
 */

#ifndef VISIBILITY_H
#define VISIBILITY_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
    #ifdef ASTERIX_BUILD_DLL
        /* When building the DLL */
        #define ASTERIX_LIB __declspec(dllexport)
    #else
        /* When using the DLL */
        #define ASTERIX_LIB __declspec(dllimport)
    #endif
#else
    /* On Linux and macOS, we use GCC visibility */
    #define ASTERIX_LIB __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
}
#endif

#endif /* VISIBILITY_H */
