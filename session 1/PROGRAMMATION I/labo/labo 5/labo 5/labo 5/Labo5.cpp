#include <iostream>  // pour le cout et le cin
#include <conio.h>   // pour le _getch()
#include <iomanip>	 // pour les manipulateurs : fixed , setprecision()
#include <string> // pour le type 
#include <iomanip>
#include "../cvm 21.h"


using namespace std;

int main() {

	//variable 

	//étape 1
	char formatPapier = ' ';
	char typeImpression = ' ';
	int nbOri = 0;
	int nbExe = 0;
	int nbImpR = 0;
	int nbImpRV = 0;
	int reste = 0 ;

	//etape 2
	double coutR = 0;
	double coutRV = 0;

	//etape 3
	char typePapier = 0;
	double coutPapier = 0;

	//etape 4
	char aPerforer = 0;
	char typeFaconnage = 0 ;
	double coutFaconnage = 0;
	double coutPerforage = 0;
	double PerforerEtFaconnage = 0;

	//etape 5
	double coutProduction = 0;
	double coutTotal = 0;

	//constante

	//etape 2
	const double PRIX_8x11R = 31.0;
	const double PRIX_8x11RV = 60.0;
	const double PRIX_11x17R = 61.0;
	const double PRIX_11x17RV = 100.0;

	//etape 3
	const double PRIX_PAPIER_1 = 20.5;
	const double PRIX_PAPIER_2 = 67.34;
	const double PRIX_PAPIER_3 = 122.94;

	//etape 4
	const double PRIX_BROCHE = 0.03;
	const double PRIX_ENCOLLER = 0.6;
	const double PRIX_TABLETTE = 0.35;
	const double PRIX_DOSCHEVAL = 0.10;
	const double PRIX_PERFORER = 3;

	//etape 5
	const double TPS = 0.05;
	const double TVQ = 0.09975;


	//affichage         // rajouter les getch et les toupper
	cout << "Nombre d'originaux                     :";
	cin >> nbOri;

	cout << "nombre d'exemplaires \x85 reporoduire     :"; 
	cin >> nbExe;

	cout << "\nFormat du papier :" << "\n\t1. 8\xabx11" << "\n\t2. 8\xabx14" << "\n\t3. 11x17" << setw(40) << "Votre choix :" ;
	formatPapier = _getch();
	cout << formatPapier << endl;

	cout << "\ntype d'impression :" << "\n\tR. recto" << "\n\tV. recto - verso" << setw(32) << "votre choix :" ;
	typeImpression = _getch();
	typeImpression = toupper(typeImpression);
	cout << typeImpression << endl;
	
	cout << "\nType de papier :" << "\n\t1. Repro + gris" << "\n\t2. Rolland \x82volution glacier" << "\n\t3. Wausau royal, fibre texte \x82tain"<<setw(14) << "Votre choix :";  
	typePapier = _getch();
	cout << typePapier << endl;

	cout << "\nVoulez-vous des documets perfor\x82s ? (O/N)" << setw(15) << "Votre choix :" ;
	aPerforer = _getch();
	aPerforer = toupper(aPerforer);
	cout << aPerforer << endl;

	cout << "\nType de fa\x87onnage :" << "\n\t1. Broche en coin" << "\n\t2. Encoller avec ruban" << "\n\t3. Tablettes" << "\n\t4. Broche a dos de cheval"  << "\n\t5. Aucun" << setw(37) << "\tVotre choix :" ; //c et a
	typeFaconnage = _getch();
	cout << typeFaconnage << endl;

	cout << "\n\nApppuyez sur une touche pour continuer ...";
	_getch();


	// Étape 1 : calcul du nombre de feuilles à imprimer (recto et recto-verso) 
	if (typeImpression == 'R') {
		switch (formatPapier){
		case '1':
			nbImpR = nbOri * nbExe;
			nbImpRV = 0;
			break;

		case '2':
			nbImpR = nbOri * nbExe;
			nbImpRV = 0;
			break;

		case '3':
			if (nbOri % 2 != 0) {
				nbOri = nbOri + 1;
				nbImpR = nbOri * nbExe / 2;
				nbImpRV = 0;
			}else{
				nbImpR = nbOri * nbExe / 2;
				nbImpRV = 0;				
			}
		break;
		}

	}else if (typeImpression == 'V'){
		switch (formatPapier){
		case'1':
			if (nbOri % 2 != 0) {
				nbImpR = nbExe;
				nbImpRV = (nbOri - 1) * nbExe / 2;
			}else{
				nbImpR = 0;
				nbImpRV = nbOri * nbExe / 2;
			}
			break;

		case'2':
			if (nbOri % 2 != 0) {
				nbImpR = nbExe;
				nbImpRV = (nbOri - 1) * nbExe / 2;
			}else {
				nbImpR = 0;
				nbImpRV = nbOri * nbExe / 2;
			}
			break;

		case '3':
			reste = nbOri % 4;

			if (reste == 0) {
				nbImpR = 0;
				nbImpRV = nbOri * nbExe / 4;
			}else if (reste == 1 || reste == 2) {
				nbImpR = nbExe;
				nbImpRV = (nbOri - reste) * nbExe / 4;
			}else if (reste == 3) {
				nbImpR = 0;
				nbImpRV = (nbOri + 1) * nbExe / 4;
			}
		}
	}else{
		nbImpR = nbOri * nbExe;
	}

	//Étape 2 : calcul des coûts de main-d'œuvre de l'impression (recto et recto-verso) 
	switch (typeImpression) {

	case 'R':
		if (formatPapier == '1' || formatPapier == '2') {
			coutR = nbImpR  * PRIX_8x11R /1000;

		}else{
			coutR = nbImpR * PRIX_11x17R /1000;
		}
		break;

	case 'V':
		if (formatPapier == '1' || formatPapier == '2') {
			coutRV = nbImpRV * PRIX_8x11RV /1000;
			coutR = nbImpR * PRIX_8x11R / 1000;
		}else{
			coutRV = nbImpRV * PRIX_11x17RV /1000;
			coutR = nbImpR * PRIX_11x17R / 1000;
			break;
		}
	default:
		if (formatPapier == '1' || formatPapier == '2') {
			coutR = nbImpR * PRIX_8x11R / 1000;

		}else{
			coutR = nbImpR * PRIX_11x17R / 1000;
		}
		break;


	}
	// Étape 3 : calcul des coûts du papier 
	switch (typePapier) {

	case '1':

		if (formatPapier == '1') {
			coutPapier = ((nbImpR + nbImpRV) * PRIX_PAPIER_1 / 1000)/2;

		}else if (formatPapier == '2' || formatPapier == '3') {
			coutPapier = ((nbImpR + nbImpRV) * PRIX_PAPIER_1) / 1000;
		}
		break;

	case '2':

		if (formatPapier == '1') {
			coutPapier = ((nbImpR + nbImpRV) * PRIX_PAPIER_1 / 1000) /2;

		}else if (formatPapier == '2' || formatPapier == '3') {
			coutPapier = (nbImpR + nbImpRV) * PRIX_PAPIER_2 / 1000;
		}
		break;

	case '3':

		if (formatPapier == '1') {
			coutPapier = ((nbImpR + nbImpRV) * PRIX_PAPIER_1 /1000)/2;

		}else if (formatPapier == '2' || formatPapier == '3'){
			coutPapier = (nbImpR + nbImpRV) * PRIX_PAPIER_3/1000;
			}
		break;
	}
	// Étape 4 : Calculer les coûts du façonnage et de la perforation 

switch (aPerforer){

	case 'O':
		coutPerforage = (nbImpR + nbImpRV) * PRIX_PERFORER/1000;
		break;

	case 'N':
		coutPerforage = 0;
		break;
	}

	switch (typeFaconnage) {

	case '1':
		coutFaconnage = nbExe * PRIX_BROCHE;
		break;

	case '2':
		if (formatPapier == '1'|| formatPapier == '2') {
			coutFaconnage = nbExe * PRIX_ENCOLLER;
		}else{
			coutFaconnage = 0;
		}
		break;

	case '3':
		coutFaconnage = nbExe * PRIX_TABLETTE;
		break;

	case '4':
		if (formatPapier == '3') {
			coutFaconnage = nbExe * PRIX_DOSCHEVAL;
		}
		break;

	default :
			coutFaconnage = 0;
			break;
	}

	// Étape 5 : Calculer le coût total 

	coutProduction = coutR + coutRV + coutPapier + coutFaconnage + coutPerforage;
	PerforerEtFaconnage= coutFaconnage + coutPerforage;
	double tps = coutProduction * TPS;
	double tvq = coutProduction * TVQ;
	coutTotal = coutProduction + tps + tvq;

	// Affichage des résultats 
	clrscr();

	cout << fixed;
	cout << "\n\n\nFACTURE" << endl;
	cout <<"\n\n" << setw(29) << "Co\x96t des impression recto :" << setw(19) << fixed << setprecision(2) << coutR << setw(2) << "$" << endl;
	cout << setw(35) << "Co\x96t des impression recto-verso :" << setw(13) << fixed  << setprecision(2) << coutRV << setw(2) << "$" << endl;
	cout << "\n" << setw(18) << "Co\x96t du papier :" << setw(30) << fixed << setprecision(2) << coutPapier << setw(2) << "$" << endl;
	cout << setw(21.5) << "Co\x96t du faconnage :" << setw(27) << fixed  << setprecision(2) << PerforerEtFaconnage << setw(2) << "$" << endl;
	cout << setw(50) << "---------------------" << endl;
	cout << "\n" << setw(22.5) << "Co\x96t de production :" << setw(26) << fixed << setprecision(2) << coutProduction << setw(2) << "$" << endl;
	cout << setw(50) << "======================" << endl;
	cout << "Co\x96t total" << setw(38) << setprecision(2) << coutTotal << setw(2) << " $" << endl;
}
