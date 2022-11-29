class Dog : public Animal
{
    private:
    public:
        Dog();
        Dog(const Dog &obj);
        Dog& operator=(const Dog &obj);
        ~Dog();
        virtual void    makesound(void);
        virtual std::string    gettype();
};
