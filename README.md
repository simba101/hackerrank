# HackerRank answers

This repository holds the answers submitted to the problems on [HackerRank](https://www.hackerrank.com) site.

### Compiling and running
Most of the answers have been written in C++. Their names end with **.cc** suffix.  I am using the latest standard, which is now C++14 / C++1y. The compiler I am using is g++. In order to compile a solution *filename.cc*, issue the following command:
```
g++ -o output filename.cc --std=c++1y
```
This will produce an executable *output* which may be run directly in the shell.  Note that the above command may need slight tweaking depending on your OS.  It works properly on Ubuntu 14.04 LTS, however on Arch box you'll need to specify the standard as `--std=c++14` instead.

Some answers are written in Python3 - their names end with **.py** suffix.  Provided that you have Python3 installed properly, run them with:
```
python3 filename.py
```

### License
All the answers are licensed under the MIT license found in the LICENSE file.  Problem statements have been provided by [HackerRank](https://www.hackerrank.com) and are subject to their [Terms of Service](https://www.hackerrank.com/terms-of-service).
