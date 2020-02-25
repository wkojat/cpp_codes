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
            cout <<"number entered correctly" <<endl;
            getline(cin, garbage);
            break;
        }
    }

    cout <<"entered number is " <<a <<endl;

    system ("pause");
}
