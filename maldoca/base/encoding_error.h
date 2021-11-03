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

#ifndef MALDOCA_BASE_ENCODING_ERROR_H_
#define MALDOCA_BASE_ENCODING_ERROR_H_

#include <string>

namespace maldoca {

// Returns the last failed encoding.
std::string GetFailedEncoding();

// Sets the failed encoding.
void SetFailedEncoding(const char* encoding);

// Deletes any set encoding.
void ResetFailedEncoding();
}  // namespace maldoca

#endif  // MALDOCA_BASE_ENCODING_ERROR_H_
