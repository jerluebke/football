#include "tor.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>


//////////////////////
//  Konstruktor     //
//////////////////////


Tor::Tor(int xmax,  int ymax) : m_direction(0)
{
    // setze eine zufällige Seite
    // +-------+
    // |   3   |
    // |2     4|
    // |   1   |
    // +-------+
    //
    // setze zufällige Position auf der erhaltenen Seite
    // setze zufällige Länge des Tores beschränkt durch die Länge des Feldes
    //
    // da das Tor nicht nur eine Position einnimmt, kann es hilfreich sein,
    // diese Positionen in einem Vektor zu speichern

    const int m_direction = rand() % 4 + 1;
    Position startPos;
    int location;
    int length;
	int start, stop;
    switch (m_direction)
    {
        case 1 : startPos.set_posY(ymax-1);
             start = make_location(xmax);
             stop = make_location(xmax);
             length = static_cast<int> (abs(start-stop))+1;
             location = std::min(start, stop);
             break;
        case 2 : startPos.set_posX(0);
			start = make_location(ymax);
			stop = make_location(ymax);
			length = static_cast<int> (abs(start - stop)) + 1;
			location = std::min(start, stop);
			break;
        case 3 : startPos.set_posY(0);
			start = make_location(xmax);
			stop = make_location(xmax);
			length = static_cast<int> (abs(start - stop)) + 1;
			location = std::min(start, stop);
			break;
        case 4 : startPos.set_posX(xmax-1);
			start = make_location(ymax);
			stop = make_location(ymax);
			length = static_cast<int> (abs(start - stop)) + 1;
			location = std::min(start, stop);
			break;
    }

    for (int i = 0; i < length; i++)
    {

		if (m_direction % 2 == 0) {
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

std::vector<Position> Tor::get_pos() const
{
    return m_pos;
}


int Tor::get_direction() const
{
    return m_direction;
}


int Tor::make_location(const int bound)
{
    return (rand() % bound);
}
