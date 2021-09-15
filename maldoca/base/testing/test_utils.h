// Copyright 2021 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MALDOCA_BASE_TESTING_TEST_UTILS_H_
#define MALDOCA_BASE_TESTING_TEST_UTILS_H_
#include <algorithm>
#include <string>

#include "absl/strings/str_cat.h"
#include "absl/strings/string_view.h"
#include "maldoca/base/file.h"
#include "maldoca/base/get_runfiles_dir.h"

// File name substrings indicating xor-encoding respectively the lack
// thereof.
constexpr char kFileNameXorEncodingIndicator[] = "_xor_0x42_encoded";
constexpr char kFileNameTextprotoIndicator[] = "textproto";

namespace maldoca {
namespace testing {
// Some helper utils for testing
inline std::string OleTestFilename(absl::string_view filename,
                                   absl::string_view subdir = "") {
#if defined(_WIN32)
  constexpr char test_data[] = "testdata\\";
  auto fn = file::JoinPath(GetRunfilesDir(),
                           absl::StrCat(test_data, subdir, filename));
  std::replace(fn.begin(), fn.end(), '/', '\\');
  return fn;
#else
  constexpr char test_data[] = "maldoca/ole/testdata/";
  return ::maldoca::file::JoinPath(maldoca::GetRunfilesDir(),
                                   absl::StrCat(test_data, subdir, filename));
#endif
}

inline std::string ServiceTestFilename(absl::string_view filename) {
#if defined(_WIN32)
  constexpr char test_data[] = "testdata\\";
  auto fn = file::JoinPath(GetRunfilesDir(), absl::StrCat(test_data, filename));
  std::replace(fn.begin(), fn.end(), '/', '\\');
  return fn;
#else
  constexpr char test_data[] = "maldoca/service/testdata/";
  return file::JoinPath(GetRunfilesDir(), absl::StrCat(test_data, filename));
#endif
}

inline absl::Status GetTestContents(const std::string& path,
                                    std::string* contents) {
  // xor decode file if path contains kFileNameXorEncodingIndicator.
  // However, ignore textproto files.
  bool xor_decode_file =
      absl::StrContains(path, kFileNameXorEncodingIndicator) &&
      !absl::StrContains(path, kFileNameTextprotoIndicator);
  return ::maldoca::file::GetContents(path, contents, xor_decode_file);
}

}  // namespace testing
}  // namespace maldoca
#endif  // MALDOCA_BASE_TESTING_TEST_UTILS_H_
