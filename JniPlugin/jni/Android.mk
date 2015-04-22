include $(CLEAR_VARS)

# override strip command to strip all symbols from output library; no need to ship with those..
cmd-strip = $(TOOLCHAIN_PREFIX)strip $1 

LOCAL_ARM_MODE  := arm
LOCAL_PATH      := $(NDK_PROJECT_PATH)/jni
LOCAL_LDLIBS    := -llog
LOCAL_MODULE    := libJniPlugin
LOCAL_CFLAGS    := -Werror
LOCAL_SRC_FILES := jni.cpp
LOCAL_LDLIBS    := -llog

include $(BUILD_SHARED_LIBRARY)
$(LOCAL_PATH)/../lib/$(notdir $(LOCAL_MODULE)): $(LOCAL_MODULE)
	ls
	cp $(LOCAL_PATH)/../lib/$(notdir $(LOCAL_MODULE)) $(LOCAL_PATH)/../../
