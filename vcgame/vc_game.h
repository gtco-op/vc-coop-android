#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define VALIDATE_SIZE(struc, size) static_assert(sizeof(struc) == size, "Invalid structure size of " #struc)
extern uintptr_t g_libGTAVC;

#include "CVector.h"