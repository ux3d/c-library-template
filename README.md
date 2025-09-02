
# C Library Template

[![CI](https://github.com/ux3d/c-project-template/actions/workflows/ci.yml/badge.svg)](https://github.com/ux3d/c-project-template/actions/workflows/ci.yml)

This repository is a **GitHub template for modern C libraries**. It provides a ready-to-use setup for:

- **Multi-platform CI** with GitHub Actions (Windows, macOS, Linux)
- **Unit testing** with Google Test (gtest)
- **Dependency management** with [vcpkg](https://github.com/microsoft/vcpkg)
- **Modern CMake** (C11, out-of-source builds, install rules)

---

## Features

- **Easy project bootstrap:** Just use this template to start a new C library project.
- **Cross-platform builds:** Automated CI for Windows, macOS, and Linux.
- **Google Test integration:** Write tests in C++ using gtest, run them locally or in CI.
- **vcpkg manifest mode:** Manage dependencies in `vcpkg.json`.
- **CMake best practices:** Out-of-source builds, install rules, and exportable targets.

---

## Project Structure

```
c-project-template/
├── include/           # Public header files
├── src/               # Source files
├── test/              # Unit tests (Google Test)
├── build/             # CMake build output
├── install/           # Installation output
├── CMakeLists.txt     # CMake build configuration
├── vcpkg.json         # vcpkg dependencies
└── .github/           # GitHub Actions workflows
```

---

## Getting Started

### 1. Use this template

Click **"Use this template"** on GitHub to create your own repository.

### 2. Clone your new repository

```sh
git clone https://github.com/your-org/your-new-c-library.git
cd your-new-c-library
```

### 3. Install dependencies with vcpkg

```sh
vcpkg install
```

### 4. Configure and build with CMake

```sh
cmake -B build -S .
cmake --build build
```

### 5. Run unit tests

```sh
cd build
ctest
# or run the test binary directly
./gtest
```

---

## Customization

- **Rename the library:**
    - Update `project()` and target names in `CMakeLists.txt`.
    - Rename files and headers as needed.
- **Add dependencies:**
    - Add them to `vcpkg.json` and follow the CMake comments for linking.
- **Add source or test files:**
    - Place C sources in `src/`, headers in `include/`, and tests in `test/`.

---

## Continuous Integration

This template includes a sample GitHub Actions workflow for multi-platform builds and tests. See `.github/workflows/ci.yml` for details.

---

## License

This template is provided under the MIT License. See [LICENSE](LICENSE) for details.

