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
mps_code_src := code/mps.c

include $(CLEAR_VARS)

# Make sure instructions are generated in ARM mode.  Thumb mode does
# not work very well.

LOCAL_SRC_FILES := $(mps_code_src)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/code/
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/code/

LOCAL_CFLAGS := -DCONFIG_VAR_COOL

# Export this directory.
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LOCAL_PATH) $(LOCAL_PATH)/code

# Build as a shared library.
LOCAL_MODULE := mps

include $(BUILD_SHARED_LIBRARY)
