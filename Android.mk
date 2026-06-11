LOCAL_PATH := $(call my-dir)
ifeq ($(TARGET_DEVICE),tb375fc)
include $(call all-subdir-makefiles,$(LOCAL_PATH))
endif
