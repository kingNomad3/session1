#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

/*

VARIABLE DIMENSIONN�E: ( autres noms: "un Tableau", ou en anglais: "Array" )


	A) D�FINITION: Il est possible de d�finir, en une seule instruction, une serie de N variables du m�me type.

		- Syntaxe de la d�finition:
	
			type nom [ N ] ;		// d�finition d'une variable dimentionn�e


		- le "nom" est celui de la variable dimensionn�e

		- N est la dimension (ou la taille) de la s�rie et doit �tre un entier positif ( >= 1 )
	
		- la valeur de N doit �tre connu � la compilation (versus connu � l'ex�cution), il s'agit donc d'une constante enti�re.


	B) ACC�S: Pour acc�der � une des variables de la s�rie, il faut utiliser un indice
		
		- la premi�re variable de la s�rie est � l'indice : 0

		- le derni�re variable de la s�rie est � l'indice : N-1


		- Syntaxe d'acc�s:

			nom [ 0 ] ;				// acc�s � la premi�re variable de la s�rie

			nom [ 1 ] ;				// acc�s � la deuxi�me variable de la s�rie

			nom [ i ] ;				// acc�s � la variable en indice i

			nom [ N-1 ] ;			// acc�s � la derni�re variable de la s�rie

			nom [ expression ] ;	// la valeur de l'expression doit absolument �tre un entier entre [ 0 .. N-1 ]



		- l'indice peut �tre vu comme un d�placement (un delta) � partir du d�but de la s�rie de variables

			s�rie de 10 variables:	[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]		// ici N = 10  ==>  10 x [case]
						   indice:	 0  1  2  3  4  5  6  7  8  9

*/


// Pour la suite, le terme Tableau est utilis�

int main()
{
	// EXEMPLE #1 -- D�finition du tableau "nombres" (une s�rie) de 3 entiers

	// D�finition
	int nombres[3];		// 3 est la taille du tableau


	// Affectation d'une valeur � chaque indice du tableau
	nombres[0] = 10;	// � l'indice 0
	nombres[1] = 15;	// � l'indice 1
	nombres[2] = 20;	// � l'indice 2

	// note 1: les indices d�bute � 0 jusqu'� (taille-1)
	// note 2: l'indice doit absolument �tre valide sinon une erreur grave se produira � l'ex�cution
	// note 3: l'indice n'est pas v�rifi� � la compilation

	// EXEMPLE #2 -- Afficher les 3 �l�ments du tableau "nombres"

	cout
		<< nombres[0] << endl
		<< nombres[1] << endl
		<< nombres[2] << endl;


	// EXEMPLE #3 --  Afficher les 3 �l�ments du tableau "nombres" en bloucle !!!

	for (int i = 0; i < 3; ++i)
		cout << nombres[i] << endl;


	// EXEMPLE #4 -- Augmenter de 100 chaque �l�ment du tableau

	for (int i = 0; i < 3; ++i)		// i pour indice
		nombres[i] = nombres[i] + 100;


	// EXEMPLE #5 -- Tripler chaque �l�ment du tableau en utilisant une bloucle

	for (int i = 0; i < 3; ++i)		// i pour indice
		nombres[i] *= 3;


	// EXEMPLE #6 -- R�initialiser tous les �l�ments du tableau � z�ro

	for (int i = 0; i < 3; ++i)
		nombres[i] = 0;


	// EXEMPLE #7 -- Incr�menter tous les �l�ments du tableau de 1

	for (int i = 0; i < 3; ++i)
	{
		nombres[i]++;

		// alternatives syntaxiques:

		//  ++nombres[i];

		//  nombres[i] += 1;

		//  nombres[i] = nombres[i] + 1;
	}

	_getch();
}