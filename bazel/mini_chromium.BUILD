# Copyright 2021 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

licenses(["notice"])

package(
    default_visibility = ["//visibility:public"],
)

MINI_CHROMIUM_HDRS = [
    "base/atomicops.h",
    "base/auto_reset.h",
    "base/bit_cast.h",
    "base/check.h",
    "base/check_op.h",
    "base/compiler_specific.h",
    "base/cxx17_backports.h",
    "base/files/file_path.h",
    "base/files/scoped_file.h",
    "base/format_macros.h",
    "base/logging.h",
    "base/macros.h",
    "base/memory/free_deleter.h",
    "base/metrics/histogram_functions.h",
    "base/metrics/histogram_macros.h",
    "base/metrics/persistent_histogram_allocator.h",
    "base/notreached.h",
    "base/numerics/checked_math.h",
    "base/numerics/clamped_math.h",
    "base/numerics/safe_conversions.h",
    "base/numerics/safe_math.h",
    "base/posix/eintr_wrapper.h",
    "base/process/process_metrics.h",
    "base/rand_util.h",
    "base/scoped_generic.h",
    "base/strings/string_number_conversions.h",
    "base/strings/string_piece.h",
    "base/strings/string_util.h",
    "base/strings/stringprintf.h",
    "base/strings/utf_string_conversions.h",
    "base/synchronization/lock.h",
    "base/threading/thread_local_storage.h",
    "build/build_config.h",
]

MINI_CHROMIUM_SRCS = [
    "base/compiler_specific.h",
    "base/debug/alias.cc",
    "base/debug/alias.h",
    "base/files/file_path.cc",
    "base/files/file_util.h",
    "base/files/scoped_file.cc",
    "base/logging.cc",
    "base/memory/scoped_policy.h",
    "base/numerics/checked_math_impl.h",
    "base/numerics/clamped_math_impl.h",
    "base/numerics/safe_math_clang_gcc_impl.h",
    "base/numerics/safe_math_shared_impl.h",
    "base/process/memory.cc",
    "base/process/memory.h",
    "base/rand_util.cc",
    "base/scoped_clear_last_error.h",
    "base/strings/string_number_conversions.cc",
    "base/strings/stringprintf.cc",
    "base/strings/sys_string_conversions.h",
    "base/strings/utf_string_conversion_utils.cc",
    "base/strings/utf_string_conversion_utils.h",
    "base/strings/utf_string_conversions.cc",
    "base/synchronization/condition_variable.h",
    "base/synchronization/lock.cc",
    "base/synchronization/lock_impl.h",
    "base/template_util.h",
    "base/third_party/icu/icu_utf.cc",
    "base/third_party/icu/icu_utf.h",
    "base/threading/thread_local_storage.cc",
]

MINI_CHROMIUM_LINUX_HDRS = [
    "base/posix/safe_strerror.h",
]

MINI_CHROMIUM_LINUX_SRCS = [
    "base/files/file_util_posix.cc",
    "base/posix/safe_strerror.cc",
    "base/process/process_metrics_posix.cc",
    "base/strings/string_util_posix.h",
    "base/synchronization/condition_variable_posix.cc",
    "base/synchronization/lock_impl_posix.cc",
    "base/threading/thread_local_storage_posix.cc",
]

ALL_HDRS_SRCS = MINI_CHROMIUM_SRCS + MINI_CHROMIUM_LINUX_SRCS + \
                MINI_CHROMIUM_HDRS + MINI_CHROMIUM_LINUX_HDRS

UNIQUE_HDRS_SRCS = dict(zip(ALL_HDRS_SRCS, ALL_HDRS_SRCS)).keys()

# This is the actual code being built using base as the first dir in the include
cc_library(
    name = "base_lib",
    srcs = UNIQUE_HDRS_SRCS,
    textual_hdrs = [
        "base/atomicops_internals_atomicword_compat.h",
        "base/atomicops_internals_portable.h",
        "base/numerics/safe_conversions_impl.h",
        "base/numerics/safe_math_arm_impl.h",
        "base/numerics/safe_conversions_arm_impl.h",
        "base/sys_byteorder.h",
    ],
)

# This is a trick so we can add mini_chromium/ as the first dir in the include
# path for the rest of Maldoca.
cc_library(
    name = "base",
    hdrs = MINI_CHROMIUM_HDRS +
           MINI_CHROMIUM_LINUX_HDRS,
    include_prefix = "mini_chromium",
    textual_hdrs = [
        "base/atomicops_internals_atomicword_compat.h",
        "base/atomicops_internals_portable.h",
        "base/numerics/safe_conversions_impl.h",
        "base/numerics/safe_math_arm_impl.h",
        "base/numerics/safe_conversions_arm_impl.h",
        "base/sys_byteorder.h",
    ],
    deps = [":base_lib"],
)
