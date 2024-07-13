# Modifications to libgmp to build on Android.
# Copyright (C) 2023 Free Software Foundation, Inc.

# These modifications are part of GNU Emacs.

# GNU Emacs is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or (at
# your option) any later version.

# GNU Emacs is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with GNU Emacs.  If not, see <https://www.gnu.org/licenses/>.

LOCAL_PATH := $(call my-dir)

# Source files in the code directory.
libmps_code_src := code/mps.c

include $(CLEAR_VARS)

# Make sure instructions are generated in ARM mode.  Thumb mode does
# not work very well.

LOCAL_ARM_MODE := arm
LOCAL_SRC_FILES := $(libmps_code_src)

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/code/

LOCAL_CFLAGS := -O2 -pedantic -DPIC
LOCAL_CFLAGS_arm := -fomit-frame-pointer -march=armv7-a -mtune=cortex-a5
LOCAL_CFLAGS_arm64 := -O2 -pedantic -march=armv8-a
LOCAL_CFLAGS_x86_64 := -O2 -pedantic -fomit-frame-pointer -m64 -mtune=k8 \
  -march=k8

# Allow finding the right config.h and gmp-mparam.h.
LOCAL_CFLAGS_arm := -I$(LOCAL_PATH)/android-armv7
LOCAL_CFLAGS_arm64 := -I$(LOCAL_PATH)/android-aarch64
LOCAL_CFLAGS_x86_64 := -I$(LOCAL_PATH)/android-x86_64

# Export this directory.
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH) $(LOCAL_PATH)/code

# Build as a shared library.
LOCAL_MODULE := libmps

include $(BUILD_SHARED_LIBRARY)
