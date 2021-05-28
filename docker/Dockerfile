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

# Build the image locally:
# cd to //maldoca
# docker build -f /docker/Dockerfile -t <tag> .

# Based on Ubuntu 18.04
FROM ubuntu:bionic

RUN apt-get update

# Install gcc, g++, make, etc..
RUN apt-get install -y build-essential

# Install Bazel.
RUN apt-get install -y curl gnupg
RUN curl https://bazel.build/bazel-release.pub.gpg | apt-key add -
RUN apt-get install -y apt-transport-https ca-certificates
RUN apt-get update
RUN apt-get install -y bazel

RUN apt-get install -y git

# Uncomment below for use for dev on your machine. You should sub DOCKER_USER
# via flag --build-arg DOCKER_USER=$USER and set DOCKER_UID via
# --build-arg DOCKER_UID="$(id -u)" in docker build. Optional override password.
# We need these set up to enable sudo.
# e.g.
# docker build --build-arg DOCKER_UID="$(id -u)"  --build-arg DOCKER_USER=$USER  -t maldoca_build -f docker/Dockerfile .

# ARG DOCKER_USER=docker_user
# ARG DOCKER_UID=8191
# ARG DOCKER_PASS=xyzzy
# ARG DOCKER_TZ='America/Los_Angeles'

# RUN ln -snf "/usr/share/zoneinfo/${DOCKER_TZ}" /etc/localtime && echo "${DOCKER_TZ}" > /etc/timezone

# RUN useradd -r -m -u "${DOCKER_UID}" -s /bin/bash $DOCKER_USER
# RUN echo "${DOCKER_USER}:${DOCKER_PASS}" | chpasswd && adduser "${DOCKER_USER}" sudo

#### end uncomment below
