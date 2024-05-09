/*
unit_test.fmt_test
*/
#include <format/fmt.h>
#include <she_test.h>

SHE_TEST(unit_test, fmt_test) {
  using namespace she_log;

  /* char */ {
    char target1 = 'a';
    char target2 = 'b';
    std::cout << fmt("char >>> {} {}", target1, target2) << std::endl;
  }
  /* unsigned char */ {
    unsigned char target1 = 'a';
    unsigned char target2 = 'b';
    std::cout << fmt("unsigned char >>> {} {}", target1, target2) << std::endl;
  }
  /* const char* */ {
    const char* target1 = "target1";
    const char* target2 = "target2";
    std::cout << fmt("const char* >>> {} {}", target1, target2) << std::endl;
  }

  /* std::string */ {
    std::string target1 = "target1";
    std::string target2 = "target2";
    std::cout << fmt("std::string >>> {} {}", target1, target2) << std::endl;
  }

  /* int */ {
    int target1 = 1;
    int target2 = 2;
    std::cout << fmt("int >>> {} {}", target1, target2) << std::endl;
  }

  /* double */ {
    double target1 = 1.2;
    double target2 = 2.1;
    std::cout << fmt("double >>> {} {}", target1, target2) << std::endl;
  }
  /* bool */ {
    bool target1 = true;
    bool target2 = false;
    std::cout << fmt("bool >>> {} {}", target1, target2) << std::endl;
  }

  return true;
}
