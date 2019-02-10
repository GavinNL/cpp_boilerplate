#ifndef _LIB1_SHARED_EXPORTS_H__
#define _LIB1_SHARED_EXPORTS_H__

#ifdef _WIN32
    #ifdef LIB1_DEFINE_EXPORTS
        #define LIB1_SHARED_EXPORT __declspec(dllexport)
    #else
        #define LIB1_SHARED_EXPORT __declspec(dllimport)
    #endif
#else
    #define LIB1_SHARED_EXPORT
#endif

#endif /* _SHARED_EXPORTS_H__ */
