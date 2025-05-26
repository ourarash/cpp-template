load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "com_google_googletest",
    #// Dec 27, 2021
    commit = "1b18723e874b256c1e39378c6774a90701d70f7a",
    remote = "https://github.com/google/googletest",
    # tag = "release-1.11.0",
)

git_repository(
    name = "glog",
    remote = "https://github.com/google/glog.git",
    tag = "v0.5.0",
)

git_repository(
    name = "abseil-cpp",
    remote = "https://github.com/abseil/abseil-cpp.git",
    tag = "20211102.0",
)

git_repository(
    name = "com_google_benchmark",
    remote = "https://github.com/google/benchmark.git",
    tag = "v1.5.1",
)

new_local_repository(
    name = "usr_local",
    build_file = "third_party/usr_local.BUILD",
    path = "/usr/local",
)

# Assuming zlib is installed in usr/local/opt/zlib/lib
new_local_repository(
    name = "zlib",
    build_file = "third_party/zlib.BUILD",
    path = "/usr/local/opt/zlib",
)

git_repository(
    name = "com_github_gflags_gflags",
    remote = "https://github.com/gflags/gflags.git",
    tag = "v2.2.2",
)
