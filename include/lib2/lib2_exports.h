#ifndef _LIB2_SHARED_EXPORTS_H__
#define _LIB2_SHARED_EXPORTS_H__

#ifdef _WIN32
    #ifdef LIB2_DEFINE_EXPORTS
        #define LIB2_SHARED_EXPORT __declspec(dllexport)
    #else
        #define LIB2_SHARED_EXPORT __declspec(dllimport)
    #endif
#else
    #define LIB2_SHARED_EXPORT
#endif

#endif /* _SHARED_EXPORTS_H__ */
