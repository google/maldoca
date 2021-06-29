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

#include "maldoca/base/endian.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace maldoca {
namespace {
constexpr uint64_t kInitialNumber{0x0123456789abcdef};
constexpr uint64_t k64Value{kInitialNumber};
constexpr uint32_t k32Value{0x01234567};
constexpr uint16_t k16Value{0x0123};
constexpr int kNumValuesToTest = 1000000;
constexpr int kRandomSeed = 12345;

#ifdef ABSL_IS_BIG_ENDIAN
constexpr uint64_t kInitialInNetworkOrder{kInitialNumber};
constexpr uint64_t k64ValueLE{0xefcdab8967452301};
constexpr uint32_t k32ValueLE{0x67452301};
constexpr uint16_t k16ValueLE{0x2301};

constexpr uint64_t k64ValueBE{kInitialNumber};
constexpr uint32_t k32ValueBE{k32Value};
constexpr uint16_t k16ValueBE{k16Value};
#else
constexpr uint64_t kInitialInNetworkOrder{0xefcdab8967452301};
constexpr uint64_t k64ValueLE{kInitialNumber};
constexpr uint32_t k32ValueLE{k32Value};
constexpr uint16_t k16ValueLE{k16Value};

constexpr uint64_t k64ValueBE{0xefcdab8967452301};
constexpr uint32_t k32ValueBE{0x67452301};
constexpr uint16_t k16ValueBE{0x2301};
#endif

TEST(EndianessTest, little_endian) {
  // Check little_endian uint16_t.
  uint64_t comp = little_endian::FromHost16(k16Value);
  EXPECT_EQ(comp, k16ValueLE);
  comp = little_endian::ToHost16(k16ValueLE);
  EXPECT_EQ(comp, k16Value);

  // Check little_endian uint32_t.
  comp = little_endian::FromHost32(k32Value);
  EXPECT_EQ(comp, k32ValueLE);
  comp = little_endian::ToHost32(k32ValueLE);
  EXPECT_EQ(comp, k32Value);

  // Check little_endian uint64_t.
  comp = little_endian::FromHost64(k64Value);
  EXPECT_EQ(comp, k64ValueLE);
  comp = little_endian::ToHost64(k64ValueLE);
  EXPECT_EQ(comp, k64Value);

  // Check little-endian Load and store functions.
  uint16_t u16Buf;
  uint32_t u32Buf;
  uint64_t u64Buf;

  little_endian::Store16(&u16Buf, k16Value);
  EXPECT_EQ(u16Buf, k16ValueLE);
  comp = little_endian::Load16(&u16Buf);
  EXPECT_EQ(comp, k16Value);

  little_endian::Store32(&u32Buf, k32Value);
  EXPECT_EQ(u32Buf, k32ValueLE);
  comp = little_endian::Load32(&u32Buf);
  EXPECT_EQ(comp, k32Value);

  little_endian::Store64(&u64Buf, k64Value);
  EXPECT_EQ(u64Buf, k64ValueLE);
  comp = little_endian::Load64(&u64Buf);
  EXPECT_EQ(comp, k64Value);
}

TEST(EndianessTest, big_endian) {
  // Check big-endian Load and store functions.
  uint16_t u16Buf;
  uint32_t u32Buf;
  uint64_t u64Buf;

  unsigned char buffer[10];
  big_endian::Store16(&u16Buf, k16Value);
  EXPECT_EQ(u16Buf, k16ValueBE);
  uint64_t comp = big_endian::Load16(&u16Buf);
  EXPECT_EQ(comp, k16Value);

  big_endian::Store32(&u32Buf, k32Value);
  EXPECT_EQ(u32Buf, k32ValueBE);
  comp = big_endian::Load32(&u32Buf);
  EXPECT_EQ(comp, k32Value);

  big_endian::Store64(&u64Buf, k64Value);
  EXPECT_EQ(u64Buf, k64ValueBE);
  comp = big_endian::Load64(&u64Buf);
  EXPECT_EQ(comp, k64Value);

  big_endian::Store16(buffer + 1, k16Value);
  EXPECT_EQ(u16Buf, k16ValueBE);
  comp = big_endian::Load16(buffer + 1);
  EXPECT_EQ(comp, k16Value);

  big_endian::Store32(buffer + 1, k32Value);
  EXPECT_EQ(u32Buf, k32ValueBE);
  comp = big_endian::Load32(buffer + 1);
  EXPECT_EQ(comp, k32Value);

  big_endian::Store64(buffer + 1, k64Value);
  EXPECT_EQ(u64Buf, k64ValueBE);
  comp = big_endian::Load64(buffer + 1);
  EXPECT_EQ(comp, k64Value);
}

}  // namespace
}  // namespace maldoca
