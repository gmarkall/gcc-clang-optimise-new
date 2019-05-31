#include <iostream>
#include <cstdlib>

#ifndef _OVERRIDE_H
#define _OVERRIDE_H

class A {
public:
  void* operator new(size_t sz);
  void operator delete(void* p);
private:
  int data;
};

#endif // _OVERRIDE_H
