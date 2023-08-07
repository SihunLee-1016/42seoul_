#include <iostream>

class Warlock
{
    private :
        std::string name;
        std::string title;

        std::string const& getName() const;
        std::string const& getTitle() const;


    public:
        void const setTitle(std::string const &  ) const;
        Warlock(std::string const &name_, std::string const &title);

};