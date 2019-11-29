/*english
program gives design compressive strength of concrete class chosen by user;
a map container was used to hold concrete classes and their corresponding compressive strentghs;
program supports situation when incorrect concrete class symbol was entered by user;
*/

#include <iostream>     //cin, cout
#include <map>          //map container
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
    double defined_concrete_strength {0};

    cout <<"Podaj klase betonu: C12/15, C16/20, C20/25, C25/30 lub C30/37: ";
    cin >>chosen_concrete_class;

    map <string, double>::iterator value = concrete_classes.find (chosen_concrete_class);

    if (value == concrete_classes.end ())
        cout <<"Podano niepoprawne oznaczenie klasy betonu" <<endl;
    else
    {
        defined_concrete_strength = value->second;                                                //patrz niżej
        cout <<"Wytrzymalosc na sciskanie betonu dla zadanej klasy " <<chosen_concrete_class
             <<" wynosi fcd = " <<defined_concrete_strength <<" MPa." <<endl;
    }

    system ("pause");
}

/*
wyjaśnienia do uporządkowania:
jeżeli mapa nie zawiera klucza z wywołania funkcji find, to zwróci iterator ustawiony na "toretyczny" element
znajdujący się po ostatnim elemencie w mapie - stąd możliwy warunek sprawdzający z linii 31

obiekt_pokazywany_wskaznikiem -> jego_dana_o_nazwie_second, ponieważ
iterator o nazwie value jest tutaj obiektem typu pair<const key_type, mapped_type>, dlatego do odniesienia się do jego drugiej
danej składowej (wartość) używa się powyższego zapisu; dla pierwszej danej składowej (klucz) byłoby to first
*/
