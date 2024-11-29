#pragma once

#ifdef LIN_PLATFORM_WINDOWS
	#ifdef LIN_BUILD_DLL
		#define LIN_API __declspec(dllexport)
	#else
		#define LIN_API __declspec(dllimport)
	#endif
#else
	#error Lin only support Windows.
#endif