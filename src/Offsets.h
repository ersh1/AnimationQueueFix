#pragma once

static void** g_animationFileManager = (void**)REL::VariantID(520994, 407512, 0x30A9F50).address();  // 2F51EC0, 2FECA40, 30A9F50

typedef void (*tAnimationFileManagerSingleton_UpdateQueue)(void* a_this);
static REL::Relocation<tAnimationFileManagerSingleton_UpdateQueue> AnimationFileManagerSingleton_UpdateQueue{ REL::VariantID(63080, 63995, 0xB45AB0) };  // B0ACD0, B2F650, B45AB0
