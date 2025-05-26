load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_test")

cc_test(
    name = "cpplib_test",
    srcs = ["cpplib_test.cc"],
    deps = [
        "//src/lib:CPPLib",
        "@googletest//:gtest_main",
    ],
)
