
/*
 * Jeu.cpp
 *
 *  Created on: 25 avr. 2019
 *  Author: yuxin
 */

#include <iostream>
using namespace std;
#include <string>
#include "Jeu.h"

using namespace std;

//allumette Jeu::allumettes=0;
void Jeu::init() {
	int nbAl = 21;
	int maxi = 3;
	this->allumette.allumettes(nbAl, maxi);

}

void Jeu::setAllumettes(int nbAl) {
	this->allumette.allumettes(nbAl, 3);
}

int Jeu::getNBAll() {
	return allumette.getnb();
}

void Jeu::retirer(int nb) {
	this->allumette.draw(this->allumette.getnb() - nb);
	this->allumette.allumettes(this->allumette.getnb() - nb, 3);
}

bool Jeu::win() {
	if (this->allumette.getnb() == 0)
		return true;
	else
		return false;
}
void Jeu::jouer(int mode) {
	int nb;
	int nbAllumette = this->allumette.getnb();
	machine.setActuel(false);
	humain1.setActuel(true);
	humain2.setActuel(false);
	this->allumette.draw(nbAllumette);
	if (mode == 1) {
		while (this->allumette.getnb() > 0) {
			cout << endl;
			if (machine.getActuel()) {
				cout << "C'est le tour de la machine:" << endl;
				nb = machine.AI(this->allumette.getnb(), 3);
				//this->allumette.draw(this->allumette.getnb()-nb);
				//this->allumette.allumette(this->allumette.getnb()-nb,3);
				this->retirer(nb);
				if (win()) {
					humain1.gagner();
					cout << humain1.getNom() << "a gagn¨¦!" << endl;
				}
				else {
					cout << endl;
					cout << "Il reste " << this->allumette.getnb() << " allumettes" << endl;
					cout << endl;
					humain1.setActuel(true);
					machine.setActuel(false);
				}
			}
			else {
				//cout<<endl;
				do {
					try {
						cout << "Vous voulez retirer combien d'allumettes?" << endl;
						cin >> nb;

						if (nb < 1 || nb>3)
							throw 0;
						else if ((this->allumette.getnb() - nb) < 0)
							throw "a";
					}
					catch (int e) {
						cout << "Vous pouvez retirer que 1,2 ou 3 allumettes.ERROR: " << e << endl;
					}
					catch (const char *a) {
						cout << "Vous ne pouvez retirer plus de " << this->allumette.getnb() << " allumettes" << endl;
					}
				} while (nb < 1 || nb>3 || (this->allumette.getnb() - nb) < 0);
				//this->allumette.draw(this->allumette.getnb()-nb);
				//this->allumette.allumette(this->allumette.getnb()-nb,3);
				this->retirer(nb);
				if (win()) {
					machine.gagner();
					cout << "machine a gagn¨¦!" << endl;
				}
				else {
					cout << endl;
					cout << "Il reste " << this->allumette.getnb() << " allumettes" << endl;
					cout << endl;
					humain1.setActuel(false);
					machine.setActuel(true);
				}


			}
		}
	}
	else {
		while (this->allumette.getnb() > 0) {

			if (humain2.getActuel()) {
				cout << endl;
				do {
					try {
						cout << humain2.getNom() << ": Vous voulez retirer combien d'allumettes?" << endl;
						cin >> nb;
						if (nb > 3 || nb < 1)
							throw 0;
						else if ((this->allumette.getnb() - nb) < 0)
							throw "a";
					}
					catch (int e) {
						cout << "Vous pouvez retirer que 1,2 ou 3 allumettes. ERROR: " << e << endl;
					}
					catch (const char *a) {
						cout << "Vous ne pouvez retirer plus de " << this->allumette.getnb() << " allumettes" << endl;
					}
				} while (nb > 3 || nb < 1 || (this->allumette.getnb() - nb) < 0);
				//humain2.retirer(this->allumette,nb);
				//this->allumette.draw(this->allumette.getnb()-nb);
				//this->allumette.allumette(this->allumette.getnb()-nb,3);
				this->retirer(nb);
				if (win()) {
					humain1.gagner();
					cout << humain1.getNom() << " a gagn¨¦!" << endl;
				}
				else {
					cout << endl;
					cout << "Il reste " << this->allumette.getnb() << " allumettes" << endl;
					humain1.setActuel(true);
					humain2.setActuel(false);
				}
			}
			else {
				cout << endl;
				do {
					try {
						cout << humain1.getNom() << ": Vous voulez retirer combien d'allumettes?" << endl;
						cin >> nb;
						//this->allumette.draw(this->allumette.getnb()-nb);
						//this->allumette.allumette(this->allumette.getnb()-nb,3);
						if (nb < 1 || nb>3)
							throw 0;
						else if ((this->allumette.getnb() - nb) < 0)
							throw "a";
					}
					catch (int e) {
						cout << "Vous pouvez retirer que 1,2 ou 3 allumettes. ERROR" << e << endl;
					}
					catch (const char *a) {
						cout << "Vous ne pouvez retirer plus de " << this->allumette.getnb() << " allumettes" << endl;
					}
				} while (nb < 1 || nb>3 || (this->allumette.getnb() - nb) < 0);
				this->retirer(nb);
				if (win()) {
					humain2.gagner();
					cout << humain2.getNom() << " a gagn¨¦!" << endl;
				}
				else {
					cout << "Il reste " << this->allumette.getnb() << " allumettes" << endl;
					humain2.setActuel(true);
					humain1.setActuel(false);
				}
			}

		}
	}
}

void Jeu::AfficherResultat(int mode) {
	if (mode == 2) {
		cout << humain1.getNom() << " : " << humain1.getScore() << endl;
		cout << humain2.getNom() << " : " << humain2.getScore() << endl;
	}
	else {
		cout << humain1.getNom() << " : " << humain1.getScore() << endl;
		cout << "machine : " << machine.getScore() << endl;
	}
}


void Jeu::AjouterJoueur(int mode) {
	string n1;
	string n2;
	if (mode == 1) {
		cout << "Saisissez votre nom : " << endl;
		cin >> n1;
		humain1.setNom(n1);
	}
	else {
		cout << "Saisissez le nom de joueur 1: " << endl;
		cin >> n1;
		humain1.setNom(n1);
		cout << "Saisissez le nom de joueur 2: " << endl;
		//getline (cin,n2);
		cin >> n2;
		humain2.setNom(n2);
	}

}


