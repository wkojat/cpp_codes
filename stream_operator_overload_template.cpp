#include <iostream>
#include <vector>
using namespace std;

template <typename T>
ostream& operator<< (ostream &display, const vector<T> &w)
    {
        for (int i=0 ; i<w.size() ; i++)
        {
            display <<w[i] <<" ";
        }
        return display;
    }

int main ()
{
    vector <int> numbersInt {1, 2, 3, 4, 5};
    cout <<numbersInt <<endl;

    vector <double> numbersDou {3.12, 5.47, 9.31};
    cout <<numbersDou <<endl;

    vector <char> numbersCha {'b', 'k', 'r'};
    cout <<numbersCha <<endl;

    system ("pause");
}
