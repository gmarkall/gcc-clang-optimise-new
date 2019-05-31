#include <cstdlib>
#include <new>
#include <iostream>

#include "override.h"

void* operator new(size_t sz) throw (std::bad_alloc)
{
    std::cerr << "allocating " << sz << " bytes\n";
    void* mem = malloc(sz);
    if (mem)
        return mem;
    else
        throw std::bad_alloc();
}


void operator delete(void* ptr) throw()
{
    std::cerr << "deallocating at " << ptr << std::endl;
    free(ptr);
}

void*
A::operator new(size_t sz) {
  std::cerr << "New  A\n";
  return ::operator new(sz);
}

void
A::operator delete(void* p) {
  std::cerr << "Delete A\n";
  ::operator delete(p);
}

