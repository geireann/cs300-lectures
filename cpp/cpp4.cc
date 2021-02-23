#include <string>

int main() {
  // std::string is a dynamic, heap-allocated string that you can grow and shrink
  std::string my_string("hello");
  my_string.append(" world!");

  // to print a std::string, use .c_str() on it
  printf("%s\n", my_string.c_str());
}
