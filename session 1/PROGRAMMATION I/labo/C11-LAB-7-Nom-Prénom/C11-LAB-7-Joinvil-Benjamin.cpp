#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <string>
#include "../cvm 21.h"

using namespace std;

int main() {
	//varible
	string code;
	string codeConfirmation;
	size_t x, y;
	string c;
	string motDePasseFin;
	int boucleMdp;
	

	//constante
	const string Titre = " Entrez votre mot de passe (4 caract\x8are) :";
	const string confirmation = "taper votre mot de passe encore une fois :";
	const string Recommencer = " Recommencez, vous devez entrer le même mot deux fois :";
	const string barreoblique = "//////////////////////////";
	const string ecranV = "/      \220CRAN VEROUILL\x90   /";
	const string MOT_DE_PASSE_FIN = "mot de passe :";
	const string XS = "XXXX";
	const size_t X = 120, Y = 30;
	const string  MOT_FIN = "Mot de passe :";
	const int MAX_MDP = 3;


	


	do {

		x = (X - Titre.size()) / 2;
		y = Y / 2;
		gotoxy(x, y);
		cout << Titre;
		gotoxy(x + 20, y + 1);
		cout << XS;
		gotoxy(x + 20, y + 1);

			for (int boucleMdp= 0; boucleMdp <= MAX_MDP; ++boucleMdp)
			{	
					c = _getch();
					gotoxy(x + 20 + boucleMdp, y + 1);
					cout << "*";
			}
			code = code + c;
			clrscr();
		
		//deuxieme message pour confirmer 
		gotoxy(x, y);
		cout << confirmation << endl;
		gotoxy(x + 20, y + 1);
		cout << XS;
		gotoxy(x + 20, y + 1);
		for (int boucleMdp = 0; boucleMdp <= MAX_MDP; ++boucleMdp)
		{
			c = _getch();
			gotoxy(x + 20 + boucleMdp, y + 1);
			cout << "*";
		}
		codeConfirmation = codeConfirmation + c;
		clrscr();

		
		//suite de l'eurreur de mot de passe 
		if (code != codeConfirmation) {
			do {
				gotoxy(x, y);
				cout << Recommencer << endl;
				gotoxy(x + 20, y + 1);
				cout << XS;
				gotoxy(x + 20, y + 1);
				for (int boucleMdp = 0; boucleMdp <= MAX_MDP; ++boucleMdp)
				{
					code = "";
					c = _getch();
					gotoxy(x + 20 + boucleMdp, y + 1);
					cout << "*";
				}		

				clrscr();

				gotoxy(x, y);
				cout << confirmation << endl;
				gotoxy(x + 20, y + 1);
				cout << XS;
				gotoxy(x + 20, y + 1);
				for (int boucleMdp = 0; boucleMdp <= MAX_MDP; ++boucleMdp)
				{
					codeConfirmation = "";
					c = _getch();
					gotoxy(x + 20 + boucleMdp, y + 1);
					cout << "*";
				}

				clrscr();


			} while (code != codeConfirmation);

		}

		//ecran de veille
		while (!_kbhit()) {
				x = rand() % (200 - ecranV.size());
				y = rand() % 30;
				gotoxy(x, y);

				gotoxy(x + 20, y );
				cout << barreoblique << endl;
				gotoxy(x + 20, y + 1);
				cout << ecranV << endl;
				gotoxy(x + 20, y + 2);
				cout << barreoblique << endl;

				Sleep(1000);
				
				clrscr();
		} 

			 clrscr();
			 while (_kbhit())
				 _getch();

		//fin
			 x = (X - MOT_DE_PASSE_FIN.size()) / 2;
			 y = Y / 2;
			 gotoxy(x, y);
			 cout << MOT_DE_PASSE_FIN << endl;
			 gotoxy(x + 5, y + 1);
			 cout << XS;
			 gotoxy(x + 5, y + 1);
			 c = _getch();
			 gotoxy(x + 5 , y + 1);
			 cout << "*";
			 
				 do {
					 x = (X - MOT_DE_PASSE_FIN.size()) / 2;
					 y = Y / 2;

					 gotoxy(x, y);
					 cout << MOT_DE_PASSE_FIN << endl;
					 gotoxy(x + 5, y + 1);
					 cout << XS;
					 gotoxy(x + 5, y + 1);
				
					 for (int boucleMdp = 0; boucleMdp <= MAX_MDP; ++boucleMdp)
					 {
						 motDePasseFin = "";
						 c = _getch();
						 gotoxy(x + 5 + boucleMdp, y + 1);
						 cout << "*";
						 motDePasseFin = motDePasseFin + c;
					 }
					
					
				 }while (code != motDePasseFin);
			
				gotoxy(x, y);
				cout << MOT_DE_PASSE_FIN << endl;
				gotoxy(x + 5, y + 1);
				cout << "*" << endl;
				gotoxy(x + 2, y + 2);
				cout << "AU REVOIR" << endl;

		     
	} while (code != codeConfirmation);0
}







