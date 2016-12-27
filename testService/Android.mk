LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES += TestApp.cpp ITestApp.cpp
LOCAL_SHARED_LIBRARIES += libbinder libutils libcutils liblog 
LOCAL_MODULE := libtestapp
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := init.cpp
LOCAL_CFLAGS := -DPLATFORM_ANDROID
LOCAL_MODULE := init
LOCAL_SHARED_LIBRARIES += libtestapp
LOCAL_SHARED_LIBRARIES += liblog
LOCAL_SHARED_LIBRARIES += libutils libbinder libcutils
LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)


