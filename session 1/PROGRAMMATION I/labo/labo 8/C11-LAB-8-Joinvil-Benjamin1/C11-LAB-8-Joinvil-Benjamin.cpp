#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <string>
#include "../cvm 21.h"

using namespace std;

int main() {
	bool valide;
	int jju, mm, aaaa, jourSemaine, jj;
	int x3 = 2;
	int y3 = 1;
	long nbTotatlJoursEcoule = 0;
	int limiteMax = 2099;
	int limitMin = 1901;
	int moisMin = 1;
	int moisMax = 12;
	int jourMax = 31;
	int jourMin = 1;
	string sep = "/";
	string sep1 = "-";

	size_t x = 5;
	size_t y = 1;
	string mois;
	char voirCalendrier;


	char barre = ' ';

	const int J = 7;
	const int M = 12;
	//const size_t X = 10, Y = 5;
	const int NB_JOURS_MOIS[M] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	const string jourDeLaSemaine[J] = { "Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi" };
	const string jourDeLaSemaine2[J] = { "Di", "Lu", "Ma", "Me", "Je", "Ve", "Sa" };
	const string MoisDeLannee[M] = { "janvier","février","mars","avril","mai","juin","juillet","août","septembre","octobre","novembre","décembre" };
	const string messageDebut = "Entrez une date (JJ/MM/AAAA) : ";
	const string MESSAGE_ERREUR = "ERREUR: Vous devez entrer un op\x82rateur valide ! (- , / )";
	const string ERREUR_JOUR = "Le jour est erroné(doit être entre 1 et 31 inclusivement)";
	const string ERREUR_MOIS = " Le mois est erroné (doit être entre 1 et 12 inclusivement)";
	const string ERREUR_ANNEE = " L'annee est erroné (doit être entre 1 et 12 inclusivement)";
	const string QVoirCalendrier = "Voulez-vous voir le calendrier complet du mois (O/N) ?";
	const string erreur = "ERREUR: Vous devez entrer seulement des nombres !";
	valide = false;
	do {



		// vider le tampon du cin

		cin.ignore(cin.rdbuf()->in_avail());

		cout << messageDebut;
		cin >> jju >> barre >> mm >> barre >> aaaa;
		clrscr();
		if (jju > jourMax || jju < jourMin) {
			cout << ERREUR_JOUR;

			valide = false;
		}
		else if (mm > moisMax || mm < moisMin) {
			cout << ERREUR_MOIS;
			valide = false;

		}
		else if (aaaa > limiteMax || aaaa < limitMin) {
			cout << ERREUR_ANNEE;

			valide = false;
		}
		else {
			valide = true;
		}

		if (cin.fail()) { // vérifier d'abord si le "cin" n'a pas été en mesure de lire l'expression.
			cout << erreur << endl;

			cin.clear(); // obligatoire de remettre le cin en état de marche car fail()
		}
		else if (barre != '/' && barre != '-') { // opérateur non admissible

			cout << MESSAGE_ERREUR;
			clrscr();

		}
		else {
			valide = true;
		}
		if (!valide)
		{
			// cout << MESSAGE_ERREUR << " ... "; _getch();
			clrscr();
		}




		//if (cin.fail()) {}
		if (valide == true) {
			if (mm == 2) {
				if (aaaa % 400 == 0 || (aaaa % 4 == 0 && aaaa % 100 != 0))
					jj = 29;
				else
					jj = 28;
			}
			else if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) {
				jj = 31;

			}
			else {
				jj = 30;
			}




			for (int i = 0; i < mm - 1; i++) {

				nbTotatlJoursEcoule += NB_JOURS_MOIS[i];

			}

			nbTotatlJoursEcoule += jju;
			jourSemaine = (nbTotatlJoursEcoule + (aaaa - 1900) + (aaaa - 1901) / 4) % 7 + 1;



			cout << "Le" << jju << barre << mm << barre << aaaa << " est un :";
			for (int a = 1; a <= jourSemaine; a++) {

				if (a == jourSemaine) {
					cout << jourDeLaSemaine[a - 1];
				}
			}
			cout << "\n" << QVoirCalendrier;
			cin >> voirCalendrier;
			clrscr();

			if (voirCalendrier = 'O') {

				//MoisDeLannee[M] = mois;
				//nbTotatlJoursEcoule = jj;

				gotoxy(x += 35, y);

				for (int m = 0; m <= mm; m++)
				{
					if (m == mm)
						cout << MoisDeLannee[m - 1];
				}




				int x2 = 5;
				int y2 = 2;
				gotoxy(x2, y2);
				for (int s = 0; s <= 6; s++) {
					//cout << mois << endl;

					gotoxy(x2 += 10, y2);
					cout << jourDeLaSemaine2[s];
				}

				int x = 15;

				//cout << fixed << endl;
				gotoxy(x, y + 2);
				cout << "---------------------------------------------------------------" << endl;



				//nbTotatlJoursEcoule -= jju;
				//nbTotatlJoursEcoule++;
				int x3 = 5;
				int y3 = 4;


				if (jourSemaine == 1) {
					int x3 = 5;
					int y3 = 4;

					for (int j = 1; j <= jj; ++j)
					{

						gotoxy(x3 += (10), y3);
						cout << j;


						if (x3 == 75) {
							x3 = 5;
							y3 += 2;
						}

					}

					cout << endl;
				}

				else if (jourSemaine == 2) {

					int x3 = 15;
					int y3 = 4;

					for (int j = 1; j <= jj; ++j)
					{

						gotoxy(x3 += (10), y3);
						cout << j;


						if (x3 == 75) {
							x3 = 5;
							y3 += 2;
						}

					}

					cout << endl;
				}
				else if (jourSemaine == 3) {

					int x3 = 25;
					int y3 = 4;

					for (int j = 1; j <= jj; ++j)
					{

						gotoxy(x3 += (10), y3);
						cout << j;


						if (x3 == 75) {
							x3 = 5;
							y3 += 2;
						}

					}

					cout << endl;

				}
				else if (jourSemaine == 4) {


					int x3 = 35;
					int y3 = 4;

					for (int j = 1; j <= jj; ++j)
					{

						gotoxy(x3 += (10), y3);
						cout << j;


						if (x3 == 75) {
							x3 = 5;
							y3 += 2;
						}

					}

					cout << endl;
				}
				else if (jourSemaine == 5) {
					int x3 = 45;
					int y3 = 4;

					for (int j = 1; j <= jj; ++j)
					{

						gotoxy(x3 += (10), y3);
						cout << j;


						if (x3 == 75) {
							x3 = 5;
							y3 += 2;
						}

					}

					cout << endl;
				}

				else if (jourSemaine == 6) {
					int x3 = 55;
					int y3 = 4;

					for (int j = 1; j <= jj; ++j)
					{

						gotoxy(x3 += (10), y3);
						cout << j;


						if (x3 == 75) {
							x3 = 5;
							y3 += 2;
						}

					}

					cout << endl;
				}

				else if (jourSemaine == 7) {
					int x3 = 65;
					int y3 = 4;

					for (int j = 1; j <= jj; ++j)
					{

						gotoxy(x3 += (10), y3);
						cout << j;


						if (x3 == 75) {
							x3 = 5;
							y3 += 2;
						}

					}

					cout << endl;
				}


			}
			else if (voirCalendrier = 'N') {
				valide == false;
			}

		}

		//	_getch();

	} while (valide);

}