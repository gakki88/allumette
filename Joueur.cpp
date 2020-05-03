/*
 * Joueur.cpp
 *
 *  Created on: 25 avr. 2019
 *      Author: yuxin
 */

#include <iostream>
using namespace std;
#include <string>
#include "Joueur.h"

void Joueur::gagner() {
	record += 1;
}

int Joueur::getScore() {
	return record;
}

bool Joueur::getActuel() {
	return JoueurActuel;
}

void Joueur::setActuel(bool act) {
	JoueurActuel = act;
}



string Humain::getNom() {
	return nom;
}
void Humain::setNom(string n) {
	nom = n;
}

int Machine::AI(int reste, int max) {
	int dividende = max + 1;
	if (reste % dividende == 1)
		return 1;
	else if (reste % dividende == 0)
		return max;
	else return (reste % dividende) - 1;
}


