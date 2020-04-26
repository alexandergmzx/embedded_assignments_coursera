# Assignment for Week 1: _Embedded System Development Components_

@author Alexander Gómez

@date 2019-December-16

# Overview

This assignment is about learning:

- __"Version control"__ systems with Github
- __"C Standardization and Team Coding Standards"__ (Jack Ganssle's firmware development standard)
- GCC (GNU Compiler Colection) introduction

The assignmet was to declare, define and implement functions that, given an array, prints some statistics of the content. Then the files should be compiled with the GCC. 

The compilation and running can be done with these commands:
```
gcc main.c stats.c -o main.out
./main.out
```

# Content

This folder contains:

- __**stats.h**__	The function Declaration header 
- __**stats.c**__	The function Definition file
- __**main.c**__	The function Implementation file

Additionaly this folder contains a __makefile__, which can ease the compilation, gives some information that will be learned later.

# Reference cards (Cheat sheets)

Some Cheat sheets were used for this assignment:

- [Atlassian **Git** Cheat sheet](https://www.atlassian.com/git/tutorials/atlassian-git-cheatsheet)
- [J. H. Silverman **C** Reference Card (ANSI)](https://www.math.brown.edu/~jhs/)
- [wiki C reference](https://en.cppreference.com/w/c)