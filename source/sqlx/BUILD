load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "sqlx",
    srcs = [
        "sqlx/db.cc",
        "sqlx/db_impl.h",
        "sqlx/query.cc",
        "sqlx/tx.cc",
    ],
    hdrs = [
        "sqlx/db.h",
        "sqlx/ex.h",
        "sqlx/query.h",
        "sqlx/tx.h",
    ],
    linkopts = [
        "-lodbc",
    ],
    deps = [
        "@com_google_absl//absl/status",
    ],
)

cc_binary(
    name = "app",
    srcs = [
        "main.cc",
    ],
    deps = [":sqlx"],
)
