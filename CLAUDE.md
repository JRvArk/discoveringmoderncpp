# Discovering Modern C++ — Exercise Solutions

Working through the exercises in _Discovering Modern C++_ 2nd edition by Peter
Gottschling.

## Project Structure

```
solutions/chN/excM_name/
  src/main.cpp
  makefile          # copied from .templates/makefile
  build/            # generated
  main              # compiled binary
```

## Build Commands

Run from the repo root:

```bash
make new-2.1        # scaffold solutions/ch2/exc1/ with template makefile + main.cpp
make 2.1            # build exercise ch2 exc1
make run-2.1        # build and run
make                # build all exercises
make clean          # clean all build artifacts
```

Or from inside an exercise directory:

```bash
make                # build
make clean
```

## Toolchain

- **Compiler**: g++, C++20 (`-std=c++20 -Wall -Werror`)
- **Formatting**: clang-format (LLVM style, Allman braces, 4-space indent, 100
  col limit)
- **Linting**: clang-tidy (cppcoreguidelines, modernize, performance,
  readability, bugprone)
- **Pre-commit hooks**: clang-format + clang-tidy run automatically on commit

## Code Style

- Use `'\n'` instead of `std::endl`
- Naming: `snake_case` for variables, parameters, functions, members;
  `CamelCase` for classes/structs; `UPPER_CASE` for constants and enum values
- Prefer standard library features
- Allman brace style (braces on their own line)
- Pointers/references aligned left (`int* p`, `int& r`)
