#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array
{
    private:
        unsigned int size;
        T *data;

    public:
        class OutofBound 
            : public std::exception{
        public :
            const char* what(void) const throw() {
                return "out of Bound";
            }
        };

        Array(void) : size(0), data(NULL){
        }
        
        Array(unsigned int n) : size(n){
            data = new T[n];
        }

        Array(const Array &obj) : size(obj.getsize()),data(NULL){
            if (size)
                data = new T[size];
            for(unsigned int i = 0; i < size; ++i)
                data[i] = obj[i];
        }

        Array & operator=(const Array &obj){
            if (size != 0){
                delete []data;
                size = obj.getsize();
                data = new T[size];
            }
            for(unsigned int i = 0; i < size; i++)
                data[i] = obj[i];
            return *this;
        }

        T & operator [](unsigned int i) const {
            if (i >= size)
                throw OutofBound();
            return data[i];
        }

        ~Array(){
            if (size != 0)
                delete []data;
                // data = NULL;
                // size = 0;
        }
        
        unsigned int getsize() const {
            return (size);
        }
};
#endif
