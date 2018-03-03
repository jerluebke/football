#include <iostream>
#include <cmath>
#include "spieler.h"


//////////////////////
//  Konstuktoren    //
//////////////////////

Spieler::Spieler(){}

Spieler::Spieler(const int xmax, const int ymax, Tor *tor, Ball *ball) : 
	m_pos(xmax, ymax)
{
	m_xmax = xmax;
	m_ymax = ymax;

	m_ballErreicht = false;
    m_tor = tor;
    m_ball = ball;

    m_setNaechsteTorPos = false;
}
// 
// Spieler::Spieler(Position pos, Tor *tor, Ball *ball)
// {
//     m_pos = pos;
// 
// 
//     m_ballErreicht = false;
//     m_tor = tor;
//     m_ball = ball;
//     m_ballPos = m_ball->get_pos();
//     m_torPos = m_tor->getPosition();
// 
//     m_setNaechsteTorPos = false;
// 
// }
// 

//////////////////////////
//  Public methodes     //
//////////////////////////

Position Spieler::getPos() const
{
    return m_pos;
}

void Spieler::tuEtwas()
{
    if (!m_amBall())
        m_geheZuBall();
    else
    {
        if (!m_ballErreicht)
            m_ballErreicht = true;
        m_geheZumTor();
    }
}


int Spieler::getSchritte() const
{
    return m_schritte;
}

int Spieler::getSchuesse() const
{
    return m_schuesse;
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
    return (m_ball->get_pos() == this->m_pos);
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

        // default: std::cerr << "Bedingung: 0 < direction < 5"
        //          << " - Etwas ist schiefgelaufen..." << std::endl;
        //          break;
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

        // default: std::cerr << "Bedingung: 0 < direction < 5"
        //          << " - Etwas ist schiefgelaufen..." << std::endl;
        //          break;
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
{
    if (m_pos.get_posX() < m_ball->get_posX())
        m_geh(4);
    else if (m_pos.get_posX() > m_ball->get_posX())
        m_geh(2);
    else if (m_pos.get_posY() < m_ball->get_posY())
        m_geh(1);
    else if (m_pos.get_posY() > m_ball->get_posY())
        m_geh(3);
}


void Spieler::m_geheZumTor()
{
    if (!m_setNaechsteTorPos)
    {
        m_naechsteTorPos = m_getNaechsteTorPos();
        m_setNaechsteTorPos = true;
    }

    int direction;
    if (m_pos.get_posX() < m_naechsteTorPos.get_posX())
        direction = 4;
    else if (m_pos.get_posX() > m_naechsteTorPos.get_posX())
        direction = 2;
    else if (m_pos.get_posY() < m_naechsteTorPos.get_posY())
        direction = 3;
    else if (m_pos.get_posY() > m_naechsteTorPos.get_posY())
        direction = 1;

    if (m_amBall())
        m_schiess(direction);
    else
        m_geh(direction);

}

Position Spieler::m_getNaechsteTorPos()
{
    Position naechste;
	double MAXDISTANZ = m_xmax*m_xmax + m_ymax * m_ymax +1;
    for (Position &currentPos : m_tor->getPosition())
        if (m_pos.abstandQuadrat(currentPos) < MAXDISTANZ)
            naechste = currentPos;
    return naechste;
}
