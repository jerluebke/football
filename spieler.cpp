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

    m_tor = tor;
    m_ball = ball;

	m_ballErreicht = false;
    m_schauAufTorRichtungX = (m_tor->get_direction() % 2 == 0) ? true : false;
    m_setNaechsteTorPos = false;

    m_schritte = 0;
    m_schuesse = 0;

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
    if (!m_amBall())
        m_geheZuBall();
    else
    {
        if (!m_ballErreicht)
            m_ballErreicht = true;
        m_geheZuTor();
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

bool Spieler::get_ballErreicht() const
{
    return m_ballErreicht;
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

    }
    std::cout << "Schuss!" << std::endl;
    m_schuesse++;
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

    }
    std::cout << "Schritt..." << std::endl;
    m_schritte++;
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


void Spieler::m_geheZuTor()
{
    if (!m_setNaechsteTorPos)
    {
        m_naechsteTorPos = m_getNaechsteTorPos();
        m_setNaechsteTorPos = true;
    }

    int direction;
    int torPosX = m_naechsteTorPos.get_posX();
    int torPosY = m_naechsteTorPos.get_posY();
    // Idee bei diesem Konstrukt:
    // gehe erst so, dass der Spieler auf das Tor schaut
    // und dann gehe auf das Tor zu
    // Der Ball soll nicht "seitlich" in das Tor gespielt werden
    // TODO:
    // ist das Tor rechts oder links, verhält sich das Spiel wie gewünscht
    // ist das Tor oben oder unten, funktioniert es nicht
    if (!m_schauAufTorRichtungX)
    {
        int currentPosX = m_pos.get_posX();
        if (currentPosX < torPosX)
            direction = 4;
        else if (currentPosX > torPosX)
            direction = 2;
        else    // currentPosX == torPosX
            m_schauAufTorRichtungX = true;
    }
    if (m_schauAufTorRichtungX)
    {
        int currentPosY = m_pos.get_posY();
        if (currentPosY < torPosY)
            direction = 1;
        else if (currentPosY > torPosY)
            direction = 3;
        else    // currentPosY == torPosY
            m_schauAufTorRichtungX = false;
    }

    if (m_amBall())
        m_schiess(direction);
    else
        m_geh(direction);

}

Position Spieler::m_getNaechsteTorPos()
{
    Position naechste;
	double MINDISTANZ = m_xmax*m_xmax + m_ymax * m_ymax +1;
    for (Position &currentPos : m_tor->getPosition())
        if (m_pos.abstandQuadrat(currentPos) < MINDISTANZ)
        {
            naechste = currentPos;
            MINDISTANZ = m_pos.abstandQuadrat(currentPos);
        }
    return naechste;
}
