#pragma once
#ifdef LIB_EXPORTS
#define LIBTV_API __declspec(dllexport)
#else
#define LIBTV_API __declspec(dllimport)
#endif // LIB_EXPORTS
