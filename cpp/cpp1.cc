#include <stdio.h>

class Animal {
 public:
  const char* name_;
  int age_;

 private:
  int weight_;

 public:
  // constructor; automatically gets invoked when
  // making a new instance (object) of class Animal,
  // after memory has been set aside for it
  Animal(const char* name, int age) : name_(name), age_(age) {
  }

  void setWeight(int weight) {
    if (weight < 0) {
      printf("error\n");
    }
    this->weight_ = weight;
  }

  int getWeight() {
    return this->weight_;
  }
};

void herd_animals() {
  // makes a new stack-allocated instance of class Animal
  Animal stack_a("kitty", 1);

  printf("stack_a.age_ is at %p\n", &stack_a.age_);

  printf("name: %s, age: %d, weight: %d\n",
         stack_a.name_, stack_a.age_, stack_a.getWeight());

  // makes a new heap-allocated instance of class Animal
  //Animal* heap_a = new Animal("bob", 5);
  //heap_a->name_ = "chunky bob";

  // won't work, because weight_ is a private member
  //heap_a->weight_ = 99;
  //
  // need to use getName() because name_ is a private member
  //heap_a->setWeight(99);

  //printf("name: %s, weight: %d\n",
  //       heap_a->name_, heap_a->getWeight());
}

int f() {
  const char* x = "yo";
  int y = 999;
  int z = 999;
  printf("x: %p, y: %p, z: %p\n", &x, &y, &z);

  return z;
}

int main() {
  f();
  herd_animals();

  return 0;
}
