# MalDocA - Malicious Document Analyzer

MalDocA is a library to parse and extract features from Microsoft Office documents. It supports both OLE and OOXML documents.

The project's goal is to analyze potentially malicious documents to improve user safety and security.

## REQUIREMENTS
- bazel
- clang

## CHECKOUT
git clone --recurse-submodules https://github.com/google/maldoca.git

cd maldoca

## BUILD
Linux: bazel build --config=linux maldoca/...

## TEST
Linux: bazel test --config=linux maldoca/...

## DISCLAIMER
This is not an official Google product.
