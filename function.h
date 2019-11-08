#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <string>
#include "stos.h"

int sprawdzCzyX(int);
int sprawdzCzyKolor(std::string);
int wybierzIlosc(void);

auto getStos(size_t);
auto getStosByCin(size_t);

void doSomethingWithPolygonByReference(const Stos&);

void testStosByCin2(void);
void testStos(int );
void testStosByCin(void);




#endif // FUNCTION_H
