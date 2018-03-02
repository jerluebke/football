#pragma once

#include <iostream>
#include <chrono>
#include "position.h"
#include "ball.h"
#include "tor.h"
#include "spieler.h"

class Spielfeld
{

public:

	Spielfeld();
    ~Spielfeld() { delete[] m_feld; }

	void printSpielfeld();

	int get_breite() const;
	int get_laenge() const;
    void macheZug();

private:

	 int m_breite = 0;
	 int m_laenge = 0;

     unsigned char *m_feld;

	 Ball m_ball;
	 Spieler m_spieler;
	 Tor m_tor;
     std::vector<Position> m_torPos;
     Position m_ballPos;
     Position m_spielerPos;

     bool m_beendet();
     void m_beendeSpiel() const;

     unsigned int m_index(Position &pos);

     // std::chrono::seconds m_oneSecondDelay(1000);

};
