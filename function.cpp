#include "function.h"

#include <iostream>
#include <string>
#include <cassert>

int sprawdzCzyX(int x)
{
    if (x<2 || x>10)
    {
        std::cout << "zla wartosc! podaj nr karty od 2 do 10 \n" ;
        return 1;
    }   else return 0;
}

int sprawdzCzyKolor(std::string kolor)
{
    if (kolor != "karo" && kolor != "pik" && kolor != "trefl" && kolor != "kier")
    {
        std::cout << "Zly kolor, podaj: kier, karo, pik lub trefl :) \n ";
        return 1;
    }   else return 0;
}

int wybierzIlosc(void)
{
    int x;
    std::cout << "\nPodaj wielkość talii: \n";
    std::cin >> x;
    return x;
}

auto getStos(size_t size = 4)
{
    auto result = Stos(size);
    result.push({4, "kier"});
    result.push({5, "karo"});
    result.push({9, "trefl"});
    result.push({6, "pik"});

    return result;
}

auto getStosByCin(size_t size = 4)
{
    int x = 0;
    std::string kolor = " ";
    auto result = Stos(size);
        for (auto i = 0.0; i < size; ++i)
            {
                std::cout << "Podaj nr: ";
                std::cin >> x;
                while(sprawdzCzyX(x)==1)
                {
                    std::cin >> x;
                }
                std::cout << "Podaj kolor:";
                std::cin >> kolor;
                while(sprawdzCzyKolor(kolor)==1)
                {
                    std::cin >> kolor;
                }
                result.push({ x , kolor});
            }
        return result;

}

void doSomethingWithPolygonByReference(const Stos& stos)
{
    std::cout << "\n";
    for (auto i = 0; i < stos.numberOfCards(); ++i)
    {
        std::cout << "<" << stos[i].x << "," << stos[i].kolor << "> ";
    }
    std::cout << "\n\n";
}



void testStos(int x)
{
    std::cout << "___TEST1\n" << std::endl;
    auto karta3 = getStos(x);
    doSomethingWithPolygonByReference(karta3);
}
void testStosByCin2(void)
{
    int x = wybierzIlosc();
    std::cout << "___TEST2\n" << std::endl;
    auto karta5 = getStosByCin(x);
    doSomethingWithPolygonByReference(karta5);
}
void testStosByCin(void)
{
    int x = wybierzIlosc();
    std::cout << "___TEST2\n" << std::endl;
    auto karta4 = getStosByCin(x);
    doSomethingWithPolygonByReference(karta4);
}
