#include "instancja.h"

using namespace std;

instancja::instancja() {
	long ziarno;
	long suma_p = 0;

	cout << "Wprowadz ziarno losowania: ";
	cin >> ziarno;
	RandomNumberGenerator generator = RandomNumberGenerator(ziarno);

	cout << "Wprowadz ilosc zadan: ";
	cin >> ilosc_zadan;

	for (int i = 0; i < ilosc_zadan; i++) { //Losowanie wartosci p
		lista_zadan.push_back(zadanie());
		lista_zadan[i].j = i + 1;

		lista_zadan[i].p = generator.nextInt(1, 29);
		suma_p += lista_zadan[i].p;
	}

	for (int i = 0; i < ilosc_zadan; i++) { //Losowanie wartosci w
		lista_zadan[i].w = generator.nextInt(1, 9);
	}


	for (int i = 0; i < ilosc_zadan; i++) { //Losowanie wartosci d
		//lista_zadan[i].d = generator.nextInt(1, suma_p);
		lista_zadan[i].d = generator.nextInt(1, 29); //W ramach testu czy zakres d ma wplyw na dzialanie algorytmu
	}
}

void instancja::wypiszTabele() {
	cout << endl << "j: [";
	for (int i = 0; i < ilosc_zadan; i++) {
		cout << lista_zadan[i].j;
		if (i == ilosc_zadan - 1) { //Jesli ostatni element
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}

	cout << endl << "p: [";
	for (int i = 0; i < ilosc_zadan; i++) {
		cout << lista_zadan[i].p;
		if (i == ilosc_zadan - 1) { //Jesli ostatni element
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}

	cout << endl << "w: [";
	for (int i = 0; i < ilosc_zadan; i++) {
		cout << lista_zadan[i].w;
		if (i == ilosc_zadan - 1) { //Jesli ostatni element
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}

	cout << endl << "d: [";
	for (int i = 0; i < ilosc_zadan; i++) {
		cout << lista_zadan[i].d;
		if (i == ilosc_zadan - 1) { //Jesli ostatni element
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}
}

vector<long> instancja::domyslnePi() {
	vector<long> pi;
	for (int i = 0; i < ilosc_zadan; i++) {
		pi.push_back(lista_zadan[i].j);
	}
	return pi;
}

void instancja::wypiszPi(vector<long> pi) {
	cout << endl << "Pi: [";
	for (int i = 0; i < pi.size(); i++) {
		cout << pi[i];
		if (i == pi.size() - 1) {
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}
}

void instancja::wypiszWyniki(vector<long> pi) {

	vector<zadanie> posortowana_lista;
	vector<long> czas_S; //moment rozpoczenia
	vector<long> czas_C; //moment zakonczenia
	vector<long> czas_T; //opoznienie
	vector<long> czas_WT; //opoznienie razy waga
	long t_pom; //zmienna pomocnicza
	long ocena = 0; //wazona suma opoznien

	for (int i = 0; i < ilosc_zadan; i++) {
		posortowana_lista.push_back(lista_zadan[pi[i] - 1]); //posrtowanie listy zadan wedlug PI
	}

	for (int i = 0; i < ilosc_zadan; i++) {

		if (i == 0) { //Ustawienie czasu S dla pierwszego zadania
			czas_S.push_back(0);
		}
		else { //Ustawienie czasu S dla pozostalych zadan
			czas_S.push_back(czas_C[i - 1]);
		}

		czas_C.push_back(czas_S[i] + posortowana_lista[i].p); //Ustawienie czasu C

		t_pom = czas_C[i] - posortowana_lista[i].d; //Obliczenie opoznienia
		if (t_pom < 0) { //Jezeli zadania wykonano przed czasem to opoznienie wynosi 0
			t_pom = 0;
		}

		czas_T.push_back(t_pom); //Ustawienie czasu T
		czas_WT.push_back(t_pom * posortowana_lista[i].w); // Ustawienie czasu wT		
		ocena += czas_WT[i]; //Dodanie do oceny czasu wT
	}

	cout << endl << "S: [";
	for (int i = 0; i < ilosc_zadan; i++) {
		cout << czas_S[i];
		if (i == ilosc_zadan - 1) { //Jesli ostatni element
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}

	cout << endl << "C: [";
	for (int i = 0; i < ilosc_zadan; i++) {
		cout << czas_C[i];
		if (i == ilosc_zadan - 1) { //Jesli ostatni element
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}

	cout << endl << "T: [";
	for (int i = 0; i < ilosc_zadan; i++) {
		cout << czas_T[i];
		if (i == ilosc_zadan - 1) { //Jesli ostatni element
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}

	cout << endl << "wT: [";
	for (int i = 0; i < ilosc_zadan; i++) {
		cout << czas_WT[i];
		if (i == ilosc_zadan - 1) { //Jesli ostatni element
			cout << "]";
		}
		else {
			cout << ", ";
		}
	}

	cout << endl << "Ocena opoznien: " << ocena << endl;
}

long instancja::funkcjaOceny(vector<long> pi) {

	vector<zadanie> posortowana_lista;
	long czas_C = 0; //moment zakonczenia
	long t_pom; //zmienna pomocnicza
	long ocena = 0; //wazona suma opoznien

	for (int i = 0; i < ilosc_zadan; i++) {
		posortowana_lista.push_back(lista_zadan[pi[i] - 1]); //posrtowanie listy zadan wedlug PI
	}

	for (int i = 0; i < ilosc_zadan; i++) {

		czas_C += posortowana_lista[i].p; //Obliczenie czasu C		
		t_pom = czas_C - posortowana_lista[i].d; //Obliczenie opoznienia

		if (t_pom > 0) //Jezeli jest opoznienie
			ocena += t_pom * posortowana_lista[i].w; //Dodanie opoznienia do oceny
	}

	return ocena;
}

vector<long> instancja::zachlanna() {

	vector<zadanie> pomocnicza_lista; //Kopisa listy zadan
	vector<long> pi_posortowanej_listy; //PI dla listy posortowanej wedlug deadlinow (od najmniejszych do najwiekszych)

	for (int i = 0; i < ilosc_zadan; i++) { //Skopiowanie listy zadan
		pomocnicza_lista.push_back(lista_zadan[i]);
	}

	int liczba_elementow = ilosc_zadan; //Sortowanie babelkowe

	while (liczba_elementow > 1) {

		for (int i = 0; i < liczba_elementow - 1; i++) {
			if (pomocnicza_lista[i].d > pomocnicza_lista[i + 1].d) {
				swap(pomocnicza_lista[i], pomocnicza_lista[i + 1]);
			}
		}

		liczba_elementow--;
	}

	for (int i = 0; i < ilosc_zadan; i++) { //Zapisywanie PI posortowanej listy
		pi_posortowanej_listy.push_back(pomocnicza_lista[i].j);
	}

	return pi_posortowanej_listy;
}

vector<long> instancja::przeglad() {

	vector<long> pi = domyslnePi(); //Inicjalizacja permutacji PI, domyslnym PI
	vector<long> optymalne_pi; //Optymalna kolejnosc PI
	long ocena = 2147483647; //Inicjalizacja oceny maksymalna wartoscia longa
	long ocena_pom; //Zmienna pomocniacza

	do {
		ocena_pom = funkcjaOceny(pi);
		if (ocena_pom < ocena) {
			ocena = ocena_pom;
			optymalne_pi = pi;
		}
	} while (next_permutation(pi.begin(), pi.end()) && ocena > 0);

	return optymalne_pi;
}