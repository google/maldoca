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

// For expedience, we are borrowing file ops in the protobuf/testing.
// In the long run this should be replaced by either using better
// libraries or rewrite.

#include "maldoca/base/file.h"

#include <memory>

#include "absl/memory/memory.h"
#include "absl/status/status.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "maldoca/base/testing/status_matchers.h"

namespace maldoca {
namespace file {
namespace {
using ::testing::UnorderedElementsAre;

void CheckSplit(std::pair<absl::string_view, absl::string_view> actual,
                absl::string_view prefix, absl::string_view postfix) {
  EXPECT_EQ(actual.first, prefix);
  EXPECT_EQ(actual.second, postfix);
}

#ifndef MALDOCA_CHROME
TEST(Match, FindFiles) {
  std::string tmp_dir = TestTempDir();

  MALDOCA_ASSERT_OK(CreateDir(JoinPath(tmp_dir, "findfiles_1")));
  MALDOCA_ASSERT_OK(CreateDir(JoinPath(tmp_dir, "findfiles_1/abcd_123")));
  MALDOCA_ASSERT_OK(CreateDir(JoinPath(tmp_dir, "findfiles_1/abcd_123/xyz")));
  auto file_1 = JoinPath(tmp_dir, "findfiles_1/abcd_123/xyz/file-1.txt");
  auto file_2 = JoinPath(tmp_dir, "findfiles_1/abcd_123/xyz/file-2.txt");
  MALDOCA_ASSERT_OK(SetContents(file_1, "dummy"));
  MALDOCA_ASSERT_OK(SetContents(file_2, "dummy"));

  std::vector<std::string> files;
  MALDOCA_ASSERT_OK(
      Match(JoinPath(tmp_dir, R"(findfiles_1/abc*/xyz/*.txt)"), &files));
  EXPECT_EQ(2, files.size());
  ASSERT_THAT(files, UnorderedElementsAre(file_1, file_2));
  files.clear();
  MALDOCA_ASSERT_OK(
      Match(JoinPath(tmp_dir, R"(findfiles_1/abc?????/xyz*/*.txt)"), &files));
  ASSERT_THAT(files, UnorderedElementsAre(file_1, file_2));
  files.clear();
  MALDOCA_ASSERT_OK(
      Match(JoinPath(tmp_dir, R"(findfiles_1/abc?????/xyz*/*2*.txt)"), &files));
  ASSERT_THAT(files, UnorderedElementsAre(file_2));
  files.clear();
  ASSERT_FALSE(
      Match(JoinPath(tmp_dir, R"(findfiles_1/abc??/xyz*/*2*.txt)"), &files)
          .ok());
}

TEST(SplitPath, SplitPath) {
  auto result = SplitPath("/file/a/fn.txt");
  CheckSplit(result, "/file/a", "fn.txt");
  result = SplitPath("/");
  CheckSplit(result, "/", "");
  result = SplitPath("/home/");
  CheckSplit(result, "/home", "");
}

#endif  // MALDOCA_CHROME

// TODO: add tests for Windows once it is used.
TEST(JoinPath, JoinPath) {
  EXPECT_EQ(base::FilePath("a").value(),
            JoinPath(base::FilePath("a"), base::FilePath("")).value());
  EXPECT_EQ(base::FilePath("a/b").value(),
            JoinPath(base::FilePath("a"), base::FilePath("b")).value());
  EXPECT_EQ(base::FilePath("a/b").value(),
            JoinPath(base::FilePath("a/"), base::FilePath("b")).value());
  EXPECT_EQ(base::FilePath("a/b/").value(),
            JoinPath(base::FilePath("a"), base::FilePath("b/")).value());
  EXPECT_EQ(base::FilePath("a/b/").value(),
            JoinPath(base::FilePath("a/"), base::FilePath("b/")).value());
  EXPECT_EQ(base::FilePath("a/b/").value(),
            JoinPath(base::FilePath("a//"), base::FilePath("b/")).value());
  EXPECT_EQ(base::FilePath("/a/b").value(),
            JoinPath(base::FilePath("/a"), base::FilePath("b")).value());
}

// TODO: add tests for Windows
TEST(SplitFilename, SplitFilename) {
  auto result = SplitFilename(base::FilePath("/file/a/fn.txt"));
  CheckSplit(result, "/file/a/fn", "txt");
  result = SplitFilename(base::FilePath("/"));
  CheckSplit(result, "/", "");
  result = SplitFilename(base::FilePath("/home/"));
  CheckSplit(result, "/home/", "");
  result = SplitFilename(base::FilePath("my.file.doc"));
  CheckSplit(result, "my.file", "doc");
}
}  // namespace
}  // namespace file
}  // namespace maldoca
