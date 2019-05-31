#include <cstdlib>
#include <new>
#include <iostream>

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
