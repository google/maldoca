// Copyright 2021 Google LLC
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

#ifdef MALDOCA_CHROME

namespace maldoca {
namespace {

static std::string& failed_encoding() {
  thread_local std::string failed_encoding("");
  return failed_encoding;
}

void SetFailedEncoding(const char* encoding) {
  failed_encoding() = std::string(encoding);
}

std::string* GetFailedEncoding() { return &failed_encoding(); }

void ResetFailedEncoding() { failed_encoding().clear(); }
}  // namespace
}  // namespace maldoca

#endif  // MALDOCA_CHROME
