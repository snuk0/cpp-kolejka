#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main()
{
	int liczby;
	fstream plik;  //deklaracja zmiennej pliku tekstowego

	plik.open("plik.txt", ios::in);  //otwarcie pliku


	cout << "ContentType:application/json;charset=UTF-8" << (char)13 << (char)10
		<< "\n"
		<< "[ \n ";
		if (plik.good())  //sprawdzenie czy plik istnieje
			while (!plik.eof())  //petla wykonuje sie az program dojedzie do konca pliku
			{
				plik >> liczby;  //pobranie linii do zmiennej napis
				queue < int > kolejkaLiczb;
				kolejkaLiczb.push(liczby);
				cout << "  { \"liczba\":\" " << liczby << "\" }, \n";

				cout << endl;
			}
		plik.close();  //zamkniecie pliku tekstowego
	cout << "]";

	return 0;
}
