# Calc
A simple, stand-alone implementation of a basic calculator (for educational purpose).

## Compile as Stand-Alone C++ Class
Just include all header files in the `include` folder into your own project. Make sure to compile and link the 
corresponding source files in `src` folder (except `main.cpp`, which is for the interactive command line interface 
mentioned below). This project uses C++11 standard.

## Interactive Command Line Interface
You can try this simple calculator by compiling it with a simple interactive command line interface. Just use the 
following command at the root of project directory:
```bash
mkdir out
c++ src/Calculator.cpp src/main.cpp -Iinclude --std=c++11 -o out/Calculator
```

## Testing
This project comes with unit tests, using [googletest](https://github.com/google/googletest). Although all test cases 
are provided in `test` folder, you have to set up the test framework by your self. Read the instruction in 
`CMakeLists.txt` for more information.
