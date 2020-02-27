/*
zabezpieczenie przed wpisaniem przez użytkownika nieprawidłowej wartości dla zmiennej typu int
program obsługuje takie niepoprawne warianty jak np.: "jsd.b", "rw78cx-" albo "14gnk"
(czyli gdy w strumieniu nie ma liczby, liczba znajduje się pomiędzy innymi znakami
albo przed innymi znakami)
*/

#include <iostream>
#include <string>
using namespace std;

int main ()
{
    int a {0};

    while (true)
    {
        string garbage;
        cout <<"enter integer number: ";
        cin >>a;
        if (cin.fail())
        {
            cout <<"error: typed characters are not an integer number" <<endl;
            cin.clear(cin.rdstate() & ~ios::failbit);
            getline(cin, garbage);
        }
        else
        {
            getline(cin, garbage);
            if(garbage.empty())
            {
                cout <<"number entered correctly" <<endl;
                break;
            }
            else
            {
                cout <<"error: typed characters are not an integer number" <<endl;
            }
        }
    }
    cout <<"entered number is " <<a <<endl;

    system ("pause");
}
