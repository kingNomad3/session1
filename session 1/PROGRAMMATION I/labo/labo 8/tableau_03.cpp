#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;


// CONSTANTE DIMENSIONN�E (IDEM QUE VARIABLE DIMENSIONN�E)

int main()
{
	// EXEMPLE #1 -- D�finition du tableau constant "planets" (une s�rie) de 8 string

	const int N = 8;
	
	const string planets[N] = { "Mercure", "Venus", "Terre", "Mars", "Jupiter", "Saturne", "Uranus", "Neptune" };


	// D�finition des lunes associ�s

	const int moons[N] = { 0, 0, 1, 2, 79, 82, 27, 14 };


	// EXEMPLE #2 -- Afficher toutes les plan�tes

	for (int i = 0; i < N; ++i)
		cout << planets[i] << endl;

	cout << endl;


	// EXEMPLE #3 -- Afficher la troisi�me plan�te et son nombre de lunes:     Attention avec les indices !!!

	int planetNo = 3; // la Terre

	cout << planets[planetNo - 1] << " #" << planetNo << " ==> " << moons[planetNo - 1] << " lune(s)" << endl << endl;


	// EXEMPLE #4 -- Rechercher si une valeur existe dans le tableau planets

	int i;
	bool trouv�;
	string valeur;

	valeur = "Terre";

	trouv� = false;
	for (i = 0; i < N; ++i)
		if (planets[i] == valeur)
		{
			trouv� = true;
			break;
		}
	
	if (trouv�)
		cout << valeur << " existe ! -- indice: " << i << endl;
	else
		cout << valeur << " n'existe pas !" << endl;

	_getch();
}