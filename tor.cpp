#include "tor.h"
#include <stdlib.h>
#include <time.h>


//////////////////////
//  Konstruktor     //
//////////////////////

Tor::Tor(const int xmax, const int ymax)
{
    // setze eine zufällige Seite
    // +-------+
    // |   3   |
    // |2     4|
    // |   1   |
    // +-------+
    //
    // setze zufällige Position auf der erhaltenen Seite
    // setze zufällige Länge des Tores beschränkt durch dir Länge des Feldes
    //
    // da das Tor nicht nur eine Position einnimmt, kann es hilfreich sein,
    // diese Positionen in einem Vektor zu speichern

    srand(time(NULL));
    const int direction = rand() % 4 + 1;
    Position startPos;
    int location;
    int length;
    switch (direction)
    {
        case 1 : startPos.set_posY(ymax);
                 location = m_setLocation(ymax);
                 length = m_setLength(ymax, location);
                 break;
        case 2 : startPos.set_posX(0);
                 location = m_setLocation(xmax);
                 length = m_setLength(xmax, location);
                 break;
        case 3 : startPos.set_posY(0);
                 location = m_setLocation(ymax);
                 length = m_setLength(ymax, location);
                 break;
        case 4 : startPos.set_posX(xmax);
                 location = m_setLocation(xmax);
                 length = m_setLength(xmax, location);
                 break;
    }

    for (int i = 0; i <= length; i++)
    {
        // switch (direction % 2)
        // {
        //     case 0 : Position posY;
        //              posY.set_pos(startPos.get_posX(), location+i);
        //              m_pos.push_back(posY);
        //              break;
        //     case 1 : Position posX;
        //              posX.set_pos(location+i, startPos.get_posX());
        //              m_pos.push_back(posX);
        //              break;
        // }

        if (direction % 2 == 0)
        {
            Position posY;
            posY.set_pos(startPos.get_posX(), location+i);
            m_pos.push_back(posY);
        }
        else
        {
            Position posX;
            posX.set_pos(location+i, startPos.get_posX());
            m_pos.push_back(posX);
        }

    }
}

std::vector<Position> Tor::getPosition() const
{
    return m_pos;
}


int Tor::m_setLocation(const int bound)
{
    srand(time(NULL));
    return (rand() % bound);
}

int Tor::m_setLength(const int globalBound, const int location)
{
    srand(time(NULL));
    return (rand() % (globalBound - location));
}
