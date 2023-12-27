/*
* Auteur		: Benjamin Joinvil
	Description	: 
	Input		: 
	Output		:
	Version		: 1.0

*/
using namespace std;

#include <iostream>  // pour le cout
#include <conio.h>   // pour le _getch()
#include <string> // pour le type 
#include <iomanip>

int main() {
	//variable
	string prenom = "";
	string nom = "";
	string numeroGroupe = "";

	// constante
	char carac = '\x41';
	int entier = 75000;
	short entierCourt = -42;
	long entierLong = 57000;
	float reel = 123.456;
	double reelDouble = 12.0123456789;
	unsigned int sansSigne = 54321;
	string titre1 = "Essai du cadrage \x85 gauche et de la notation en virgule flottante:"; 
	string titre2 = "Essai du cadrage \x85 droite et de la notation scientifique:";
	string titre3 = "Essai de mise en page:";
		

	//input
	cout << "Taper votre pr\x82nom:";
		cin >> prenom;
	cout << "taper votre nom:";
		cin >> nom;
	cout << "taper votre num\x82ro de groupe:" ;
	cin >> numeroGroupe; cout << "\n";

 //output
	cout << left << titre1; "\n";
	cout << left << "\n" << setw(8) << entier << setw(7) << entierCourt << setw(8) << entierLong << setw(8) << sansSigne << setw(8) << carac;
	cout << left << "\n" << setw(8) << setprecision(5) << reel << setw(10) << setprecision(4) << reelDouble;

	cout << "\n\n";  
	cout << right << titre2; "\n";
	cout << right << "\n" << setw(12) << entier << ' ' << setw(8) << entierCourt << setw(12) << entierLong << setw(12) << sansSigne << setw(14) << carac;
	cout << right << "\n"<< setw(4) << ' ' << scientific << reel << "\t" << setw(6) << reelDouble;

	cout << "\n\n";
	cout << titre3;
	cout << "\n\t" << "entier\t\t = " << hex << entier; 
	cout << "\n\t" << "entierCourt\t = " << hex << entierCourt;
	cout << "\n\t" << "entierLong\t = " << hex << entierLong;
	cout << "\n\t" << "SansSigne\t = " << hex << sansSigne;
	cout << "\n\t" << "carac\t\t = " << carac;
	cout << "\n\t" << "reel\t\t ="<< setw(11) <<fixed << setprecision(3) << reel;
	cout << "\n\t" << "reelDouble\t =" << setw(11) << fixed << reelDouble;
		

	cout << "\n\nSalut"<<' '<< nom << ' ' << prenom << ' ' << "du groupe" << ' ' << numeroGroupe << "!";



}