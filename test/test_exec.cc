#include <iostream>
#include "../subprocess.hpp"

using namespace subprocess;

void test_exec()
{
  int st= Popen("",exec_func([](){
      std::cerr << "writing error to stderr\n";
      std::exit(0);
  }), environment{{
					{"NEW_ENV1", "VALUE-1"},
					{"NEW_ENV2", "VALUE-2"},
					{"NEW_ENV3", "VALUE-3"}
                                    }}).wait();
  assert (st == 0);
}

int main() {
    std::atexit([](){std::cerr << "EXIT BWAHAHA\n";});
    std::at_quick_exit([](){std::cerr << "QUICK EXIT BWAHAHA\n";});
  test_exec();
  return 0;
}
