// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "maldoca/base/encoding_error.h"

#include <string>

#include "absl/synchronization/mutex.h"

namespace maldoca {
namespace {

ABSL_CONST_INIT absl::Mutex FailedEncodingMutex(absl::kConstInit);

// Maximum size for failed encodings without \0.
constexpr uint32_t kMaxFailedEncodingSize = 1023;

#ifndef MALDOCA_CHROME
thread_local char failed_encoding[kMaxFailedEncodingSize + 1];
#else
// This code is not fully thread-safe as they all use a shared
// "failed_encoding" variable. thread_local is not usable in Chrome due to
// crbug.com/1261617.
static char failed_encoding[kMaxFailedEncodingSize + 1];
#endif  // MALDOCA_CHROME

}  // namespace

std::string GetFailedEncoding() {
#ifdef MALDOCA_CHROME
  absl::MutexLock lock(&FailedEncodingMutex);
#endif  // MALDOCA_CHROME
  return std::string(failed_encoding);
}

void SetFailedEncoding(const char* encoding) {
#ifdef MALDOCA_CHROME
  absl::MutexLock lock(&FailedEncodingMutex);
#endif  // MALDOCA_CHROME
  strncpy(failed_encoding, encoding, kMaxFailedEncodingSize);
  // Ensure string truncation.
  failed_encoding[kMaxFailedEncodingSize] = '\0';
}

void ResetFailedEncoding() { SetFailedEncoding(""); }
}  // namespace maldoca
