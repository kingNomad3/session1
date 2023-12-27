/*
* Auteur		: Benjamin Joinvil
	Description	:
	Input		:
	Output		:
	Version		: 1.0

*/

#include <iostream>  // pour le cout et le cin
#include <conio.h>   // pour le _getch()
#include <iomanip>	 // pour les manipulateurs : fixed , setprecision()
#include <string> // pour le type 
#include <iomanip>
#include "../cvm 21.h"

using namespace std;

int main() {
	// variable
	char deviseInitiale;
	char deviseConversion;
	double montantInitial;
	double montantConverti;
	double montantCanadien;

	//constante
	const double DOLLAR = 1.31674;
	const double EURO = 1.31357;
	const double BAHT = 0.03597;
	const double ROUPIE = 0.01657;
	const double COURONNE = 0.17666;
	const int MARGE = 5;
	const int C1 = MARGE + 0, C2 = 4, C3 = 0, C4 = 25, C5 = 30;

	//convsetion 
	//montantCanadien = montantInitial * deviseConversion;
	//montantConverti = montantCanadien / deviseConversion;

	//input 

	cout << "Entrez le montant \x85 convertir :";
	cin >> montantInitial;
	cout << "\nEntrez la devise de ce montant :\n\n";


	cout << setw(C1) << "$" << setw(C2) << "-> " << setw(C3) << "Dollar" << setw(18) << "(Canada)\n";
	cout << setw(C1) << "D" << setw(C2) << "-> " << setw(C3) << "Dollar" << setw(21) << "(\220tas-unis)\n";
	cout << setw(C1) << "E" << setw(C2) << "-> " << setw(C3) << "Euro" << setw(29) << "(Union Europ\x82nne)\n";
	cout << setw(C1) << "B" << setw(C2) << "-> " << setw(C3) << "Baht" << setw(22) << "(Tha\x8bland)\n";
	cout << setw(C1) << "R" << setw(C2) << "-> " << setw(C3) << "Roupie" << setw(16) << "(Inde)\n";
	cout << setw(C1) << "C" << setw(C2) << "-> " << setw(C3) << "Couronne" << setw(17) << "(Danemark)" << setw(C5) << "Votre choix : ";
	deviseInitiale = _getch();
	deviseInitiale = toupper(deviseInitiale);
	cout << deviseInitiale;
	

	cout << "\n\n" << "Entrez la devise dans laquelle on fera la conversion :\n\n";
	cout << setw(C1) << "$" << setw(C2) << "-> " << setw(C3) << "Dollar" << setw(18) << "(Canada)\n";
	cout << setw(C1) << "D" << setw(C2) << "-> " << setw(C3) << "Dollar" << setw(21) << "(\220tas-unis)\n";
	cout << setw(C1) << "E" << setw(C2) << "-> " << setw(C3) << "Euro" << setw(29) << "(Union Europ\x82nne)\n";
	cout << setw(C1) << "B" << setw(C2) << "-> " << setw(C3) << "Baht" << setw(22) << "(Tha\x8bland)\n";
	cout << setw(C1) << "R" << setw(C2) << "-> " << setw(C3) << "Roupie" << setw(16) << "(Inde)\n";
	cout << setw(C1) << "C" << setw(C2) << "-> " << setw(C3) << "Couronne" << setw(17) << "(Danemark)" << setw(C5) << "Votre choix : ";
	deviseConversion = _getch();
	deviseConversion = toupper(deviseConversion);
	cout << deviseConversion;


	if (deviseInitiale == 'D') {
		montantCanadien = montantInitial * DOLLAR;

	}
	else if (deviseInitiale == 'E') {
		montantCanadien = montantInitial * EURO;

	}
	else if (deviseInitiale == 'B') {
		montantCanadien = montantInitial * BAHT;

	}
	else if (deviseInitiale == 'R') {
		montantCanadien = montantInitial * ROUPIE;

	}
	else if (deviseInitiale == 'C') {
		montantCanadien = montantInitial * COURONNE;

	}
	else {
		montantCanadien = montantInitial;
		deviseInitiale = '$';
	}



	if (deviseConversion == 'D') {
		montantConverti = montantCanadien / DOLLAR;

	}
	else if (deviseConversion == 'E') {
		montantConverti = montantCanadien / EURO;

	}
	else if (deviseConversion == 'B') {
		montantConverti = montantCanadien / BAHT;

	}
	else if (deviseConversion == 'R') {
		montantConverti = montantCanadien / ROUPIE;

	}
	else if (deviseConversion == 'C') {
		montantConverti = montantCanadien / COURONNE;

	}
	else {
		montantConverti = montantCanadien;
		deviseConversion = '$';
		}


	cout << fixed;
	cout << "\n\nMontant initial  :" << setw(15) << setprecision(2) << montantInitial << setw(5) << deviseInitiale;
	cout << "\n\nMontant converti :" << setw(15) << setprecision(2) << montantConverti << setw(5) << deviseConversion;

	_getch();
}