#pragma once

#ifdef RS_PLATFORM_WINDOWS
	#ifdef RS_BUILD_DLL
		#define ROBLES_API __declspec(dllexport)
	#else
		#define ROBLES_API __declspec(dllimport)
	#endif // RS_BUILD_DLL
#else
	#error Robles is only available on Windows devices.
#endif // RS_PLATFORM_WINDOWS
