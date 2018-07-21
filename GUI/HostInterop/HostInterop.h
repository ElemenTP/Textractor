#pragma once
#include "../../texthook/hookman.h"
#include "../../texthook/textthread.h"
#include "../../texthook/host.h"

using namespace System;

namespace HostInterop
{
	public ref struct Host abstract sealed
	{
		static void Open() { OpenHost(); }
		static bool Start() { return StartHost(); }
		static void Close() { CloseHost(); }
		//static void InitHookManager(HookManager uninit) { uninit.native = GetHostHookManager(); }
		static bool InjectProcessById(DWORD pid) { return ::InjectProcessById(pid); }
		static bool DetachProcessById(DWORD pid) { return ::DetachProcessById(pid); }
		//static bool InsertHook(DWORD pid, HookParam hp, std::string name) { return ::InsertHook(pid, hp.GetNative()); };
		static bool RemoveHook(DWORD pid, DWORD addr) { return ::RemoveHook(pid, addr); }
	};

	public ref struct HookManager
	{
	//internal:
		::HookManager* native;
	};

	public ref struct TextThread
	{

	//internal:
		::TextThread* native;
	};

	public ref struct HookParam
	{

	//internal:
		//::HookParam GetNative();
	};

	public ref struct ThreadParam
	{

	};
}
