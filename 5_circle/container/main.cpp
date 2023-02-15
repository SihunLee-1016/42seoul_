#include <iostream>
#include <vector>
#include <stdio.h>
template <typename T>
void PrintVector(const std::vector<T> &vec) {
  std::cout << "[[PRINT VECTOR]]" << std::endl;
  for (size_t i = 0; i < vec.size(); ++i)
    std::cout << "index :" << i << " ||  value  ||\n" << vec[i] << std::endl;
}

struct Add{
    public: 
	Add(int toAdd) : _toAdd(toAdd) {
        std::cout << "add functor constructor activated" << std::endl;
        std::cout << _toAdd << std::endl;
    }
	int operator()(int x){
		return x + _toAdd;
	}
	int _toAdd;
	private:
};

int main(){
	Add add_42(42); // state 저장
    std::cout << "42 value 0 : "<<add_42._toAdd << std::endl;
    // printf("42 value : %d \n",add_42 );
	Add add_13(13);
    int result_42 = add_42(2);
    std::cout << "42 value 1 : "<<add_42._toAdd << std::endl;
	int result_13 = add_13(2);
    std::cout << result_42 << " || " << result_13 << std::endl;
	
    std::cout <<  "42 value 2 : "<< add_42._toAdd << std::endl;
    std::vector<int> v(10, 10);
	std::transform(v.begin(), v.end(), v.begin(), add_42);
}
// int main()
// {
//     std::cout << "hi" << std::endl;
// }