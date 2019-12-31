//symulator losowania lotto
//po wprowadzeniu przez u¿ytkownika 6 wybranych liczb z zakresu 1-49, program losuje swoje 6 liczb z 49,
//a¿ do momentu trafienia "szóstki"; podana zostaje równie¿ liczba przeprowadzonych losowañ

#include <iostream>		//cin, cout
#include <cstdlib>		//rand, srand
#include <ctime>		//time
#include <vector>		//vector container, erase, size

using namespace std;

//deklaracje funkcji
void number_generator (vector <int> total, int draw []);
bool all_check (int gen [], int use []);
bool single_check (int genNum, int useNum []);

//inicjalizacja sta³ych globalnych
constexpr int TOTAL_QUANTITY {49};
constexpr int DRAW_QUANTITY {6};

int main ()
{
	srand (time(NULL));											//funkcja bibl., dziêki której funkcja rand bêdzie losowa³a za ka¿dym razem inn¹ liczbê

	int generated_numbers [DRAW_QUANTITY] = {};					//tablica dla 6 liczb wylosowanych
	int user_numbers [DRAW_QUANTITY] = {};						//tablica dla 6 liczb wybranych
	unsigned long long int counter {0};							//licznik losowañ

	vector <int> pool (TOTAL_QUANTITY);							//wektor zawieraj¹cy ca³kowit¹ pulê liczb
	for (int i=0 ; i<pool.size() ; i++)							//zape³nienie wyktora liczbami od 1 do 49
		pool [i] = i+1;

	for (auto &k: user_numbers)									//wprowadzenie wybranych 6 liczb
		cin >>k;

	bool win {false};											//zmienna logiczna, bêd¹ca warunkiem dla pêtli losowania i sprawdzania
	do															//pêtla losowania i sprawdzania, wykonuje siê dopóki nie trafi siê szóstka
	{
		number_generator (pool, generated_numbers);				//wywo³anie funkcji losuj¹cej 6 liczb
		counter++;												//inkrementacja licznika losowañ po ka¿dym wykonaniu funkcji losuj¹cej 6 liczb
		win = all_check (generated_numbers, user_numbers);		//wywo³anie funkcji sprawdzaj¹cej trafienie szóstki, zwrot jej rezultatu do zmiennej win
	} while (win != true);										//warunek pêtli: dopóki funkcja sprawdzaj¹ca 6 liczb zwraca wartoœæ false

	cout <<endl <<"it took " <<counter <<" tries" <<endl;		//podanie koñcowej liczby losowañ

	system ("pause");
}


//--------------- function 01 ---------------					//funkcja losuj¹ca 6 ró¿nych liczb
void number_generator (vector <int> total, int draw [])
{
	for (int i=0, k=0 ; i<DRAW_QUANTITY ; i++)					//wielkoœæ tablicy to zmienna globalna, nie trzeba jej wysy³aæ ani pisaæ 6 w warunku
	{
		k = rand() %total.size();								//losuje indeks z puli kolejnych int-ów o wielkoœci wektora (49), w zakresie od 0 do 48
		draw [i] = total [k];									//liczbê z wektora o indeksie k wpisuje do tablicy w miejsce o indeksie i
		total.erase (total.begin() +k);							//funkcja dostaje kopiê wektora, wiêc mo¿na z niego usuwaæ elementy w zakresie funkcji
	}															//bo przy ponownym jej wywo³aniu (kolejne losowanie) znów otrzyma kopiê ca³ego wektora
}


//--------------- function 02 ---------------					//funkcja do sprawdzania trafienia wszystkich szeœciu liczb
bool all_check (int gen [], int use [])							//odbiera adres tablicy liczb wylosowanych oraz adres tablicy liczb wybranych
{
	bool (*ptr)(int, int []) = nullptr;							//wskaŸnik do funkcji (w zasadzie niepotrzebne)
	ptr = &single_check;										//ustawienie wskaŸnika na funkcjê sprawdzaj¹c¹ pojedyñcz¹ liczbê
	for (int i=0 ; i<DRAW_QUANTITY ; i++)
	{
		if ((*ptr)(gen [i], use) == true);						//wywo³anie funkcji do pojedyñczych liczb z argumentami: dana liczba i liczby u¿ytkownika
		else													//jeœli funkcja zwróci³a wartoœæ true (czyli liczba trafiona) to kolejny obieg
			return false;										//z kolejn¹ liczb¹, jeœli zwróci³a falsa (nie trafiona) to ta function 02 równie¿
	}															//zwraca false i rozpoczyna siê nowe losowanie
	return true;
}


//--------------- function 03 ---------------					//funkcja do sprawdzania trafienia pojedyñczej liczby
bool single_check (int gen_num, int use_num [])					//odbiera jedn¹ wylosowan¹ liczbê przez wartoœæ, oraz adres tablicy liczb wybranych
{
	for (int k=0 ; k<DRAW_QUANTITY ; k++)
	{
		if (gen_num == use_num [k]) return true;				//jeœli trafiona, to funkcja siê koñczy zwracaj¹c true, jeœli nie to kolejny obieg
	}
	return false;												//jeœli w szeœciu obiegach nie trafiona, to funkcja zwraca false
}

//--------------- koniec programu -----------------------------------------------------------------------------------------------------------------
