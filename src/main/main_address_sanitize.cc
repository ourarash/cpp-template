// Demo of Address Sanitizer.
// By Ari Saif
//-----------------------------------------------------------------------------
// How to build and run?
//-----------------------------------------------------------------------------
// Using bazel:
/*
bazel run --config=asan //src/main:main_address_sanitize -- [choice]
where choice is one of the choices below. See the main function below.

Example:

bazel run --config=asan //src/main:main_address_sanitize -- 1
*/
//-----------------------------------------------------------------------------
// Using G++:
/*
* Run with this command:

g++ \
-O0 \
-g \
-fno-omit-frame-pointer \
-fsanitize=address \
src/main/main_address_sanitize.cc

* And then:
./a.out <choice>

* where choice is one of of the values below See the main function below.
*/
//-----------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>

//-----------------------------------------------------------------------------
volatile char *global_ptr;

__attribute__((noinline)) void FunctionThatEscapesLocalObject() {
  char local[100];
  global_ptr = &local[0];
}

char global_array[10];

//-----------------------------------------------------------------------------
int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: main_address_sanitize <choice>" << std::endl;
    return -1;
  }
  std::cout << argv[1] << std::endl;
  int choice = std::stoi(argv[1]);
  std::cout << "choice: " << choice << std::endl;

  switch (choice) {
  case 0: {
    //  SEGV on unknown address.
    char *ptr = nullptr;
    *ptr = 5;
    break;
  }

  case 1: {
    // SEGV on unknown address.
    char *ptr = (char *)1;
    *ptr = 5;
    break;
  }

  case 2: {
    // SEGV on unknown address.
    std::vector<char> v;
    std::cout << v[100] << std::endl;
    break;
  }

  case 3: {
    // Heap buffer overflow (Example 1).
    std::vector<char> v(1);
    std::cout << v[100] << std::endl;
    break;
  }

  case 4: {
    // Heap buffer overflow (Example 2).
    char *array = new char[16];
    array[16] = 1; // BOOM!
    break;
  }

  case 5: {
    // Heap buffer overflow (Example 3).
    char *ptr = new char;
    *ptr = 'a';
    std::cout << *(ptr + 1) << std::endl;
    break;
  }

  case 6: {
    // Heap use after free.
    char *p = new char;
    delete p;
    std::cout << *p << std::endl;
    break;
  }

  case 7: {
    // Double-free.
    char *p = new char;
    delete p;
    delete p;
    break;
  }

  case 8: {
    // Stack buffer overflow.
    char array[16];
    array[20] = 1; // BOOM!
    break;
  }

  case 9: {
    // stack-use-after-scope
    volatile char *ptr = nullptr;
    {
      char x = 0;
      ptr = &x;
    }
    *ptr = 5;
    break;
  }
  case 10: {
    // stack-use-after-return
    // Set this env variable before running:
    // export ASAN_OPTIONS=detect_stack_use_after_return=1
    FunctionThatEscapesLocalObject();
    return global_ptr[0];
  }

  case 11: {
    // global-buffer-overflow
    // char global_array[10]; // global variable.
    global_array[11] = 1; // Boom!
    break;
  }

  case 12: {
    // global-buffer-overflow
    static char array[10];
    array[11] = 1; // Boom!
    break;
  }

  case 13: {
    // Leak detection (Doesn't work on Mac?)
    // Set this env variable before running:
    // export ASAN_OPTIONS=detect_leaks=1
    // Or with bazel:
    /*
      bazel run --config=asan //src/main:main_address_sanitize \
      --run_under='export ASAN_OPTIONS=detect_leaks=1 &&' -- 13
    */
    char *p = new char;
    *p = 10;
    std::cout << "*p: " << *p << std::endl;
    break;
  }

  default:
    std::cout << "Error: Invalid choice value: " << choice << std::endl;
  }

  return 0;
}
