#include <iostream>
#include "spieler.h"


//////////////////////
//  Konstuktoren    //
//////////////////////

Spieler::Spieler(){}

Spieler::Spieler(const int xmax, const int ymax, Tor &tor, Ball &ball)
{
    m_ballErreicht = false;
    Position m_pos(xmax, ymax);
    m_tor = &tor;
    m_ball = &ball;
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
    return;

    if (!m_amBall())
        m_geheZuBall();
    else
    {
        if (!m_ballErreicht)
            m_ballErreicht = true;
        m_geheZumTor();
    }
}

char Spieler::getLetzteAktion() const
{
    return m_letzteAktion;
}


//////////////////////////
//  Private attributes  //
//////////////////////////

// Richtungen
// +-------+
// |   3   |
// |2     4|
// |   1   |
// +-------+

bool Spieler::m_amBall() const
{
    if (m_ball->get_pos() == this->m_pos)
        return true;
    return false;
}


void Spieler::m_schiess(int direction)
{
    const int x = m_pos.get_posX();
    const int y = m_pos.get_posY();
    switch(direction)
    {
        case 1: m_ball->set_poxY(y+1);
                break;

        case 2: m_ball->set_posX(x-1);
                break;

        case 3: m_ball->set_poxY(y-1);
                break;

        case 4: m_ball->set_posX(x+1);
                break;

        default: std::cerr << "Bedingung: 0 < direction < 5"
                 << " - Etwas ist schiefgelaufen..." << std::endl;
                 break;
    }
    std::cout << "Schuss!" << std::endl;
    m_schuesse++;
    m_letzteAktion = 's';
}


void Spieler::m_geh(int direction)
{
    const int x = m_pos.get_posX();
    const int y = m_pos.get_posY();
    switch(direction)
    {
        case 1: m_pos.set_posY(y+1);
                break;

        case 2: m_pos.set_posX(x-1);
                break;

        case 3: m_pos.set_posY(y-1);
                break;

        case 4: m_pos.set_posX(x+1);
                break;

        default: std::cerr << "Bedingung: 0 < direction < 5"
                 << " - Etwas ist schiefgelaufen..." << std::endl;
                 break;
    }
    std::cout << "Schritt..." << std::endl;
    m_schritte++;
    m_letzteAktion = 't';
}


// Gehe-Zu-Methoden:
//
// hole xPos vom Ziel
// gehe in x-Richtung, bis eigene xPos mit Ziel übereinstimmt
// hole yPos vom Ziel und gehe dort hin
//
// Für den Weg zum Tor:
// abwechselnd schießen und gehen


void Spieler::m_geheZuBall()
{}

void Spieler::m_geheZumTor()
{}
