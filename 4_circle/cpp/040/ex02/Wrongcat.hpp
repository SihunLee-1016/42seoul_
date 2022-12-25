#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "Wronganimal.hpp"
class Wrongcat : public Wronganimal
{
    private:
        /* data */
    public:
        Wrongcat();
        ~Wrongcat();
        Wrongcat(const Wrongcat &obj);
        Wrongcat& operator=(const Wrongcat &obj);
        virtual void    makesound(void) const;
        virtual std::string    gettype()const;
};

#endif