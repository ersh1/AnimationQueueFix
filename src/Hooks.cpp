#include "Hooks.h"
#include "Offsets.h"

namespace Hooks
{
	void Install()
	{
		logger::info("Hooking...");

		QueueFixHook::Hook();

		logger::info("...success");
	}

	void QueueFixHook::LoadAnim(void* a1, void* a2)
	{
		_LoadAnim(a1, a2);

		void* animationFileManager = *g_animationFileManager;

		RE::BSSpinLock* lock = (RE::BSSpinLock*)((uintptr_t)animationFileManager + 0x14);
		RE::BSSpinLockGuard locker(*lock);

		AnimationFileManagerSingleton_UpdateQueue(animationFileManager);
	}

}
