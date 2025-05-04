#!/bin/sh
parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
# Move into this script's directory, work with relative paths afterwards
cd "${parent_path}"

target="none"

for arg in "$@"; do
  case "$arg" in
    -h)
		echo "This script by default runs all tests in the solution."
		echo "You can pass into it any g_test flags, which will be appended to the actual calls of the executables."
		echo "Example: ./runTests --gtest_list_tests"
		echo "To get the help menu of the tests, pass --help as flag."
		echo "You may also specify a target executable with the flag --target={name_of_exe}" 
		exit 0;;
	--target=*)
      target="${arg#*=}"
      ;;
  esac
done

source_folder="Source"
build_folder="build"

echo "Running tests from bash script..."

executable_tests_lines="$(grep --include=\*CMakeLists.txt -rwh 'Source' -e 'gtest_discover_tests')"
for executable_test_line in ${executable_tests_lines};
do
	prefix_removed=${executable_test_line#*(}
	executable_test=${prefix_removed%)*}

	if [[ "${target}" != "none" && "${target}" != "${executable_test}" ]]; then
		continue
	fi

	echo ""
	echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
	echo "Running tests in executable ${executable_test}.exe"
	echo ""

	executable="$(find ${build_folder} -name ${executable_test}.exe)"
	if [[ -x "$executable" ]]; then
		"$executable" "$@"
		echo ""
		echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
		echo ""
	else
		echo "${executable_test} not found. Did you forget to build it?"
	fi
done

echo "Done!"
