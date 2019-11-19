/* program sprawdza działanie przeładowanego operatora ++, a w tym istotną różnicę w ich kodzie:
   operator preinkrementacji zwraca poprzez referencję (bo najpierw jest inkrementacja, a potem obiekt jest wartością wyrażenia),
   operator postinkrementacji zwraca kopię obiektu sprzed inkrementacji (bo najpierw obiekt jest wartością wyrażenia
   a dopiero na sam koniec następuje inkrementacja) */

#include <iostream>
using namespace std;

class Basket
{
    public:
        int apples {10};
        Basket& operator++();
        Basket operator++(int);
};

Basket& Basket::operator++ ()       //PREinkrementacja
{
    apples = apples + 1;
    return *this;
}

Basket Basket::operator++ (int)     //POSTinkrementacja
{
    Basket result {*this};
    apples = apples + 1;
    return result;
}

int main (int argc, char *argv [])
{
    Basket wooden;
    cout <<"should be 10: " <<wooden.apples <<endl;

    ++wooden;
    cout <<"should be 11: " <<wooden.apples <<endl;

    wooden++;
    cout <<"should be 12: " <<wooden.apples <<endl;

    Basket wired {++wooden};
    cout <<"should be 13: " <<wired.apples <<endl;

    Basket plastic {wooden++};
    cout <<"should be 13: " <<plastic.apples <<endl;

    cout <<"should be 14: " <<wooden.apples <<endl;

    system ("pause");
}
