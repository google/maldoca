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

load("@rules_cc//cc:defs.bzl", "cc_library")

package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "icuuc",
    srcs = glob(["*.cpp"],
    ),
    hdrs = glob([
        "*.h",
    ]),
    include_prefix = "icu4c/source/common",
    copts = [
        # Required when compiling code in common and when linking statically:
        # https://unicode-org.github.io/icu/userguide/icu/howtouseicu.html#c-with-your-own-build-system
        "-DU_COMMON_IMPLEMENTATION",
        "-DU_STATIC_IMPLEMENTATION",
    ] + select({
        "@platforms//os:windows": [
            "/utf-8",
            "/DLOCALE_ALLOW_NEUTRAL_NAMES=0",
        ],
        "//conditions:default": [],
    }),
    deps = [
        ":headers",
        "@icu_data//:stubdata",
    ],
)

cc_library(
    name = "headers",
    hdrs = glob(["unicode/*.h"]),
    include_prefix = "icu4c/source/common",
    includes = ["."],
    local_defines = [
        "U_COMMON_IMPLEMENTATION",
    ],
)
