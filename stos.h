#ifndef STOS_H
#define STOS_H

#include <iostream>
#include <string>

struct Karta
{
   int x;
   std::string kolor;
};

class Stos
{
public:
    Stos(size_t size);
    Stos(const Stos&); //konstruktor kopiujacy
    Stos(Stos&&); //konstruktor przenoszący

    Stos& operator=(const Stos&);
    Stos& operator=(Stos&&);

    void push(Karta);


    size_t numberOfCards() const;
    Karta& operator[](size_t index);
    Karta operator[](size_t index) const;

    ~Stos();

private:
    Stos() = default;
    Stos(size_t size, size_t number_of_cards);

    void swap(Stos&, Stos&);

    size_t size_ = 0;
    size_t number_of_cards_ = 0;
    Karta* cards_ = nullptr;
};

#endif // STOS_H
