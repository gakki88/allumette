#pragma once
/*
 * Jeu.h
 *
 *  Created on: 28 avr. 2017
 *      Author: ytang01
 */

#ifndef JEU_H_
#define JEU_H_

#include "allumette.h"
#include "Joueur.h"
#include "menu.h"


class Jeu {
public:
	//Jeu();
	void init();
	bool win();
	void jouer(int);
	void AfficherResultat(int);
	void AjouterJoueur(int);
	void setAllumettes(int);
	void retirer(int);
	int getNBAll();
private:
	allumette allumette;
	Humain humain1;
	Humain humain2;
	Machine machine;
};


#endif /* JEU_H_ */
