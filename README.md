# CMocka-Testing
Testing CMocka for later use in GEKI unit tests. Figuring out assertions, mocks, etc.

Steps:
1. Made c file
2. Made CMakeLists.txt file --> manually added include directories/link libraries paths to my Program Files (x86) folder, where I have my CMocka files.
3. Made build folder, then moved into it, configuring build files with cmake .. bouncing off the CMakeLists file in the parent folder.
4. Built these using cmake --build .
5. Lastly, ran tests with ctest -C Debug -V to see full results in the command line.
