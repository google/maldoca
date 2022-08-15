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
choco install -y bazel --version=5.0.0
choco install -y llvm --version=12.0.1

rem seems to break the kokoro automation so removing it
rem refreshenv

git submodule update --init --recursive

rem Run MalDocA test.
bazel test --config=windows maldoca/... --test_output=errors --verbose_failures

