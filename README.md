# Discovering Modern C++ — Exercise Solutions

Exercise solutions for _Discovering Modern C++_ 2nd edition by Peter
Gottschling. The book covers modern C++ (C++11 through C++20) with a focus on
scientific computing.

## Structure

Solutions are organized by chapter and exercise:

```
solutions/chN/excM_description/
  src/main.cpp
  makefile
```

## Usage

```bash
make new-2.1_name   # scaffold a new exercise
make 2.1            # build exercise ch2 exc1
make run-2.1        # build and run
make tidy-2.1       # run clang-tidy on exercise ch2 exc1
make                # build all exercises
make clean          # clean all build artifacts
```

## Toolchain

- C++20, compiled with `g++ -Wall -Werror`
- clang-format (LLVM style, Allman braces, 4-space indent)
- clang-tidy (cppcoreguidelines, modernize, readability, bugprone,
  performance)
- Pre-commit hooks enforce formatting and linting before every commit
- CI runs on macOS and Linux
