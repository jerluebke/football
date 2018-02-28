#include <iostream>
#include "spieler.h"

// TODO:
// Implementierung Spieler::tuEtwas()

//////////////////////
//  Konstuktoren    //
//////////////////////

Spieler::Spieler(){}

Spieler::Spieler(const int xmax, const int ymax, Tor tor, Ball ball)
{
    // Zufallszahlgenerierung hier oder in Position?
    m_pos = Position(xmax, ymax);
    m_tor = tor;
    m_ball = ball;
}


//////////////////////////
//  Public methodes     //
//////////////////////////

Position Spieler::getPos() const
{
    return m_pos;
}

void Spieler::tuEtwas()
{
    std::cerr << "noch nicht implementiert!" << std::endl;
}

char Spieler::getLetzteAktion() const;
{
    return m_letzteAktion;
}


//////////////////////////
//  Private attributes  //
//////////////////////////

bool Spieler::m_amBall() const
{
    if (m_ball.getPos() == this->m_pos)
        return true;
    return false;
}

void Spieler::m_schiess(int direction)
{
    const int x = m_pos.get_posX();
    const int y = m_pos.get_posY();
    switch(direction)
    {
        case 1: m_ball.setPosY(y-1);
                break;

        case 2: m_ball.setPosX(x-1);
                break;

        case 3: m_ball.setPosY(y+1);
                break;

        case 4: m_ball.setPosX(x+1);
                break;

        default: std::cerr << "Bedingung: 0 < direction < 5"
                 << " - Etwas ist schiefgelaufen..." << std::endl;
                 break;
    }
    std::cout << "Schuss!" << std::endl;
    m_letzteAktion = 's';
}

void Spieler::m_geh(int direction)
{
    const int x = m_pos.get_posX();
    const int y = m_pos.get_posY();
    switch(direction)
    {
        case 1: m_pos.set_posY(y-1);
                break;

        case 2: m_pos.set_posX(x-1);
                break;

        case 3: m_pos.set_posY(y+1);
                break;

        case 4: m_pos.set_posX(x+1);
                break;

        default: std::cerr << "Bedingung: 0 < direction < 5"
                 << " - Etwas ist schiefgelaufen..." << std::endl;
                 break;
    }
    std::cout << "Schritt..." << std::endl;
    m_letzteAktion = 't';
}
