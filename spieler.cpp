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

Position Spieler::get_pos() const
{
    return m_pos;
}

void Spieler::tuEtwas()
{
    if (!amBall())
        geheZuBall();
    else
    {
        if (!m_ballErreicht)
            m_ballErreicht = true;
        geheZuTor();
    }
}


int Spieler::get_schritte() const
{
    return m_schritte;
}

int Spieler::get_schuesse() const
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

bool Spieler::amBall() const
{
    return (m_ball->get_pos() == this->m_pos);
}


void Spieler::schiess(int direction)
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


void Spieler::geh(int direction)
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


void Spieler::geheZuBall()
{
    if (m_pos.get_posX() < m_ball->get_posX())
        geh(4);
    else if (m_pos.get_posX() > m_ball->get_posX())
        geh(2);
    else if (m_pos.get_posY() < m_ball->get_posY())
        geh(1);
    else if (m_pos.get_posY() > m_ball->get_posY())
        geh(3);
}


void Spieler::geheZuTor()
{
    if (!m_setNaechsteTorPos)
    {
        m_naechsteTorPos = get_naechsteTorPos();
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

    if (amBall())
        schiess(direction);
    else
        geh(direction);

}

Position Spieler::get_naechsteTorPos()
{
    Position naechste;
	double MINDISTANZ = m_xmax*m_xmax + m_ymax * m_ymax +1;
    for (Position &currentPos : m_tor->get_pos())
        if (m_pos.abstandQuadrat(currentPos) < MINDISTANZ)
        {
            naechste = currentPos;
            MINDISTANZ = m_pos.abstandQuadrat(currentPos);
        }
    return naechste;
}
