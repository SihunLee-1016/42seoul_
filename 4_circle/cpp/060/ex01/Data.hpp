#include <iostream>
#include <cstdint>

struct Data {
  int num;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
