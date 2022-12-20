#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
  return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
  Data *ret;

  ret = reinterpret_cast<Data*>(raw);
  return (ret);
}

int main()
{
  uintptr_t     q;
  Data  ori;
  Data  *mod;
  ori.num = 1;

  q = serialize(&ori);

  std::cout << "q address : " << &ori << std::endl;
  std::cout << "q(tmp) to hex" << std::hex << q << std::endl<<std::endl;
  mod = deserialize(q);

  std::cout << "deserialized structure's num value : " << mod->num << std::endl;

	return (0);

}