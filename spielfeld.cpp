#include <stdio.h>   //for random number
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <cstring>
#include "spielfeld.h"
#include "ball.h"


std::chrono::milliseconds oneSecondDelay(100);


Spielfeld::Spielfeld(int breite, int laenge, char sys='l')
 : m_breite(breite), m_laenge(laenge), m_sys(sys),
    m_feld(nullptr) , m_ball(m_breite, m_laenge),
    m_tor(m_breite, m_laenge), m_spieler(m_breite, m_laenge, &m_tor, &m_ball)
{
    m_feld = new unsigned char[m_breite * m_laenge];

    printSpielfeld();
}

int Spielfeld::get_breite() const { return m_breite; }

int Spielfeld::get_laenge() const { return m_laenge; }


void Spielfeld::printSpielfeld()
{
    for (int i = 0; i < m_laenge; i++)
    {
        for (int j = 0; j < m_breite; j++)
        {
            std::cout << m_feld[i*m_breite+j];
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}


void Spielfeld::macheZug()
{
	while (!beendet())
	{
        // adjust according to your system
        // *nix: `clear`, win: `cls`
        if (m_sys == 'w')
            system("cls");
        else
            system("clear");
		m_spieler.tuEtwas();
		updateSpielfeld();
		printSpielfeld();

        std::this_thread::sleep_for(oneSecondDelay);
        // wenn der Ball erreicht wurde, verkürze die Wartezeit zwischen den
        // Zügen für eine flüssigere Darstellung
        //
        // TODO:
        // Artefakte bei der Darstellung
        //
        // if (!m_spieler.get_ballErreicht())
        //     std::this_thread::sleep_for(oneSecondDelay);
	}

	std::cout << "Statistik:\n";
    std::cout << "\tSchuesse: " << m_spieler.get_schuesse();
    std::cout << "\n\tSchritte: " << m_spieler.get_schritte();
    std::cout << "\n" << std::endl;
}

bool Spielfeld::beendet()
{
	for (Position &pos : m_tor.get_pos())
		if (m_ball.get_pos() == pos)
			return true;
	return false;
}


unsigned int Spielfeld::index(const Position &pos)
{
    unsigned int x = static_cast<unsigned int> (pos.get_posX());
    unsigned int y = static_cast<unsigned int> (pos.get_posY());
    unsigned int b = static_cast<unsigned int> (m_breite);
    return (y * b + x);
}


void Spielfeld::updateSpielfeld()
{
	memset(m_feld, '-', m_breite*m_laenge);

	for (Position &pos : m_tor.get_pos())
		m_feld[index(pos)] = '#';

	if ((m_ball.get_pos() == m_spieler.get_pos()))
    {
		m_feld[index(m_ball.get_pos())] = '!';
	}
	else {
		m_feld[index(m_spieler.get_pos())] = 'I';
        if (beendet())
            m_feld[index(m_ball.get_pos())] = 'x';
        else
            m_feld[index(m_ball.get_pos())] = 'o';
	}

}
