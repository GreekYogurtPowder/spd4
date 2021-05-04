#ifndef INSTANCJA_H
#define INSTANCJA_H

#include "zadanie.h"
#include "RandomNumberGenerator.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class instancja
{
public:
	vector<zadanie> lista_zadan;
	long ilosc_zadan;

	instancja();
	void wypiszTabele();

	vector<long> domyslnePi();
	void wypiszPi(vector<long> pi);
	void wypiszWyniki(vector<long> pi);
	long funkcjaOceny(vector<long> pi);
	vector<long> zachlanna();
	vector<long> przeglad();
	vector<long> dynamiczne();
};

#endif