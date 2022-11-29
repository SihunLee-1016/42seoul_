class Cat : public Animal
{
    private:
        /* data */
    public:
        Cat();
        Cat(const Cat &obj);
        ~Cat();
        Cat& operator=(const Cat &obj);
        virtual void    makesound(void);
        virtual std::string    gettype();
};
