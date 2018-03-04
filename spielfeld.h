#pragma once

#include <iostream>
#include "position.h"
#include "ball.h"
#include "tor.h"
#include "spieler.h"

class Spielfeld
{

public:

	Spielfeld(int breite, int laenge, char sys);
    ~Spielfeld() { delete[] m_feld; }

	void printSpielfeld();

	int get_breite() const;
	int get_laenge() const;
    void macheZug();

private:

     char m_sys;

	 int m_breite = 0;
	 int m_laenge = 0;

     unsigned char *m_feld;

	 Ball m_ball;
	 Spieler m_spieler;
	 Tor m_tor;


     void updateSpielfeld();
     bool beendet();

     unsigned int index(const Position &pos);


};
