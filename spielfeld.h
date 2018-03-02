#include <iostream>
#include "position.h"
#include "ball.h"
#include "tor.h"
#include "spieler.h"

class Spielfeld {

public:

	Spielfeld();

	void print_Spielfeld();

	int get_breite() const;
	int get_laenge() const;

private:

	 int m_breite = 0;
	 int m_laenge = 0;

	 Ball ball;
	 Spieler spieler;
	 Tor tor;

     bool m_beendet();

};
