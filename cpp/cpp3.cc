#include <map>

int main() {
  // stack-allocated key -> value map; data is on the heap!
  // (this allocates memory internally)
  std::map<const char*, int> my_map;
  // add entries
  my_map.emplace("alice", 12);
  my_map.emplace("bob", 42);

  printf("alice -> %d\n", my_map.at("alice"));
  printf("bob -> %d\n", my_map.at("bob"));

  // iterate over the map using a C++ iterator
  // the "auto" syntax is identical to:
  // for (std::map<char*, int>::iterator it = my_map.begin(); it != my_map.end(); it++) {
  // ... we're just leaving the compiler to figure out the iterator type for us.
  //for (auto it = my_map.begin(); it != my_map.end(); it++) {
  //  // *it is a std::pair<key type, value type>, which has members `first` and `second`
  //  printf("%s -> %d\n", it->first, it->second);
  //}
}
