/* english
program tests overload of operator++ (both pre- and postincrementation versions) for examplary user-defined class;
preincrementation operator returns an object by reference (at first incrementation happens,
and then object is used in an expression);
postincrementation operator returns by value a copy of an object before its incrementation
(at first object is used in an expression, and then incrementation of that object happens)
*/

/* polski
program sprawdza działanie przeładowanego operatora ++, a w tym istotną różnicę w ich kodzie:
operator preinkrementacji zwraca poprzez referencję (najpierw następuje działanie operatora ++,
a potem obiekt staje się wartością wyrażenia);
operator postinkrementacji zwraca kopię obiektu sprzed inkrementacji (najpierw obiekt jest wartością
wyrażenia, a dopiero na koniec następuje działanie operatora ++)
*/


#include <iostream>     //std::cout
using namespace std;

class Basket
{
    public:
        int apples {10};

        Basket& operator++();       //PREincrementation operator overload
        Basket operator++(int);     //POSTincrementation operator overload
};

Basket& Basket::operator++ ()
{
    apples = apples + 1;
    return *this;
}

Basket Basket::operator++ (int)     //unnamed argument of int type is required to distinguish this operator from the one above
{
    Basket result {*this};          //default copy constructor
    apples = apples + 1;
    return result;
}

int main (int argc, char *argv [])
{
    cout <<"overload of both operator++ functions for examplary user-defined class tests:" <<endl;

    Basket first;
    cout <<"should be 10: " <<first.apples <<endl;

    ++first;
    cout <<"should be 11: " <<first.apples <<endl;

    first++;
    cout <<"should be 12: " <<first.apples <<endl;

    Basket second {++first};                                //default copy constructor
    cout <<"should be 13: " <<second.apples <<endl;

    Basket third {first++};                                 //default copy constructor
    cout <<"should be 13: " <<third.apples <<endl;

    cout <<"should be 14: " <<first.apples <<endl;

    system ("pause");
}
