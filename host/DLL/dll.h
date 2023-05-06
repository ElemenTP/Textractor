#pragma once
#ifndef TEXTRACTOR_DLL_H
#define TEXTRACTOR_DLL_H

#ifndef DLL_API
#define DLL_API __declspec(dllexport)
#endif 

#include "../host.h"
#include "../hookcode.h"

extern "C" {
	DLL_API void start(void(*callback)(const wchar_t*, const wchar_t*));

	DLL_API void attach(DWORD processId);

	DLL_API void detach(DWORD processId);

	DLL_API BOOL inserthook(DWORD processId, const wchar_t* command);
}

#endif