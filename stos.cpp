#include "stos.h"

#include <iostream>
#include <string>
#include <cassert>


Stos::Stos(size_t size)
    : Stos(size, 0)
{

    std::cout<<"domyslny" <<std::endl;
}

Stos::Stos(const Stos & Copied)
  : Stos(Copied.size_, Copied.number_of_cards_)
{
    std::cout << "kopiujący" << std::endl;
    for(int i = 0; i < size_; ++i)
    {
        cards_[i] = Copied.cards_[i];
    }
}

Stos::Stos(Stos&& rhs)
  : Stos()
{
    std::cout <<"przenoszacy \n";
    swap(*this, rhs);
}

Stos::~Stos()
{
    if(nullptr!=cards_)
        {
        std::cout<<"zwalnianie pamieci1"<<std::endl;
        delete [] cards_;
        }
        else std::cout<<"zwalnianie pamieci2"<<std::endl;
}

Stos::Stos(size_t size, size_t number_of_cards)
    : size_(size), number_of_cards_(number_of_cards), cards_(new Karta[size_])
{
    // UWAGA :
    // tylko ten konstruktor alokuje pamiec,
    // wszystkie inne deleguja do niego zadanie przydzielenia pamieci
    std::cout << "alokacja pamieci" << std::endl;
}

//Stos & Stos::operator=(const Stos& rhs)
//{
//    //print_info("op = ");
//    std::cout << "opek" << std::endl;
////    swap(*this, Stos(rhs));
//    return *this;
//}

Stos & Stos::operator=(Stos&& rhs)
{
    std::cout << "op1\n";
    swap(*this, rhs);
    return *this;

}

Karta & Stos::operator[](size_t index)
{
    std::cout << "op2\n";
    assert(index < size_);
    return cards_[index];
}

Karta Stos::operator[](size_t index) const
{
    assert(index < size_);
    return cards_[index];
}

size_t Stos::numberOfCards() const
{
    return number_of_cards_;
}

void Stos::push(Karta karta)
{
    assert(number_of_cards_ < size_);
    cards_[number_of_cards_++] = karta;
}

void Stos::swap(Stos& lhs, Stos& rhs)
{
    std::swap(lhs.size_, rhs.size_);
    std::swap(lhs.number_of_cards_, rhs.number_of_cards_);
    std::swap(lhs.cards_, rhs.cards_);
}
