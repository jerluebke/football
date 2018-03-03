#include<iostream>
#include "Position.h"
#include "Ball.h"
#include "Tor.h"
#include "Spieler.h"

class Spielfeld {

public:

	Spielfeld();

	void print_Spielfeld();

	int get_breite() const;
	int get_laenge() const;

private:

	 int m_breite = 0;
	 int m_laenge = 0;

	 Ball ball(1,1);
	 Spieler spieler(1, 1);
	 Tor tor(1, 1);


};