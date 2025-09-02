#ifndef C_LIBRARY_TEMPLATE_H
#define C_LIBRARY_TEMPLATE_H

#if defined(_WIN32) && defined(C_LIBRARY_TEMPLATE_DLL)
#ifdef C_LIBRARY_TEMPLATE_EXPORTS
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif
#else
#define EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

EXPORT void c_library_template_init(void);
EXPORT void c_library_template_cleanup(void);

#ifdef __cplusplus
}
#endif

#endif // C_LIBRARY_TEMPLATE_H
