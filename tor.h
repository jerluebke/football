#include "position.h"

#ifndef TOR_H
#define TOR_H

class Tor
{
    public:

        Tor();
        Tor(const int xmax, const int ymax);

        Position getPosition() const;
        int getDirection() const;
        int getLength() const;

        // Compiler-Meldung
        // copy-Operator implizit gelöscht
        // deswegen hier Neudeklaration
        // TODO: Implementierung
        Tor operator=(Tor &tor) const;


    private:

        const Position m_pos;
        const int m_direction;
        const int m_length;

};

#endif
