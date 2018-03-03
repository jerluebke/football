#include "tor.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>


//////////////////////
//  Konstruktor     //
//////////////////////


Tor::Tor(int xmax,  int ymax)
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

    const int direction = rand() % 4 + 1;
    Position startPos;
    int location;
    int length;
	int start, stop;
    switch (direction)
    {
        case 1 : startPos.set_posY(ymax-1);
                 start = m_setLocation(xmax);
				 stop = m_setLocation(xmax);
				 length = static_cast<int> (abs(start-stop))+1;
				 location = std::min(start, stop);
                 break;
        case 2 : startPos.set_posX(0);
			start = m_setLocation(ymax);
			stop = m_setLocation(ymax);
			length = static_cast<int> (abs(start - stop)) + 1;
			location = std::min(start, stop);
			break;
        case 3 : startPos.set_posY(0);
			start = m_setLocation(xmax);
			stop = m_setLocation(xmax);
			length = static_cast<int> (abs(start - stop)) + 1;
			location = std::min(start, stop);
			break;
        case 4 : startPos.set_posX(xmax-1);
			start = m_setLocation(ymax);
			stop = m_setLocation(ymax);
			length = static_cast<int> (abs(start - stop)) + 1;
			location = std::min(start, stop);
			break;
    }

    for (int i = 0; i < length; i++)
    {

		if (direction % 2 == 0) {
			Position posY;
			posY.set_pos(startPos.get_posX(), location + i);
			m_pos.push_back(posY);

		}
		else {
			Position posX;
			posX.set_pos(location + i, startPos.get_posY());
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
    return (rand() % bound);
}

int Tor::m_setLength(const int globalBound, const int location)
{

	return (rand() % (globalBound  - location))+1;
}
