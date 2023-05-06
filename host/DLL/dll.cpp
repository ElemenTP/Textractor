#include "dll.h"

void(*cbk_reg)(const wchar_t*, const wchar_t*) = nullptr;

void start(void(*callback)(const wchar_t*, const wchar_t*)) {
	cbk_reg = callback;
	Host::Start([](auto) {}, [](auto) {}, [](auto&) {}, [](auto&) {},
		[](TextThread& thread, std::wstring& output) {
			static wchar_t buf[500] = {};
			swprintf_s(buf, L"[%I64X:%I32X:%I64X:%I64X:%I64X:%s:%s]",
				thread.handle,
				thread.tp.processId,
				thread.tp.addr,
				thread.tp.ctx,
				thread.tp.ctx2,
				thread.name.c_str(),
				HookCode::Generate(thread.hp, thread.tp.processId).c_str());
			cbk_reg(buf, output.c_str());
			return false;
		}
	);
}

void attach(DWORD processId) {
	Host::InjectProcess(processId);
}

void detach(DWORD processId) {
	Host::DetachProcess(processId);
}

BOOL inserthook(DWORD processId, const wchar_t* command) {
	auto hp = HookCode::Parse(command);
	if (hp.has_value()) {
		Host::InsertHook(processId, hp.value());
		return TRUE;
	}
	else {
		return FALSE;
	}
}
