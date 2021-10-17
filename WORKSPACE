workspace(name = "cpp_experiments")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Bazel compilation database helps to generate compilation database JSON file
# for clangd application. Clangd application is used for code autocompletion.
http_archive(
    name = "bazel_compdb",
    sha256 = "bcecfd622c4ef272fd4ba42726a52e140b961c4eac23025f18b346c968a8cfb4",
    strip_prefix = "bazel-compilation-database-0.4.5",
    urls = [
        "https://github.com/grailbio/bazel-compilation-database/archive/0.4.5.tar.gz",
    ],
)

# Google Abseil C++ library
# It provides some useful features for C++.
http_archive(
    name = "com_google_absl",
    sha256 = "59b862f50e710277f8ede96f083a5bb8d7c9595376146838b9580be90374ee1f",
    strip_prefix = "abseil-cpp-20210324.2",
    urls = [
        "https://github.com/abseil/abseil-cpp/archive/refs/tags/20210324.2.tar.gz",
    ],
)

# Bazel build rules for Abseil library support.
http_archive(
    name = "rules_cc",
    sha256 = "4dccbfd22c0def164c8f47458bd50e0c7148f3d92002cdb459c2a96a68498241",
    urls = ["https://github.com/bazelbuild/rules_cc/releases/download/0.0.1/rules_cc-0.0.1.tar.gz"],
)

# Google testing framework for unit testing.
http_archive(
    name = "com_google_googletest",
    sha256 = "b4870bf121ff7795ba20d20bcdd8627b8e088f2d1dab299a031c1034eddc93d5",
    strip_prefix = "googletest-release-1.11.0",
    urls = ["https://github.com/google/googletest/archive/refs/tags/release-1.11.0.tar.gz"],
)
