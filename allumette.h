/*
 * allumette.h
 *
 *  Created on: 25 avr. 2019
 *  Author: yuxin
 */

#pragma once
#ifndef ALLUMETTE_H_
#define ALLUMETTE_H_

class allumette {
public:
	
	void draw(int);
	void allumettes(int, int);
	int getnb();
	void setnb(int);
private:
	int nbrAllumetteActuel;
	int max;
};



#endif /* ALLUMETTE_H_ */

