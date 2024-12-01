# Solutions for advent of Code 2024

Here will be all solutions for the advent of code 2024 riddles, using c++.
 
## General Inforamtion

After setting up a new repository with this template do the following:
1. Change the project_name in the CMakeLists.txt in the root directory
2. Initialize the google test submodule again
```
git submodule update --init --recursive
```

### build process and use
1. first we create a build folder:  
```
mkdir build
```

2. inside the build folder run the following commands:
```
cmake ..
cmake --build .
```

3. After that you can run the main and test executables
On windows default build will build in Debug mode
```
.\Debug\project_name.exe
.\test\Debug\project_name_test.exe
```

To rebuild the programm after you did some changes to it just repeat step 2.

### change CMakeLists to respect bin folder if wanted

### How to add more submodules

Changes to the CMakeLists.txt:

### other
