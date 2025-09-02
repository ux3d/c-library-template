#ifndef C_LIBRARY_TEMPLATE_H
#define C_LIBRARY_TEMPLATE_H

#if defined(_WIN32) && defined(C_LIBRARY_TEMPLATE_DLL)
#ifdef C_LIBRARY_TEMPLATE_EXPORTS
#define C_LIBRARY_TEMPLATE_API __declspec(dllexport)
#else
#define C_LIBRARY_TEMPLATE_API __declspec(dllimport)
#endif
#else
#define C_LIBRARY_TEMPLATE_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

C_LIBRARY_TEMPLATE_API void c_library_template_init(void);
C_LIBRARY_TEMPLATE_API void c_library_template_cleanup(void);

#ifdef __cplusplus
}
#endif

#endif // C_LIBRARY_TEMPLATE_H
