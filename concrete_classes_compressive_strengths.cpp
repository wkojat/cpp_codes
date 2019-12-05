/*english
program determines design compressive strength of concrete class chosen by user;
a 'map' container was used to hold concrete classes and their corresponding compressive strentghs - fcd;
program supports situation when incorrect concrete class symbol was entered by user;
functions specific for containers from STL library were used;
(consrete's design compressive strength is one of parameters used in calculations for civil engineering projects);
*/

/*polski
program określa wartość obliczeniowej wytrzymałości na ściskanie dla klasy betonu wybranej przez użytkownika;
przykładowe klasy betonu oraz odpowiadające im wytrzymałości fcd zebrane zostały w kontenerze typu 'mapa';
w kodzie zawarte jest zabezpieczenie przed wprowadzeniem niepoprawnego oznaczenia klasy betonu;
użyto funkcji właściwych kontenerom z biblioteki STL;
(wytrzymałość obliczeniowa betonu na ściskanie wykorzystywana jest w wielu projektach budownictwa lądowego i wodnego);
*/

#include <iostream>     //cin, cout
#include <map>          //map container; find, end functions
#include <string>       //string object
using namespace std;

int main ()
{
    map <string, double> concrete_classes =
        {
            {"C12/15",  8.6},
            {"C16/20", 11.4},
            {"C20/25", 14.3},
            {"C25/30", 17.9},
            {"C30/37", 21.4}
        };

    string chosen_concrete_class;
    double determined_concrete_strength {0};

    cout <<"Enter concrete class: C12/15, C16/20, C20/25, C25/30 or C30/37: ";
    cin >>chosen_concrete_class;

    map <string, double>::iterator result = concrete_classes.find (chosen_concrete_class);       //explanations below

    if (result == concrete_classes.end ())                   //if no key was found
        cout <<"Incorrect concrete class" <<endl;
    else
    {
        determined_concrete_strength = result->second;       //explanations below
        cout <<"Design compressive strength for " <<chosen_concrete_class
             <<" concrete class is fcd = " <<determined_concrete_strength <<" MPa." <<endl;
    }

    system ("pause");
}

/*
additional explanations:
1.  concrete classes and their fcd values are stored in a map container
2.  user chosen concrete class is assigned to string object
3.  STL specific function 'find' searches for that key in map and returns a iterator to specific element
4.  if no key was found, function returns iterator to map::end, which referrs to a 'theoretical' element
    that would follow the last one (same as function 'end')
5.  if a key was found, corresponding mapped value is assigned determined_concrete_strength variable
6.  result->second refers to the second element of the pair (corresponding value in the map)
    (dereferencing map's iterator gives a std::pair<const key_tye, mapped_type>, which key and its corresponding value
    can be accessed through two members: first and second)
*/
