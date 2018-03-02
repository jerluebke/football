#include <stdio.h>   //for random number
#include <stdlib.h>
#include <time.h>
#include <thread>
#include "spielfeld.h"
#include "ball.h"


Spielfeld::Spielfeld() : m_breite(0), m_laenge(0), m_feld(nullptr)
{
	srand(time(NULL));
	m_breite = rand() % 10 + 1;
	m_laenge = rand() % 10 + 1;

    m_feld = new unsigned char[m_breite * m_laenge];
    memset (m_feld, '-', m_breite*m_laenge);

    Ball m_ball(m_breite, m_laenge);
    Tor m_tor(m_breite, m_laenge);
    Spieler m_spieler(m_breite, m_laenge, m_tor, m_ball);

    m_torPos = m_tor.getPosition();
    m_ballPos = m_ball.get_pos();
    m_spielerPos = m_spieler.getPos();

    m_feld[m_index(m_ballPos)] = 'o';
    m_feld[m_index(m_spielerPos)] = 'I';
    for (Position pos : m_torPos)
        m_feld[m_index(pos)] = '#';

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
        printSpielfeld();

        // std::this_thread::sleep_for(m_oneSecondDelay);
    }

    m_beendeSpiel();
}

void Spielfeld::m_beendeSpiel() const
{
    system("cls");
    std::cout << "TOR!\n\n";
    std::cout << "Statistik:" << "\n";
    std::cout << "\tSchritte: " << m_spieler.getSchritte();
    std::cout << "\tSchuesse: " << m_spieler.getSchuesse();
    std::cout << std::endl;
}

bool Spielfeld::m_beendet()
{
    for (Position torPos : m_torPos)
        if (m_ball.get_pos() == torPos)
            return true;
    return false;
}

unsigned int Spielfeld::m_index(Position &pos)
{
    unsigned int x = static_cast<unsigned int> (pos.get_posX());
    unsigned int y = static_cast<unsigned int> (pos.get_posY());
    unsigned int b = static_cast<unsigned int> (m_breite);
    return (y * b + x);
}
