# C++ Template for Google Bazel, Test, Benchmark, Log, and Abseil (ABSL)

> Can be used in Visual Studio Code

Features:

- [x] Building C++ files using Bazel in Visual Studio Code
- [x] [Google Test](https://github.com/google/googletest) for unit tests
- [x] [Google GMock](https://google.github.io/googletest) for writing mock classes
- [x] [Google Benchmark](https://github.com/google/benchmark) for benchmarking
- [x] Google's [glog](https://github.com/google/glog) logger for logging
- [x] Google's [Abseil library](https://github.com/abseil/abseil-cpp)
- [x] [Address Sanitizer](https://github.com/google/sanitizers/wiki/AddressSanitizer)
- [x] [Undefined behavior Sanitizer](https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html)
- [x] Debugging with Visual Studio Code to provide breakpoints, watch, call stack, and pretty printing for STL containers such as `std::map` and `std::vector`

You can use this template for most of your C++ projects with minimal changes.

## A Video on how to use this repo:

<table><tr><td>

<a href="https://youtu.be/JfOzsBi_irY">
<img border="5" alt="C++ starter repo for Bazel & Visual Studio Code with GTest, Glog and Abseil" src="https://raw.githubusercontent.com/ourarash/cpp-template/master/abseil_thumbnail_play.png" width="400">
</a>
</td></tr></table>

## Prerequisite: Installing Bazel

This repo uses `Bazel` for building C++ files.
You can install Bazel using this [link](https://bazel.build/start).

## Cloning this repo

```bash
git clone https://github.com/ourarash/cpp-template.git
```

## Examples:

### Hello World Example:

You can run this using `bazel`:

```bash
bazel run src/main:main
```

### Google's glog demo:

You can run this using `bazel`:

```bash
bazel run src/main:main_logger
```

### Google's Benchmark demo:

You can run this using `bazel`:

```bash
bazel run --cxxopt='-std=c++17' -c opt src/benchmark/main_benchmark
```

<table><tr><td>

<a href="https://youtu.be/9VKR8u9odrA">
A video tutorial on Google Benchmark.
</a>
</td></tr></table>

### Google's Abseil's flags demo:

You can run this using `bazel`:

```bash
bazel run src/main:main_flags_absl
```

### Address Sanitizer demo:

You can run this using `bazel`:

```bash
bazel run --config=asan //src/main:main_address_sanitize -- 0
```

Note that you should run bazel with `--config=asan`.
This will use [.bazelrc](.bazelrc) file that enables the usage of address sanitizer.

See [src/main/main_address_sanitize.cc](src/main/main_address_sanitize.cc) for usage examples.

Output:

<table><tr><td>

<img border="5" alt="Google Sanitizer Demo" src="https://raw.githubusercontent.com/ourarash/cpp-template/master/asan_demo.png" width="800">

</td></tr></table>

### Undefined Behavior Sanitizer demo:

You can run this using `bazel`:

```bash
bazel run --config=ubsan //src/main:main_undefined_behavior_sanitizer -- 0
```

Note that you should run bazel with `--config=ubsan`.
This will use [.bazelrc](.bazelrc) file that enables the usage of address sanitizer.

See [src/main/main_undefined_behavior_sanitizer.cc](src/main/main_undefined_behavior_sanitizer.cc) for usage examples.

Example:

```cpp
int k = 0x7fffffff;
k += 100;  // undefined behavior
std::cout << "k: " << k << std::endl;
```

Output:

<table><tr><td>

<img border="5" alt="Google Sanitizer Demo" src="https://raw.githubusercontent.com/ourarash/cpp-template/master/ubsan_demo.png" width="800">

</td></tr></table>

# Using Google Test with Bazel in Visual Studio Code:

Here is a video that explains more about how to use Google Test with Bazel in Visual Studio Code:

<table><tr><td>

<a href="https://www.youtube.com/watch?v=0wMNtl2xDT0/">
<img border="5" alt="Bazel & Google Test in Visual Studio Code" src="https://raw.githubusercontent.com/ourarash/cpp-template/master/bazel_yt.png" width="400">
</a>
</td></tr></table>

## Example of running a test:

A sample test file is [tests/cpplib_test.cc](tests/cpplib_test.cc) which uses [tests/BUILD](tests/BUILD) file.

You can run the test using [`bazel`](installing-bazel):

```bash
bazel test //tests/gtest_demo:fib_test 
```

# More info on GLOG

GLOG is the C++ implementation of the Google logging module.
You can see complete usage instructions [here](https://github.com/google/glog/blob/master/doc/glog.html)

A sample usage is included in this repo [here](src/main/main_logger.cc):

```cpp
int main(int argc, char* argv[]) {
  google::InitGoogleLogging(argv[0]);

  // Log both to log file and stderr
  FLAGS_alsologtostderr = true;

  std::vector<int> x = {1, 2, 3, 4};
  std::map<int, int> y = {{1, 2}, {2, 3}};

  LOG(INFO) << "ABC, it's easy as "
            << "{" << x << "}";
  LOG(INFO) << "ABC, it's easy as " << y;

  LOG(INFO) << "This is an info  message";
  LOG(WARNING) << "This is a warning message";
  LOG(INFO) << "Hello, world again!";
  LOG(ERROR) << "This is an error message";
  LOG(FATAL) << "This is a fatal message";
  CHECK(5 == 4) << "Check failed!";

  return 0;
}
```

# More Info On Abseil Library:

[Abseil library](https://github.com/abseil/abseil-cpp) is an open-source collection of C++ code (compliant to C++11) designed to augment the C++ standard library.

A sample usage is included in this repo [here](src/main/main_flags_absl.cc):

Abseil contains the following C++ library components:

- [`base`](https://github.com/abseil/abseil-cpp/tree/master/absl/base/) Abseil Fundamentals
  <br /> The `base` library contains initialization code and other code which
  all other Abseil code depends on. Code within `base` may not depend on any
  other code (other than the C++ standard library).
- [`algorithm`](https://github.com/abseil/abseil-cpp/tree/master/absl/algorithm/)
  <br /> The `algorithm` library contains additions to the C++ `<algorithm>`
  library and container-based versions of such algorithms.
- [`container`](https://github.com/abseil/abseil-cpp/tree/master/absl/container/)
  <br /> The `container` library contains additional STL-style containers,
  including Abseil's unordered "Swiss table" containers.
- [`debugging`](https://github.com/abseil/abseil-cpp/tree/master/absl/debugging/)
  <br /> The `debugging` library contains code useful for enabling leak
  checks, and stacktrace and symbolization utilities.
- [`hash`](https://github.com/abseil/abseil-cpp/tree/master/absl/hash/)
  <br /> The `hash` library contains the hashing framework and default hash
  functor implementations for hashable types in Abseil.
- [`memory`](https://github.com/abseil/abseil-cpp/tree/master/absl/memory/)
  <br /> The `memory` library contains C++11-compatible versions of
  `std::make_unique()` and related memory management facilities.
- [`meta`](https://github.com/abseil/abseil-cpp/tree/master/absl/meta/)
  <br /> The `meta` library contains C++11-compatible versions of type checks
  available within C++14 and C++17 versions of the C++ `<type_traits>` library.
- [`numeric`](https://github.com/abseil/abseil-cpp/tree/master/absl/numeric/)
  <br /> The `numeric` library contains C++11-compatible 128-bit integers.
- [`strings`](https://github.com/abseil/abseil-cpp/tree/master/absl/strings/)
  <br /> The `strings` library contains a variety of strings routines and
  utilities, including a C++11-compatible version of the C++17
  `std::string_view` type.
- [`synchronization`](https://github.com/abseil/abseil-cpp/tree/master/absl/synchronization/)
  <br /> The `synchronization` library contains concurrency primitives (Abseil's
  `absl::Mutex` class, an alternative to `std::mutex`) and a variety of
  synchronization abstractions.
- [`time`](https://github.com/abseil/abseil-cpp/tree/master/absl/time/)
  <br /> The `time` library contains abstractions for computing with absolute
  points in time, durations of time, and formatting and parsing time within
  time zones.
- [`types`](https://github.com/abseil/abseil-cpp/tree/master/absl/types/)
  <br /> The `types` library contains non-container utility types, like a
  C++11-compatible version of the C++17 `std::optional` type.
- [`utility`](https://github.com/abseil/abseil-cpp/tree/master/absl/utility/)
  <br /> The `utility` library contains utility and helper code.

# Debugging with Bazel and Visual Studio Code

## Build for debug:

In order to generate debug information, use `-c dbg`:

```bash
bazel build src/main:main_logger  -c dbg
```

Visual Studio Code's [launch.json](.vscode/launch.json) file is currently set so that if you hit `F5` while any file under `src/main` is open (for example [src/main/main_fib.cc](src/main/main_fib.cc)), bazel will automatically build it for debug and run it in debug mode provided that a target with the name of the file without the `.cc` extension (e.g. `main_fib`) exists in [src/main/BUILD](src/main/BUILD) file.

<table><tr><td>

<a href="https://www.youtube.com/watch?v=0wMNtl2xDT0/">
<img border="5" alt="Debugging C++ in Visual Studio Code using gcc/gdb and Bazel" src="https://raw.githubusercontent.com/ourarash/cpp-template/master/VSCDebug_yt.png" width="400">
</a>
</td></tr></table>

More Info On Debugging in VSC is [here](https://code.visualstudio.com/docs/cpp/cpp-debug).

### Credit

The initial version of this repo was inspired by [this post](https://www.ratanparai.com/c++/writing-unit-tests-with-bazel/).
