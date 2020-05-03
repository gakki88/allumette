/*
 * menu.cpp
 *
 *  Created on: 25 avr. 2019
 *      Author: yuxin
 */

#include <iostream>
#include <string>
#include "menu.h"
#include "Jeu.h"
#include "Joueur.h"
#include "allumette.h"

using namespace std;

void menu::AfficherMenu() {
	cout << " ______________________" << endl;
	cout << "|                      |" << "                 /*\\" << endl;
	cout << "|  1.Nouveau Jeu       |" << "                 \\_/" << endl;
	cout << "|______________________|" << "                  $" << endl;
	cout << " ______________________" << "                   $" << endl;
	cout << "|                      |" << "                  $" << endl;
	cout << "|  2.Param¨¨tres        |" << "                  $" << endl;
	cout << "|______________________|" << "                  $" << endl;
	cout << " ______________________" << "                   $" << endl;
	cout << "|                      |" << "                  $" << endl;
	cout << "|  3.R¨¨gle             |" << "                  " << endl;
	cout << "|______________________|" << endl;

}

void menu::AfficherRegle() {
	cout << "R¨¨gle : " << endl;
	cout << endl;
	cout << "Le but du jeu est de soit ne pas prendre la derni¨¨re allumette, soit essayer de " << endl;
	cout << "prendre la derni¨¨re allumette. Ce jeu se joue ¨¤ deux. Les joueurs sont devant un " << endl;
	cout << "certain nombre d'allumettes (qui peut varier d'une partie ¨¤ l'autre). A chaque tour, " << endl;
	cout << "il faut en enlever 1, 2 ou 3. Celui qui prend la derni¨¨re gagne ou perd suivant les" << endl;
	cout << "versions." << endl;
}

int menu::Parametre() {
	int nb = 0;
	cout << "Param¨¨tre :" << endl;
	cout << endl;
	do {
		try {
			cout << "Combien d'allumette voulez-vous jouer ? (>=21 ou <=60) ";
			cin >> nb;
			if (nb < 21 || nb>60) throw 2;
		}
		catch (int e) {
			cout << "Le nombre d'allumette doit ¨ºtre sup¨¦rieur ¨¤ 21 et inf¨¦rieur ¨¤ 60. ERROR: " << e << endl;
		}


	} while ((nb < 21) || (nb > 60));
	return nb;
}

int main() {
	int choix;
	int c;
	char quit;
	char commande;
	bool rejouer = true;
	menu me;
	Jeu j;
	j.init();
	me.AfficherMenu();
	cout << endl;
	cout << endl;
	do {
		try {
			cout << "Saisissez votre choix : ";
			cin >> choix;
			if (choix < 1 || choix>3)
				throw 3;
		}
		catch (int e) {
			cout << "Commande ill¨¦gale. ERROR: " << e << endl;
		}
	} while (choix < 1 || choix>3);
	while (choix == 3 || choix == 2 || choix == 1) {
		if (choix == 3) {
			me.AfficherRegle();
			do {
				try {
					cout << "quit?(q)" << endl;
					cin >> quit;
					if (quit != 'q')
						throw 4;
				}
				catch (int e) {
					cout << "Commande ill¨¦gale. ERROR: " << e << endl;
				}
			} while (quit != 'q');
			if (quit == 'q') {
				me.AfficherMenu();
				cout << endl;
				do {
					try {
						cout << "Saisissez votre choix : ";
						cin >> choix;
						if (choix < 1 || choix>3)
							throw 3;
					}
					catch (int e) {
						cout << "Commande ill¨¦gale. ERROR: " << e << endl;
					}
				} while (choix < 1 || choix>3);
			}

		}
		else if (choix == 2) {
			j.setAllumettes(me.Parametre());
			me.AfficherMenu();
			cout << endl;
			do {
				try {
					cout << "Saisissez votre choix : ";
					cin >> choix;
					if (choix < 1 || choix>3)
						throw 3;
				}
				catch (int e) {
					cout << "Commande ill¨¦gale. ERROR: " << e << endl;
				}
			} while (choix < 1 || choix>3);
		}
		else if (choix == 1) {

			do {
				try {
					cout << "1.Joueur VS Machine" << endl;
					cout << "2.Joueur VS Joueur" << endl;
					cout << "votre choix : " << endl;
					cin >> c;
					if (c < 1 || c>2)
						throw 2;
				}
				catch (int e) {
					cout << "Commande ill¨¦gale. ERROR: " << e << endl;
				}
			} while (c < 1 || c>2);

			j.AjouterJoueur(c);
			int nb = j.getNBAll();
			do {
				j.setAllumettes(nb);
				j.jouer(c);
				j.AfficherResultat(c);
				do {
					try {
						cout << "Vous voulez rejouer? O/N" << endl;
						cin >> commande;
						cout << commande << endl;
						if ((commande != 'O') & (commande != 'o') & (commande != 'N') & (commande != 'n'))
							throw 1;
					}
					catch (int e) {
						cout << "Commande ill¨¦gale. ERROR: " << e << endl;
					}
				} while ((commande != 'O') & (commande != 'o') & (commande != 'N') & (commande != 'n'));
				if (commande == 'N' || commande == 'n') rejouer = false;
			} while (rejouer != false);

			cout << "Bravo! Bien jou¨¦!" << endl;
			choix = 0;
		}
	}
}
