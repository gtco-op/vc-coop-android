#include <android/log.h>
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, "AXL", __VA_ARGS__)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "vcgame/vc_game.h"