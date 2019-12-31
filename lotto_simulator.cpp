//symulator losowania lotto
//po wprowadzeniu przez u�ytkownika 6 wybranych liczb z zakresu 1-49, program losuje swoje 6 liczb z 49,
//a� do momentu trafienia "sz�stki"; podana zostaje r�wnie� liczba przeprowadzonych losowa�

#include <iostream>		//cin, cout
#include <cstdlib>		//rand, srand
#include <ctime>		//time
#include <vector>		//vector container, erase, size

using namespace std;

//deklaracje funkcji
void number_generator (vector <int> total, int draw []);
bool all_check (int gen [], int use []);
bool single_check (int genNum, int useNum []);

//inicjalizacja sta�ych globalnych
constexpr int TOTAL_QUANTITY {49};
constexpr int DRAW_QUANTITY {6};

int main ()
{
	srand (time(NULL));											//funkcja bibl., dzi�ki kt�rej funkcja rand b�dzie losowa�a za ka�dym razem inn� liczb�

	int generated_numbers [DRAW_QUANTITY] = {};					//tablica dla 6 liczb wylosowanych
	int user_numbers [DRAW_QUANTITY] = {};						//tablica dla 6 liczb wybranych
	unsigned long long int counter {0};							//licznik losowa�

	vector <int> pool (TOTAL_QUANTITY);							//wektor zawieraj�cy ca�kowit� pul� liczb
	for (int i=0 ; i<pool.size() ; i++)							//zape�nienie wyktora liczbami od 1 do 49
		pool [i] = i+1;

	for (auto &k: user_numbers)									//wprowadzenie wybranych 6 liczb
		cin >>k;

	bool win {false};											//zmienna logiczna, b�d�ca warunkiem dla p�tli losowania i sprawdzania
	do															//p�tla losowania i sprawdzania, wykonuje si� dop�ki nie trafi si� sz�stka
	{
		number_generator (pool, generated_numbers);				//wywo�anie funkcji losuj�cej 6 liczb
		counter++;												//inkrementacja licznika losowa� po ka�dym wykonaniu funkcji losuj�cej 6 liczb
		win = all_check (generated_numbers, user_numbers);		//wywo�anie funkcji sprawdzaj�cej trafienie sz�stki, zwrot jej rezultatu do zmiennej win
	} while (win != true);										//warunek p�tli: dop�ki funkcja sprawdzaj�ca 6 liczb zwraca warto�� false

	cout <<endl <<"it took " <<counter <<" tries" <<endl;		//podanie ko�cowej liczby losowa�

	system ("pause");
}


//--------------- function 01 ---------------					//funkcja losuj�ca 6 r�nych liczb
void number_generator (vector <int> total, int draw [])
{
	for (int i=0, k=0 ; i<DRAW_QUANTITY ; i++)					//wielko�� tablicy to zmienna globalna, nie trzeba jej wysy�a� ani pisa� 6 w warunku
	{
		k = rand() %total.size();								//losuje indeks z puli kolejnych int-�w o wielko�ci wektora (49), w zakresie od 0 do 48
		draw [i] = total [k];									//liczb� z wektora o indeksie k wpisuje do tablicy w miejsce o indeksie i
		total.erase (total.begin() +k);							//funkcja dostaje kopi� wektora, wi�c mo�na z niego usuwa� elementy w zakresie funkcji
	}															//bo przy ponownym jej wywo�aniu (kolejne losowanie) zn�w otrzyma kopi� ca�ego wektora
}


//--------------- function 02 ---------------					//funkcja do sprawdzania trafienia wszystkich sze�ciu liczb
bool all_check (int gen [], int use [])							//odbiera adres tablicy liczb wylosowanych oraz adres tablicy liczb wybranych
{
	bool (*ptr)(int, int []) = nullptr;							//wska�nik do funkcji (w zasadzie niepotrzebne)
	ptr = &single_check;										//ustawienie wska�nika na funkcj� sprawdzaj�c� pojedy�cz� liczb�
	for (int i=0 ; i<DRAW_QUANTITY ; i++)
	{
		if ((*ptr)(gen [i], use) == true);						//wywo�anie funkcji do pojedy�czych liczb z argumentami: dana liczba i liczby u�ytkownika
		else													//je�li funkcja zwr�ci�a warto�� true (czyli liczba trafiona) to kolejny obieg
			return false;										//z kolejn� liczb�, je�li zwr�ci�a falsa (nie trafiona) to ta function 02 r�wnie�
	}															//zwraca false i rozpoczyna si� nowe losowanie
	return true;
}


//--------------- function 03 ---------------					//funkcja do sprawdzania trafienia pojedy�czej liczby
bool single_check (int gen_num, int use_num [])					//odbiera jedn� wylosowan� liczb� przez warto��, oraz adres tablicy liczb wybranych
{
	for (int k=0 ; k<DRAW_QUANTITY ; k++)
	{
		if (gen_num == use_num [k]) return true;				//je�li trafiona, to funkcja si� ko�czy zwracaj�c true, je�li nie to kolejny obieg
	}
	return false;												//je�li w sze�ciu obiegach nie trafiona, to funkcja zwraca false
}

//--------------- koniec programu -----------------------------------------------------------------------------------------------------------------
