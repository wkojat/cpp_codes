/*
zabezpieczenie przed wpisaniem przez użytkownika nieprawidłowej wartości dla zmiennej typu int
program obsługuje takie niepoprawne warianty jak np.: "jsd.b", "rw78cx-" albo "14gnk"
(czyli gdy w strumieniu nie ma liczby, liczba znajduje się pomiędzy innymi znakami
albo przed innymi znakami); zaakceptowana zostanie jedynie sytuacja, gdy wpisana zostanie sama
liczba całkowita (plus ewentualne białe znaki - sytuacja domyślna)
*/

#include <iostream>
#include <string>
using namespace std;

int main ()
{
    int value {0};
    string garbage;

    while (true)
    {
        int temp;
        cout <<"enter integer number: ";
        cin >>temp;
        if (cin.fail())
        {
            cout <<"error: typed characters are not an integer number" <<endl;
            cin.clear(cin.rdstate() & ~ios::failbit);
            getline(cin, garbage);
            garbage.clear();
        }
        else
        {
            getline(cin, garbage);
            if(garbage.empty())
            {
                value = temp;
                cout <<"number entered correctly" <<endl;
                break;
            }
            else
            {
                cout <<"error: typed characters are not an integer number" <<endl;
                garbage.clear();
            }
        }
    }
    cout <<"entered number is " <<value <<endl;

    system ("pause");
}
