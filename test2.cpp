#include <iostream>
#include <cstdlib>
#include "override.h"

int main(int argc, char**argv) {
  A* a = new A();
  delete(a);
  return 0;
}
