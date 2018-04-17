LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := coop
LOCAL_LDLIBS += -llog
FILE_LIST += $(wildcard $(LOCAL_PATH)/vcgame/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/src/*.cpp)
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_CPPFLAGS += -w -fpack-struct=1 -Wall -O2 -std=c++11
include $(BUILD_SHARED_LIBRARY)