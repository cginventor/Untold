#pragma once

#ifdef UT_PLATFORM_WINDOWS
	#ifdef UNTOLD_BUILD_DLL
		#define UNTOLD_API __declspec(dllexport)
	#else
		#define UNTOLD_API __declspec(dllimport)
	#endif
#else
	#error Untold only supports Windows!

#endif