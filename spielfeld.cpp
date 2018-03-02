#include <stdio.h>   //for random number
#include <stdlib.h>
#include <time.h>
#include <thread>
#include "spielfeld.h"
#include "ball.h"


Spielfeld::Spielfeld(int breite, int laenge) : m_breite(breite), m_laenge(laenge), m_feld(nullptr) , m_ball(m_breite, m_laenge),
m_tor(m_breite, m_laenge), m_spieler(m_breite, m_laenge, &m_tor, &m_ball)
{
	
    m_feld = new unsigned char[m_breite * m_laenge];
    memset (m_feld, '-', m_breite*m_laenge);

    m_torPos = m_tor.getPosition();
    m_ballPos = m_ball.get_pos();
    m_spielerPos = m_spieler.getPos();

    m_feld[m_index(m_ballPos)] = 'o';
    m_feld[m_index(m_spielerPos)] = 'I';
    for (Position &pos : m_torPos)
        m_feld[m_index(pos)] = '#';

    printSpielfeld();

}

int Spielfeld::get_breite() const { return m_breite; }

int Spielfeld::get_laenge() const { return m_laenge; }

// 
// void Spielfeld::print_Spielfeld() {
// 
//     for (int i = 0; i < m_laenge; ++i) {
//         for (int j = 0; j < m_breite; ++j)
//         {
//             Position draw(i, j);
//             if (draw == ball.get_pos())
//             {
//                 std::cout << 'o';
//             }
//             else if (draw == m_SpielerPosition) {
// 
//                 std::cout << 'i';
//             }
//             else if (tor.get_direction() % 2 == 0 && i >= tor.get_posX() && i <= tor.get_posX() + tor.get_) {
// 
//                 std::cout << 'x';
//             }
//             else if (m_TorLage % 2 != 0 && j >= m_TorPosition.get_posX() && j <= m_TorPosition.get_posX() + m_TorLänge) {
// 
//                 std::cout << 'x';
//             }
//             else {
// 
//                 std::cout << '-';
//             }
// 
//         }
//     }
// 
// 
// 
// 
// 
// }
// 


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
    if (m_beendet())
    {
        m_beendeSpiel();
        return;
    }
    system("cls");
    m_spieler.tuEtwas();
    printSpielfeld();

   // std::this_thread::sleep_for(m_oneSecondDelay);

}

bool Spielfeld::m_beendet()
{
	return false;
}

void Spielfeld::m_beendeSpiel()
{
    system("cls");
	std::cout << "Statistik:" << std::endl;
}


unsigned int Spielfeld::m_index(Position &pos)
{
    unsigned int x = static_cast<unsigned int> (pos.get_posX());
    unsigned int y = static_cast<unsigned int> (pos.get_posY());
    unsigned int b = static_cast<unsigned int> (m_breite);
    return (y * b + x);
}
