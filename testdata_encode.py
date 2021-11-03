#!/usr/bin/env python3
#
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

# Encodes respectively decodes testdata files with XOR and a fixed key.
# The output is stored in the same path, having "_xored" as file name appendix.
# Example usage: python testdata_encode.py maldoca/ole/testdata/ole/206e3a5d0c3e6bad5c7a5821f5ca4712

import sys

if len(sys.argv) != 2:
  print("usage: %s <path>" % sys.argv[0])
  sys.exit()


def xor(data, key):
  l = len(key)
  return bytearray(((data[i] ^ key[i % l]) for i in range(0, len(data))))


def main():
  key = bytearray([0x42])
  content = bytearray(open(sys.argv[1], "rb").read())
  xored = xor(content, key)
  open(str(sys.argv[1] + "_xored"), "wb").write(xored)


if __name__ == "__main__":
  main()

