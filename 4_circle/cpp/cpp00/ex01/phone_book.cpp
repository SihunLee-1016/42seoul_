#include <iostream>
#include <string.h>
//class는 2개.
// 연락처의 배열. 8개까지 저장 가가능능
// 8개까지 저장 된 뒤 9번째가 입력된다면 가장 최근 저장된 8번째를 삭제하고 입력된 값을 저장

class contact
{
    private:
        std::string first;
        std::string last;
        std::string nickname;
        std::string phone_num;
        std::string secret;
    public :
        void    data_Add(void);
        void    data_Search(void);
        void    data_Exit(void);
        void    data_print(void);
};

class phone_book
{
    private :
        contact contacts[8];
        int     idx;
    public :
        phone_book(void) {
            contacts {};
            this->idx = 0;
        }
        void    cnt_Add(void);
        void    cnt_Search(void);
        void    cnt_Exit(void);
};

void    phone_book::cnt_Add(void)
{
    this->contacts[idx % 8].data_Add();
    this->idx++;
}

void    phone_book::cnt_Search(void)
{

}

void    phone_book::cnt_Exit(void)
{

}
void    contact::data_Add(void)
{
    std::cout << "first name" << std::endl;
    std::cin >> this->first;
    std::cout << "last name" << std::endl;
    std::cin >> this->last;
    std::cout << "nick name" << std::endl;
    std::cin >> this->nickname;
    std::cout << "phone number" << std::endl;
    std::cin >> this->phone_num;
    std::cout << "secret" << std::endl;
    std::cin >> this->secret;
}

void    contact::data_Search(void)
{

}

void    contact::data_Exit(void)
{

}

void    contact::data_print(void)
{
    std::cout << "first : " << this->first << std::endl;
}

int main(void)
{
    std::string cmd;
    phone_book  data;
    int     idx = 0;
    int     i = 0;

    while (idx != 3)
    {
        std::cout << "cmd (ADD, SEARCH, EXIT)" << std::endl;
        std::cin >> cmd;
        if (cmd == "ADD")
        {
            data.cnt_Add();
            idx++;
        }
        else if (cmd == "SEARCH")
        {

        }
        else if (cmd == "EXIT")
        {
            
        }
        else
        {
            std::cout << "cmd not found" << std::endl;
        }
    }

    while (i < idx)
    {
        data[idx].cnt_print();
        i++;
    }

    return (0);

}