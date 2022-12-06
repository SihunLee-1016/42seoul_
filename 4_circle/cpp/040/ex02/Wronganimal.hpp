#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>
#include <string>
class Wronganimal
{
    protected :
        std::string type;
    private:
    public:
        Wronganimal();
        Wronganimal(const Wronganimal &obj);
        virtual ~Wronganimal();
        Wronganimal& operator=(const Wronganimal &obj);
        virtual void    makesound(void) const;
        virtual std::string gettype() const;
};
#endif