#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

	int smaller, bigger;

	void funkcja(int A[], int len ,int k) // wstawia funkcje
	{
		fstream plik; // tworzy plik
		plik << "Twoje pary to: "<< endl;
		plik.open ("wynik.txt",ios::out); // otwiera zapis do pliku
		vector<int> used_numbers = {}; //tablica dynamiczna
    	bool used; //zmienna true albo false

   			for(int i = 0; i < len; i++) // pętla pobiera po kolei liczbę z tablicy
    {
        for(int j = 0; j < len; j++) //pętla pobiera po kolei liste z tablicy
        {
            if(A[i] < A[j]) // porównuje wielokość cyfr
            {
                smaller = A[i];
                bigger = A[j];
            }
            else
            {
                smaller = A[j];
                bigger = A[i];
            }
            if(bigger - smaller == k) //różnica liczb daje nam nasze k
            {
                used = false; // zmienna bool fałszywa;
                for(int m = 0; m < used_numbers.size(); m++) // Dzięki tej funkcji nie duplikują się pary
                {
                    if(smaller == used_numbers[m]) // sprawdza czy liczba smaller znajduje się już w talicy dynamicznej
                    {
                        used = true;
                    }
                }
                if(used == false)
                {
                    used_numbers.push_back(smaller); // wpycha na koniec vectora użytą liczbe


                    cout << "[" << smaller << ", " << bigger << "]" << endl;
                    																// wypisuje liczby na konsole i do pliku
                    plik << "[" << smaller << ", " << bigger << "]" << endl;
                }
            }
        }
    }
    	plik.close(); // zamyka zapis do pliku
	}

	int main () {

	cout <<"Wprowadz z klawiatury (1)" << endl;
	cout <<"Wprowadz z pliku (2)" << endl;

		int wybor;
	cout <<"Wybierz metode" << endl;
	cin >> wybor;

	switch (wybor) { // wybór metody wprowadzania

		case 1: {	// przypadek 1

	int len,k;

	cout << "podaj ilosc liczb w tablicy: ";
    cin >> len;
    cout << "podaj roznice: ";
    cin >> k;
    int A[len];

     for (int j=0; j<len; j++) { // prosi o wypisanie liczby len - 1 razy[numeracja tablicy od 0]
        cout << endl << "podaj " <<j+1<< ". liczbe w tablicy: ";
        cin >> A[j]; }
        cout << "Twoje pary to: "<< endl;
        funkcja(A,len ,k); // uruchamiana funkcje

	break;
		}

	case 2:{ // przypadek 2

		int k, Alen=0;
		cout << "Podaj roznice: ";
		cin >> k;

		ifstream plik3;
		plik3.open("liczby.txt", ios::in); //zapisywanie z pliku

		string linia;
		while(getline(plik3, linia)){Alen++;} //dlugosc tablicy wyliczona poprzez zliczenie linijek wierszy
		plik3.clear();  // czyści flagi na otwarciu pliku
		plik3.seekg(0,plik3.beg); // wstawianie kursora na początek pliku
		int z[Alen]	= {0}; // tworzy tabele o nazwie z o długości Alen
		int numery = 0;
		while (getline(plik3,linia)) { //dzięki funkcji getline czytamy pokolei wiersze w pliku
			z[numery++] = atoi(linia.c_str()); //zmienia string na int
		}

        plik3.close();
        funkcja(z,Alen ,k);
	}
		break;
}
return 0; // kończy program
}
