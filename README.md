sheLog is a  fast C++ logging library based on c++11.

Authors: shecannotsee (shecannotsee@163.com)

# Features

- Based on c++11 and without any dependency
- Easy to use
- Clear architecture so that you can easily modify the library



# Documentation

You can find more details in folder ./example

example.cpp

```c++
#include <iostream>
#include <interface.h>

int main() {
  std::cout<<"example test start.\n";

  sheLog::interface p_log("log.txt");
  p_log.DEBUG("hi");

  std::cout<<"Done.\n";
  return 0;
};
```



# Getting the Source

```shell
git clone https://github.com/shecannotsee/sheLog.git
```



# Building

This project supports [CMake](https://cmake.org/) out of the box.

### Build for Linux or Mac

```shell
# now you are in the directory ${path}/sheThreadPool
➜ pwd
${path}/sheLog
➜ mkdir build
➜ cd build
➜ cmake ..
➜ make
➜ make install
```
