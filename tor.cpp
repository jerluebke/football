#include "tor.h"


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
}

std::vector<Position> Tor::getPosition() const
{
    return m_pos;
}
