# MalDocA - Malicious Document Analyzer

MalDocA is a library to parse and extract features from Microsoft Office documents. It supports both OLE and OOXML documents.

The project's goal is to analyze potentially malicious documents to improve user safety and security.

## CHECKOUT
git clone --recurse-submodules https://github.com/google/maldoca.git

cd maldoca

## BUILD
bazel build --copt=-DMALDOCA_CHROME=1 --define MALDOCA_CHROME=1 maldoca/...

## TEST
bazel test --copt=-DMALDOCA_CHROME=1 --define MALDOCA_CHROME=1 maldoca/...

## DISCLAIMER
This is not an official Google product.
