#pragma once

#define VALIDATE_SIZE(struc, size) static_assert(sizeof(struc) == size, "Invalid structure size of " #struc)

extern uintptr_t g_libGTAVC;

bool InitGameLibrary();