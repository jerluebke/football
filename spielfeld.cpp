#include <stdio.h>   //for random number
#include <stdlib.h>
#include <time.h>
#include <thread>
#include "spielfeld.h"
#include "ball.h"


Spielfeld::Spielfeld(int breite, int laenge) : m_breite(breite), m_laenge(laenge),
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
	while (!m_beendet())
	{
		// system("cls");
		m_spieler.tuEtwas();
		updateSpielfeld();
		printSpielfeld();
	}

   // std::this_thread::sleep_for(m_oneSecondDelay);
	m_beendeSpiel();
}

bool Spielfeld::m_beendet()
{
	for (Position &pos : m_tor.getPosition())
		if (m_ball.get_pos() == pos)
			return true;
	return false;
}

void Spielfeld::m_beendeSpiel()
{
    // system("cls");
	std::cout << "Statistik:" << std::endl;
}


unsigned int Spielfeld::m_index(const Position &pos)
{
    unsigned int x = static_cast<unsigned int> (pos.get_posX());
    unsigned int y = static_cast<unsigned int> (pos.get_posY());
    unsigned int b = static_cast<unsigned int> (m_breite);
    return (y * b + x);
}


void Spielfeld::updateSpielfeld()
{
	memset(m_feld, '-', m_breite*m_laenge);

	for (Position &pos : m_tor.getPosition())
		m_feld[m_index(pos)] = '#';
    
	if ((m_ball.get_pos() == m_spieler.getPos()))
    {
		m_feld[m_index(m_ball.get_pos())] = '!';
	}
	else {
		m_feld[m_index(m_ball.get_pos())] = 'o';
		m_feld[m_index(m_spieler.getPos())] = 'I';
	}

}
