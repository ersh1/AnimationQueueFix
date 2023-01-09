#pragma once
#include "Offsets.h"

namespace Hooks
{
	class QueueFixHook
	{
	public:
		static void Hook()
		{
			REL::Relocation<uintptr_t> hook{ REL::VariantID(62584, 63517, 0xB245D0) };  // AE9A70, B0DE90, B245D0   BSResource__EntryDB_BShkbHkxDB__DBTraits_::Func3
			
			SKSE::AllocTrampoline(14);
			auto& trampoline = SKSE::GetTrampoline();

			_LoadAnim = trampoline.write_call<5>(hook.address() + 0x2B, LoadAnim);
		}

	private:
		static void LoadAnim(void* a1, void* a2);

		static inline REL::Relocation<decltype(LoadAnim)> _LoadAnim;
	};

	void Install();
}
