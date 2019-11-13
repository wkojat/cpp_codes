//function template that overloads operator<< (putting into stream) for vectors
//contatining fundamental built-in types of variables

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
    cout <<"content of vectors with overloaded operator<< :" <<endl;

    vector <int> vec_int {4, 7, 9};
    cout <<vec_int <<endl;

    vector <double> vec_dou {3.12, 5.47, 9.31};
    cout <<vec_dou <<endl;

    vector <char> vec_char {'b', 'k', 'r'};
    cout <<vec_char <<endl;

    system ("pause");
}
