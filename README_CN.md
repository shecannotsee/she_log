### 简介

she_log 是一个cpp的日志

作者：shecannotsee（shecannotsee@163.com）



### 特点

- she_test 是基于 c++11开发。
- she_log 提供了正常的日志记录功能，并且根据您的需求可以选择日志输出的地方（控制台或者是日志文件）；您也可以根据您的需求添加自己的输出模块；当然了，您也可以定制您的输出格式。



### 使用说明

您需要按照构建流程从源码构建库，然后将库添加到您的项目中，才能够使用该库的功能。

#### 1.控制台输出

下面的代码展示了如何使用该库在控制台上输出日志消息

```cpp
/* @file main.cpp */
#include <she_log.h>

int main(int argc, char** argv) {
  she_log::logger pen;
  // 为日志添加输出方式，这里选择在控制台进行输出
  const auto console = std::make_shared<she_log::console>();
  // 输出格式选择为 SHE_LOG
  console->set_format(she_log::log_format::SHE_LOG);
  // 输出日志等级为 ALL (也就是说会输出所有等级的日志)
  console->set_level(she_log::log_level::ALL);
  // 将输出模式添加到 logger 中
  pen.add_output_method(console);

  // 添加十条 DEBUG 级别的日志并输出
  for (int i = 0; i < 10; ++i) {
    auto msg = std::to_string(i + 1);
    pen.record<she_log::log_level::DEBUG>(msg);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
    
  return 0;
}
```

您稍后就会发现控制台中会出现一些记录的日志。



#### 2.日志文件输出

下面的代码展示了如何使用该库在日志文件上输出日志消息

```cpp
/* @file main.cpp */
#include <she_log.h>

int main(int argc, char** argv) {
  she_log::logger pen;
  // 为日志添加输出方式，这里选择在控制台进行输出
  const auto console = std::make_shared<she_log::local_file>("test_log.txt");
  // 输出格式选择为 SHE_LOG
  console->set_format(she_log::log_format::SHE_LOG);
  // 输出日志等级为 ALL (也就是说会输出所有等级的日志)
  console->set_level(she_log::log_level::ALL);
  // 将输出模式添加到 logger 中
  pen.add_output_method(console);

  // 添加十条 DEBUG 级别的日志并输出
  for (int i = 0; i < 10; ++i) {
    auto msg = std::to_string(i + 1);
    pen.record<she_log::log_level::DEBUG>(msg);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
    
  return 0;
}
```

您稍后就会发现日志文件 test_log.txt 中会出现一些记录的日志。



#### 3.多种输出

您也可以同时添加多个输出端，例如同时添加日志文件输出和控制台输出

```cpp
// ......
  she_log::logger pen;
  const auto local_file = std::make_shared<she_log::local_file>("test_log.txt");
  pen.add_output_method(local_file);
  const auto console = std::make_shared<she_log::console>();
  pen.add_output_method(console);
// ......
```

此时的日志消息不仅会在控制台上输出，而且日志消息会在文件中输出。如果您设置的两种输出模式的输出格式相同，您会发现文件和控制台中的内容是完全相同的。



#### 4.简单的fmt

该日志库还提供了一个简单的fmt接口

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

如果您有需要，您也可以直接把`she_log/src/format/fmt.h`文件取出，然后马上就可以使用fmt函数了。



#### 5.更多的参考

您可以参考`she_log/sample`中的c++项目，该项目是构建并且使用 she_log 的一个例子。



### 获取源码以及构建项目

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