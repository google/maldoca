rem Copyright 2021 Google LLC
rem
rem Licensed under the Apache License, Version 2.0 (the "License");
rem you may not use this file except in compliance with the License.
rem You may obtain a copy of the License at
rem
rem     https://www.apache.org/licenses/LICENSE-2.0
rem
rem Unless required by applicable law or agreed to in writing, software
rem distributed under the License is distributed on an "AS IS" BASIS,
rem WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
rem See the License for the specific language governing permissions and
rem limitations under the License.

rem This script should be run at the root of maldoca repo.

rem Run MalDocA test.
cd C:\

bazel
bazel help
bazel help startup_options
bazel test --config=windows maldoca/...:all --test_output=errors

choco install bazel

bazel
bazel help
bazel help startup_options
bazel test --config=windows maldoca/...:all --test_output=errors

choco install llvm

clang --version