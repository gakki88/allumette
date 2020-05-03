#pragma once
/*
 * Joueur.h
 *
 *  Created on: 25 avr. 2019
 *      Author: yuxin
 */

#ifndef JOUEUR_H_
#define JOUEUR_H_
#include<iostream>
using namespace std;
#include <string>
#include "allumette.h"

class Joueur {
public:
	void gagner();
	int  getScore();
	bool getActuel();
	void setActuel(bool);

private:
	int record = 0;
	bool JoueurActuel;
};



class Machine :public Joueur {
public:

	int AI(int, int);
};

class Humain :public Joueur {
public:
	string getNom();
	void setNom(string);
private:
	string nom;
};



#endif /* JOUEUR_H_ */

