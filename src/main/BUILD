load("@rules_cc//cc:defs.bzl", "cc_binary")

# Demo of genrul
genrule(
    name = "test",
    srcs = [],
    outs = ["test.txt"],
    cmd = "echo 'Hello world' > $@",
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = ["//src/lib:CPPLib"],
)

cc_binary(
    name = "main_fib",
    srcs = ["main_fib.cc"],
    deps = ["//src/lib:CPPLib"],
)

cc_binary(
    name = "main_logger",
    srcs = ["main_logger.cc"],
    deps = [
        "//src/lib:CPPLib",
        "@gflags",
        "@glog",
    ],
)

cc_binary(
    name = "main_flags_absl",
    srcs = ["main_flags_absl.cc"],
    deps = [
        "@abseil-cpp//absl/flags:flag",
        "@abseil-cpp//absl/flags:parse",
        "@abseil-cpp//absl/flags:usage",
        "@glog",
    ],
)

cc_binary(
    name = "main_address_sanitize",
    srcs = ["main_address_sanitize.cc"],
    # Set this variable to the right path for llvm-symbolizer on your machine.
    env =
        {
            # "ASAN_SYMBOLIZER_PATH": "/usr/local/Cellar/llvm/13.0.0_1/bin/llvm-symbolizer"
            "ASAN_OPTIONS": "detect_stack_use_after_return=1",
        },
    deps = [
    ],
)

cc_binary(
    name = "main_address_sanitize_simple",
    srcs = ["main_address_sanitize_simple.cc"],
    # Set this variable to the right path for llvm-symbolizer on your machine.
    env =
        {
            # "ASAN_SYMBOLIZER_PATH": "/usr/local/Cellar/llvm/13.0.0_1/bin/llvm-symbolizer"
            "ASAN_OPTIONS": "detect_stack_use_after_return=1",
        },
    deps = [
    ],
)

cc_binary(
    name = "main_undefined_behavior_sanitizer",
    srcs = ["main_undefined_behavior_sanitizer.cc"],
    deps = [
        "@abseil-cpp//absl/flags:flag",
        "@abseil-cpp//absl/flags:parse",
        "@abseil-cpp//absl/flags:usage",
        "@glog",
    ],
)

cc_binary(
    name = "fib_main",
    srcs = ["fib_main.cc"],
    deps = [
    ],
)
