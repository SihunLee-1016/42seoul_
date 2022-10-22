#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

//문자열 상수참조를 반환 -> 문자열을 반환한다고 보면 될까?
int main()
{
  {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
  }
  {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
  }
}
