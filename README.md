# playfairCypher-C

### Introduction:
This is a cypher / decypher algorithm called Playfair written in C. It was for an university project.

### What do you need:
1. A C compiler
1. Cmake installed in your computer

### How to use:
1. Download the files
1. Extract it in a directory
1. "cd" into the directory
1. Run the following commands:
```
  mkdir build
  cd build
  cmake ..
  cmake --build .
```

If you want to encode files, run: 
```
  ./playfair encode <keyfile> <output_dir> <file1> ... <filen>
```
If you want to decode files, run:
```
  ./playfair decode <keyfile> <output_dir> <file1> ... <filen>
```
