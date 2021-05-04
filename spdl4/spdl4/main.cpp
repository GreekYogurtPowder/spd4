#include <cstdio>
#include <ctime>
#include <windows.h>
#include "instancja.h"
using namespace std;

int main()
{
	clock_t start, stop;
	vector<long> pi;
	instancja inst = instancja();

	cout << endl << "-----ZADANIA-----" << endl;
	inst.wypiszTabele();

	cout << endl << endl << "-----PERMUTACJA NATURALNA-----" << endl;
	inst.wypiszPi(inst.domyslnePi());
	inst.wypiszWyniki(inst.domyslnePi());

	cout << endl << "-----METODA ZACHLANNA-----" << endl;
	start = clock();
	pi = inst.zachlanna();
	stop = clock();
	inst.wypiszPi(pi);
	inst.wypiszWyniki(pi);
	cout << "Czas dzialania: " << (stop - start) / 1000.0 << " s" << endl;

	cout << endl << "-----PRZEGLAD ZUPELNY-----" << endl;
	start = clock();
	pi = inst.przeglad();
	stop = clock();
	inst.wypiszPi(pi);
	inst.wypiszWyniki(pi);
	cout << "Czas dzialania: " << (stop - start) / 1000.0 << " s" << endl;

	cout << endl << endl;
	return 0;
}