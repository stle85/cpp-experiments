# Use latest Ubuntu LTS release from Microsoft for VS Code
FROM mcr.microsoft.com/vscode/devcontainers/cpp:ubuntu

# Arguments
# USER_HOME contains the path to the user's home directory
ARG USER_HOME="/home/vscode"

# Set en_US locale for container
RUN \
    locale-gen en_US.UTF-8

ENV \
    LANG=en_US.UTF-8 \
    LANGUAGE=en_US:en \
    LC_ALL=en_US.UTF-8

# Disable interactive from apt(system package management tool)
ENV DEBIAN_FRONTEND=noninteractive

# install dev dependecies
# Clang for C++ development
# Python3 for scripts support
RUN \
    apt update && \
    apt -y --no-install-recommends install software-properties-common && \
    wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | apt-key add - && \
    add-apt-repository 'deb http://apt.llvm.org/focal/ llvm-toolchain-focal-12 main' && \    
    apt update && \
    apt -y --no-install-recommends install \
        clang-12 \
        clang-format-12 \
        clang-tidy-12 \
        clangd-12 \
        lld-12 \
        lldb-12 \
        curl \
        dos2unix \
        git \
        openjdk-11-jdk-headless \
        python3 \
        unixodbc-dev


# Change C++ toolchain to Clang
RUN \
    update-alternatives --install /usr/bin/clang clang /usr/bin/clang-12 100 && \
    update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-12 100 && \
    update-alternatives --install /usr/bin/cc cc /usr/bin/clang-12 100 && \
    update-alternatives --install /usr/bin/c89 c89 /usr/bin/clang-12 100 && \
    update-alternatives --install /usr/bin/c99 c99 /usr/bin/clang-12 100 && \
    update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++-12 100 && \
    update-alternatives --install /usr/bin/ld ld /usr/bin/lld-12 100 && \
    update-alternatives --install /usr/bin/lldb lldb /usr/bin/lldb-12 100 && \
    update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-12 100 && \
    update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-12 100 && \
    update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-12 100

# Install bazel and bazel build tools
RUN \
    curl -sLo /usr/bin/bazel https://github.com/bazelbuild/bazelisk/releases/latest/download/bazelisk-linux-amd64 && \
    chmod +x /usr/bin/bazel && \
    curl -sLo /usr/bin/buildifier https://github.com/bazelbuild/buildtools/releases/latest/download/buildifier-linux-amd64 && \
    chmod +x /usr/bin/buildifier && \
    curl -sLo /usr/bin/buildozer https://github.com/bazelbuild/buildtools/releases/latest/download/buildozer-linux-amd64 && \
    chmod +x /usr/bin/buildozer

# copy useful scripts
COPY scripts ${USER_HOME}/scripts

# add scripts in PATH
RUN \
    dos2unix ${USER_HOME}/scripts/* && \
    chmod +x ${USER_HOME}/scripts/*

ENV PATH="${USER_HOME}/scripts:${PATH}"
