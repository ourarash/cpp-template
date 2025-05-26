# This script is used to run pre-checkin tasks for a project.
bazel clean --expunge
# Remove any existing build artifacts
rm -rf bazel-bin bazel-out bazel-testlogs
# Run the build command for all targets in the src directory
# This will ensure that all source files are compiled and linked correctly
bazel build $(bazel query //src/...)
# Run the test command for all targets in the src directory
# Note: not all tests are expected to pass since this is a demo of gtests.
bazel test $(bazel query //tests/gtest_demo/...)

bazel test $(bazel query //tests/gmock_demo/...)

bazel test $(bazel query 'kind(".*_test", //tests:all)')

# Run the commands from the README.md file that are in the bash code blocks
awk '
  /^\`\`\`bash/ {in_bash=1; next}
  /^\`\`\`/ {in_bash=0}
  in_bash && /^bazel / {print}
' README.md | while read -r cmd; do
    eval "$cmd"
done
