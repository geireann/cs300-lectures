#include <vector>
#include <cstdio>

int main() {
  // declares a heap-allocated standard library vector of ints
  // similar to strvec's vector_t, but in C++. data on the heap!
  std::vector<int>* v = new std::vector<int>();

  // append 5 numbers to the vector
  v->push_back(41);
  v->push_back(42);
  v->push_back(43);
  v->push_back(44);
  v->push_back(45);

  // C-style iteration with a loop index works
  for (unsigned int i = 0; i < v->size(); i++) {
    printf("%d\n", v->at(i));
  }

  // below is the same, but uses C++ iterators
  for (auto it = v->begin(); it != v->end(); it++) {
    printf("%d\n", *it);
  }

  // frees the heap memory used for the vector
  delete v;
}
