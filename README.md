# Mantis HTTP Server Framework
Mantis is an easy to use and simple HTTP framework for networking in C++.

## Building
If you do not have a `build` directory, create one `mkdir build`.

To build the project you can run the command `./go.sh Build-All` to use the helper script.

You can also emulate it using normal cmake commands:
```bash
cmake -B build .
cmake --build build
```
This will build the entire project along with the examples.

To run an example, you can run `./build/[example name]`

## Using clangd LSP
Building using cmake will generate a `compile_commands.json` file in the `build` directory.

You may want to make a symlink to that file using `ln -s build/compile_commands.json .` which will maintain an up-to-date copy of it in your project directory.
