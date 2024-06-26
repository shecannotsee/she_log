### Introduction

she_log is a C++ logging library.

Author: shecannotsee (shecannotsee@163.com)



### Features

- she_test is developed based on C++11.
- she_log provides normal logging functionality and allows you to choose where the logs are outputted (console or log file) according to your needs. You can also add your own output modules as per your requirements. Additionally, you can customize the output format.



### Usage Instructions

You need to build the library from the source code according to the build process and then add the library to your project in order to use its functionality.

#### 1.Console Output

The following code demonstrates how to use the library to output log messages on the console:

```cpp
/* @file main.cpp */
#include <she_log.h>

int main(int argc, char** argv) {
  she_log::logger pen;
  // Add output method for logs, selecting console output here
  const auto console = std::make_shared<she_log::console>();
  // Choose SHE_LOG as the output format
  console->set_format(she_log::log_format::SHE_LOG);
  // Set log level to ALL (i.e., output all log levels)
  console->set_level(she_log::log_level::ALL);
  // Add the output method to the logger
  pen.add_output_method(console);

  // Add ten DEBUG level logs and output
  for (int i = 0; i < 10; ++i) {
    auto msg = std::to_string(i + 1);
    pen.record<she_log::log_level::DEBUG>(msg);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
    
  return 0;
}
```

You will soon see some recorded logs appearing on the console.



#### 2. Log File Output

The following code demonstrates how to use the library to output log messages to a log file:

```cpp
/* @file main.cpp */
#include <she_log.h>

int main(int argc, char** argv) {
  she_log::logger pen;
  // Add output method for logs, selecting log file output here
  const auto console = std::make_shared<she_log::local_file>("test_log.txt");
  // Choose SHE_LOG as the output format
  console->set_format(she_log::log_format::SHE_LOG);
  // Set log level to ALL (i.e., output all log levels)
  console->set_level(she_log::log_level::ALL);
  // Add the output method to the logger
  pen.add_output_method(console);

  // Add ten DEBUG level logs and output
  for (int i = 0; i < 10; ++i) {
    auto msg = std::to_string(i + 1);
    pen.record<she_log::log_level::DEBUG>(msg);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
    
  return 0;
}
```

You will soon find some recorded logs in the log file test_log.txt.



#### 3. Multiple Outputs

You can also add multiple output channels simultaneously, for example, adding both log file output and console output:

```cpp
// ......
  she_log::logger pen;
  const auto local_file = std::make_shared<she_log::local_file>("test_log.txt");
  pen.add_output_method(local_file);
  const auto console = std::make_shared<she_log::console>();
  pen.add_output_method(console);
// ......
```

Now, log messages will be outputted not only on the console but also in the file. If you set the output formats of the two output methods to be the same, you will find that the contents in the file and on the console are identical.



#### 4. Simple fmt

The logging library also provides a simple fmt interface:

```cpp
#include <she_log>

int main() {
  using namespace she_log;
  /* char */ {
    char target1 = 'a';
    char target2 = 'b';
    std::cout << fmt("char >>> {} {}", target1, target2) << std::endl;// char >>> a b
  }
  /* unsigned char */ {
    unsigned char target1 = 'a';
    unsigned char target2 = 'b';
    std::cout << fmt("unsigned char >>> {} {}", target1, target2) << std::endl;// unsigned char >>> a b
  }
  /* const char* */ {
    const char* target1 = "target1";
    const char* target2 = "target2";
    std::cout << fmt("const char* >>> {} {}", target1, target2) << std::endl;// const char* >>> target1 target2
  }

  /* std::string */ {
    std::string target1 = "target1";
    std::string target2 = "target2";
    std::cout << fmt("std::string >>> {} {}", target1, target2) << std::endl;// std::string >>> target1 target2

  }

  /* int */ {
    int target1 = 1;
    int target2 = 2;
    std::cout << fmt("int >>> {} {}", target1, target2) << std::endl;// int >>> 1 2
  }

  /* double */ {
    double target1 = 1.2;
    double target2 = 2.1;
    std::cout << fmt("double >>> {} {}", target1, target2) << std::endl;// double >>> 1.2 2.1
  }
  /* bool */ {
    bool target1 = true;
    bool target2 = false;
    std::cout << fmt("bool >>> {} {}", target1, target2) << std::endl;// bool >>> 1 0
  }
}

```

If needed, you can directly extract the `she_log/src/format/fmt.h` file and immediately start using the fmt function.



#### 5. Further References

You can refer to the C++ project in `she_log/sample`, which is an example of building and using she_log.



### Obtaining Source Code and Building the Project

```bash
$ git clone https://github.com/shecannotsee/she_log
$ cd she_log
$ ./scripts/third_party_she_test_build.sh 
$ mkdir build
$ cd build
$ cmake ..
$ make -j8
$ make install
$ tree she_log
she_log
├── bin
│   └── she_log_test
├── cmake
│   └── she_log-config.cmake
├── include
│   ├── common
│   │   ├── log_info.h
│   │   ├── make_unique.h
│   │   └── time.h
│   ├── filter
│   │   └── log_level.h
│   ├── format
│   │   ├── fmt.h
│   │   └── log_format.h
│   ├── logger
│   │   ├── log_channel.h
│   │   └── logger.h
│   ├── output
│   │   ├── console
│   │   │   └── console.h
│   │   ├── local_file
│   │   │   ├── file_ops
│   │   │   │   ├── file.h
│   │   │   │   ├── seek.h
│   │   │   │   └── write.h
│   │   │   └── local_file.h
│   │   ├── log_dest.h
│   │   └── output.h
│   └── she_log.h
└── lib
    ├── libshe_log.a
    └── libshe_log.so

12 directories, 20 files
$
```

