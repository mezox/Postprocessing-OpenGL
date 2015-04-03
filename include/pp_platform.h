#ifndef PP_PLATFORM
#define PP_PLATFORM

#ifdef _WIN32
	#define PP_SYS_WINDOWS
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>

	#ifndef NOMINMAX
		#define NOMINMAX
	#endif

#elif defined (__linux__)
	#define PP_SYS_LINUX
#elif defined (__APPLE__)
	#define PP_SYS_MACOS
#else
	#error System not supported
#endif

#if !defined(PP_STATIC_BUILD)
	#ifdef PP_SYS_WINDOWS
		#ifdef PP_NONCLIENT_BUILD
			#define PP_API __declspec(dllexport)
		#else
			#define PP_API __declspec(dllimport)
		#endif

		//Visual c++ compiler warning C42251 disable
		#ifdef _MSC_VER
			#pragma warning(disable : 4251)
		#endif

	#elif defined(PP_SYS_LINUX) || defined(PP_SYS_MACOS)
		#ifdef __GNUC__ >= 4
			#define PP_API __attribute__ ((__visibility__("default")))
		#else
			#define PP_API PP_API
		#endif
	#endif
#else
	#define PP_API PP_API
#endif

#endif