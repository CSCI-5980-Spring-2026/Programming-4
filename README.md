# Programming 4: Components, Meshes, and Geometry Primitives

In this live programming class, we will continue implementation of the core structure of the game engine necessary for the low-level rendering module.

Our implementation will make us of the following programming patterns and idioms:

- **Resource acquisition is initialization (RAII)**
  - Tie ownership to object lifetime: acquire in the constructor, release in the destructor
  - Prefer stack-based objects and smart pointers (`std::unique_ptr`, `std::shared_ptr`) over raw `new`/`delete`
  - Design types so cleanup is automatic even on early returns or exceptions 
- **Composition over inheritance**
  - Build behavior by combining small, focused components instead of deep class hierarchies
  - Prefer “has-a” relationships (owning/holding helper objects) over “is-a” relationships unless substitutability is truly required
  - Enable flexibility by swapping or configuring composed parts at runtime without changing the base type
- **Factory patterns**
  - Centralize common object creation behind a function/class so callers don’t depend on concrete types or constructor details
  - Encapsulate non-trivial setup (defaults, resource loading, dependency wiring) to keep construction consistent and safe
  - Return ownership explicitly (e.g., `std::unique_ptr<T>`, `std::shared_ptr<T>`) to make lifetimes clear at the call site

## Prerequisites

To work with this code, you will first need to install the following software (same or newer versions):

- [Visual Studio Code](https://code.visualstudio.com/)
- [CMake 4.2.1](https://cmake.org/download/)
- [LLVM 21.1.8](https://github.com/llvm/llvm-project/releases/tag/llvmorg-21.1.8)
- [Ninja 1.13.2](https://github.com/ninja-build/ninja/releases/tag/v1.13.2)

On Windows 11, the easiest way to install these is to use the winget package manager.

```
winget install code
winget install cmake
winget install llvm
winget install Ninja-build.Ninja
```

**Important:** You will need to add the LLVM binary path to your system path environment variable. By default, this is installed in `C:\Program Files\LLVM\bin`.

## Visual Studio Code Extensions

You will also need to install the following VS code extensions:

- [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)
- [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb)

## MSVC Platform Libraries

Although we are using the LLVM compiler, our application will still need to link to the MSVC and Windows SDK libraries. Therefore, you will need to install [Microsoft Visual Studio Community](https://visualstudio.microsoft.com/downloads/?q=build+tools) even though we are not using it as an IDE (there does not appear to be any way around this on Windows). In the installer, make sure to check *Desktop development for C++*, and then it will install the required dependencies.

## License

Material for [CSCI 5980 Spring 2026](https://github.com/CSCI-5980-Spring-2026/Syllabus) by [Evan Suma Rosenberg](https://illusioneering.umn.edu/) is licensed under a [Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License](http://creativecommons.org/licenses/by-nc-sa/4.0/).