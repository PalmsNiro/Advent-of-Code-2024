# Cpp-Project-template

This is a template for all sort of C++ Projects.  

For future use you might want to add a few extra things:  
Folders:  
- build - All intermediate files
- include - Project *public* header files
- bin - Output executables

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
