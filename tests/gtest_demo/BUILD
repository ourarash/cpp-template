load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_test")

cc_test(
    name = "assert_vs_expect",
    srcs = ["assert_vs_expect.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "fib_test",
    srcs = ["fib_test.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "predicate",
    srcs = ["predicate.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "simple_assertions",
    srcs = ["simple_assertions.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "exceptions",
    srcs = ["exceptions.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "floating_points",
    srcs = ["floating_points.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "disabled_tests",
    srcs = ["disabled_tests.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "c_string_assertions",
    srcs = ["c_string_assertions.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_library(
    name = "prime_table",
    srcs = [
        "prime_table.cc",
    ],
    hdrs = ["prime_table.h"],
)

cc_test(
    name = "typed_tests",
    srcs = ["typed_tests.cc"],
    deps = [
        ":prime_table",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "private_members",
    srcs = ["private_members.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "filtered_tests",
    srcs = ["filtered_tests.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "typed_tests_findmax",
    srcs = ["typed_tests_findmax.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "death_test",
    srcs = ["death_test.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "propagating_failiures",
    srcs = ["propagating_failiures.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "cpplib_test",
    srcs = ["cpplib_test.cc"],
    deps = [
        "//src/lib:CPPLib",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "sort_test",
    srcs = ["sort_test.cc"],
    deps = [
        "//src/lib/sort:SortLib",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "search_test",
    srcs = ["search_test.cc"],
    deps = [
        "//src/lib/search:SearchLib",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "test_fixture",
    srcs = ["test_fixture.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "findmax_test",
    srcs = ["findmax_test.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "hello_world_test",
    srcs = ["hello_world_test.cc"],
    copts = ["--std=c++17"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_binary(
    name = "hello_world_test_main",
    srcs = ["hello_world_test_main.cc"],
    copts = ["--std=c++17"],
    deps = [
        "@googletest//:gtest",
    ],
)

cc_test(
    name = "test_function",
    srcs = ["test_function.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "test_fixture_shared_resources",
    srcs = ["test_fixture_shared_resources.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "test_param",
    srcs = ["test_param.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "test_share_logic",
    srcs = ["test_share_logic.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "test_param_share_logic",
    srcs = ["test_param_share_logic.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "user_types",
    srcs = ["user_types.cc"],
    copts = ["--std=c++17"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_binary(
    name = "fib_test_no_gtest",
    srcs = ["fib_test_no_gtest.cc"],
)

cc_test(
    name = "adding_traces",
    srcs = ["adding_traces.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "disabled_tests_fixture",
    srcs = ["disabled_tests_fixture.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "test_param_share_logic_name_generator",
    srcs = ["test_param_share_logic_name_generator.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "test_param_share_logic_name_generator_random",
    srcs = ["test_param_share_logic_name_generator_random.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "test_param_name_generator",
    srcs = ["test_param_name_generator.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "type_prameterized_tests_findmax",
    srcs = ["type_prameterized_tests_findmax.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "repeat_test",
    srcs = ["repeat_test.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "find_max",
    srcs = ["find_max.cc"],
    deps = [
        "@googletest//:gtest_main",
    ],
)
