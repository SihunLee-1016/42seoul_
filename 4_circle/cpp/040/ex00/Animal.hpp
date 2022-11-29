#include <iostream>
#include <string>
class Animal
{
    protected :
        std::string type;
    private:
    public:
        Animal();
        Animal(const Animal &obj);
        ~Animal();
        Animal& operator=(const Animal &obj);
        virtual void    makesound(void);
        virtual std::string const gettype();
};