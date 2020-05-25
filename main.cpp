#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main()
{
	int liczby;
	fstream plik;  //deklaracja zmiennej pliku tekstowego
	queue < int > kolejkaLiczb;
	plik.open("D:\\Programy\\C++\\Kolejka\\plik.txt", ios::in);  //otwarcie pliku
	if (plik.good())  //sprawdzenie czy plik istnieje
		while (!plik.eof())  //petla wykonuje sie az program dojedzie do konca pliku
		{
			plik >> liczby;  //pobranie linii do zmiennej napis
			
			kolejkaLiczb.push(liczby);
			
		}
	plik.close();  //zamkniecie pliku tekstowego

	cout << "ContentType:application/json;charset=UTF-8" << (char)13 << (char)10
		<< "\n"
		<< "[ \n ";
	while (!kolejkaLiczb.empty()) {
		cout << "  { \"liczba\": \"" << kolejkaLiczb.front() << "\" }";
		if (kolejkaLiczb.size() != 1)
			cout << ",";
		cout << "\n";
		kolejkaLiczb.pop();
	}
	
	cout << "]";

	return 0;
}
