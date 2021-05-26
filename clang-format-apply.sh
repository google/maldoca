# Copyright 2020 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Runs clang-format and apply changes.

alias clang-format=clang-format-9

clang-format --version

for FILE in maldoca/vba/* \
            maldoca/vba/antivirus/* \
            maldoca/vba/ast/* \
            maldoca/vba/parser/* \
            maldoca/vba/test/* \
            maldoca/base/* \
            maldoca/pdf_parser/* \
            maldoca/service/* \
            maldoca/service/common/* \
            maldoca/service/common/yara/* \
            maldoca/service/common/pdf_sandbox/*; do
  case $FILE in
    *.h|*.cc|*.proto)
      clang-format-9 --verbose -i $FILE
      ;;
  esac
done
