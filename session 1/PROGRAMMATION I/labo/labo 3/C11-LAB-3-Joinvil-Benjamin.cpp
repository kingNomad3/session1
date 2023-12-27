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

	//variable
	unsigned int nbKwHres = 0;
	unsigned int nbJour = 0;
	double redevance = 0;
	double totalFacture = 0;
	string prenom = "";
	string nom = "";
	double tps = 0;
	double tvq = 0;

	double prix_1 = 0;
	double prix_2 = 0;
	const double TARIFPARJOUR = 0.42238;
	const double TARIF_1 = 0.06319;
	const double TARIF_2 = 0.09749;
	long double NewKwh =0;
	long double restKwh =0 ;

	//constant
	double TPS = 0.05;
	double TVQ = 0.09975;

	//input
	cout << right << setw(65) << "HYRDO-QU\220BEC";
	cout << "\n\n\n\nQuel est votre pr\x82nom                    : ";
	cin >> prenom;
	cout << "\nQuel est votre nom                       : ";
	cin >> nom;
	cout << "\n\nQuelle est votre consomation en KWh      : ";
	cin >> nbKwHres;
	cout << "\nSur combien de jours                      : ";
	cin >> nbJour;
	cout << right << "\n\n\n\t\t\t Appuyez sur une touche pour continuer";
	
	_getch();
	clrscr();
	

	if (nbKwHres > (40 * nbJour)) {

		prix_1 = TARIF_1 * (40 * nbJour);
		prix_2 = TARIF_2 * (nbKwHres - (40 * nbJour));
		NewKwh = (40 * nbJour);
		restKwh = (nbKwHres - (40 * nbJour));
	}else {

		prix_1 = TARIF_1 * nbKwHres;
		prix_2 = 0;
		NewKwh = (40 * nbJour);
		restKwh = 0;
	}

	redevance = (nbJour * TARIFPARJOUR);
	tps = (prix_1 + prix_2 + redevance) * TPS;
	tvq = (prix_1 + prix_2 + redevance) * TVQ;
	totalFacture = prix_1 + prix_2 + redevance + tps + tvq;


	//output
	cout << setfill(' ');
	cout << "\n\n" << setw(3) << "FACTURE D'\x90LECTICIT\x90 DE :\t" << nom << "\t" << prenom;
	cout << "\n\n\n" << setw(6) << "REDEVANCE D'ABONNEMENT :" << setw(17) << setprecision(4) << redevance << setw(2) << "$" << "\t" << nbJour << setw(8) << "jour(s)" << setw(2) << "x" << setw(2) << setprecision(5) << TARIFPARJOUR;
	cout << "\n\n\n" << "CONSOMATION:" << setw(40) << nbKwHres << setw(4) << "kWh" << "\n";
	cout << "\n" << setw(28) << "Les 40 premiers KWhjour:" << setw(13) << prix_1 << setw(2) << "$" << "\t" << NewKwh << setw(7) << "Kwh x " << TARIF_1 << " $";
	cout << "\n\n" << setw(30) << "Le reste de la consomation" << setw(11) << setprecision(4) << prix_2 << setw(2) << "$"<< setprecision(5) << "\t" << restKwh << setw(2) << " KWh x " << TARIF_2 << " $";
	cout << "\n\n\n" << "TPS:" << setw(37) << setprecision(4) << tps << setw(2) << "$" << setw(6) << "5" << setw(2) << "%";
	cout << "\n\n" << "TVQ:" << setw(37) << setprecision(5) << tvq << setw(2) << "$" << setw(10) << "9.975" << setw(2) << "%";
	cout << "\n\n" << setw(43) << "-------------";
	cout <<"\n" << "TOTAL:" << setw(35) << totalFacture <<setw(2) << "$";

	_getch();

}