# MalDocA - Malicious Document Analyzer

MalDocA is a library to parse and extract features from Microsoft Office documents. It supports both OLE and OOXML documents.

The project's goal is to analyze potentially malicious documents to improve user safety and security.

## REQUIREMENTS
- [Bazel](https://bazel.build) (recommended version: 4.1.0)
- [Clang](https://clang.llvm.org) (recommended version: 11 or 12)
- OS: Linux or Windows

## WINDOWS
- Some testdata files might trigger Windows Defender / AV systems. Please add an exclusion for the source directory to avoid potential issues.
- Bazel has some Windows related problems, e.g. maximum path length limitations. Make sure to read the [best-practices](https://docs.bazel.build/versions/main/windows.html#best-practices) to avoid them.
- Enable symlink support ([how-to](https://docs.bazel.build/versions/main/windows.html#enable-symlink-support)) as it is required by Bazel.

## CHECKOUT
git clone --recurse-submodules https://github.com/google/maldoca.git

cd maldoca

## BUILD
Linux: bazel build --config=linux //maldoca/...

Windows: bazel build --config=windows //maldoca/...

## TEST
Linux: bazel test --config=linux //maldoca/...

Windows: bazel test --config=windows //maldoca/...

## DOCKER
We proivde a docker file in "docker/Dockerfile". This is the reference
platform we use for continous integration and optionally (arguably recommended)
for development as well. Please check the documentation in "docker/Dockerfile" on how to
build and use for development.

## CONTACT
maldoca-community@google.com

## DISCLAIMER
This is not an official Google product.
