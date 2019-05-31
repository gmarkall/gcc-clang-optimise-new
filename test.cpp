#include <cstring>
#include <memory>
#include <algorithm>

void c_malloc() {
  char* x = (char*)malloc(1);
  *x = 'a';
  free(x);
}

void cpp_new() {
  char* x = new char;
  *x = 'a';
  delete x;
}

void cpp_unique_ptr() {
  auto x = std::make_unique<char>('a');
}

int main(int argc, char *argv[])
{
  c_malloc();
  cpp_new();
  cpp_unique_ptr();
}
