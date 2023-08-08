#include "Warlock.hpp"


Warlock::Warlock(std::string const &name, std::string const &title)
{
    this->name = name;
    this->title = title;
    std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
    std::map<std::string, ASpell *>::iterator it_b = data.begin();
    std::map<std::string, ASpell *>::iterator it_e = data.end();
    while (it_b != it_e)
    {
        delete it_b->second;
        it_b++;
    }
    this->data.clear();

    std::cout << this->name << ": My job here is done!\n";
}

std::string const &Warlock::getName() const
{
    return (this->name);
}

std::string const &Warlock::getTitle() const
{
    return (this->title);
}

void Warlock::setTitle(std::string const &title)
{
    this->title = title;
}

void Warlock::introduce() const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

void Warlock::learnSpell(ASpell *spell)
{
    ASpell *magic = 0;
    if (magic == spell)
        return ;
    if (spell)//pair로 넣는 두번째 인자가 clone인걸 까먹지말기.
        data.insert(std::pair<std::string, ASpell *>(spell->getName(),spell->clone()));
}

void Warlock::forgetSpell(std::string spellname)
{
    //find로 spellname 넣어야함.
    std::map<std::string, ASpell *>::iterator it = data.find(spellname);
    if(it != data.end())
        delete it->second;
    data.erase(spellname);
}

void Warlock::launchSpell(std::string spell_name, ATarget const & atarget_ref)
{
    //값을 map에서 찾는걸로.
    ASpell *magic = data[spell_name];
    //gethitby가 아닌 launch 실행
    if (magic)
        magic->launch(atarget_ref);
}


