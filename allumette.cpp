/*
 * allumette.cpp
 *
 *  Created on: 25 avr. 2019
 *      Author: yuxin
 */


#include <iostream>
#include <string>
#include "allumette.h"
using namespace std;

void allumette::allumettes(int nbA, int maximum) {
	this->nbrAllumetteActuel = nbA;
	this->max = maximum;
}

void allumette::draw(int nbrAllumetteActuel) {
	for (int i = 0; i < nbrAllumetteActuel;i++) {
		cout << "O  ";

	}
	cout << endl;
	for (int i = 0; i < nbrAllumetteActuel;i++) {
		cout << "|  ";
	}
	cout << endl;
	for (int i = 0; i < nbrAllumetteActuel;i++) {
		cout << "|  ";
	}
	cout << endl;
	for (int i = 0; i < nbrAllumetteActuel;i++) {
		if (i < 9) cout << i + 1 << "  ";
		else cout << i + 1 << " ";
	}
	cout << endl;
}

int allumette::getnb() {
	return nbrAllumetteActuel;
}

void allumette::setnb(int nb) {
	this->nbrAllumetteActuel = nb;
}

