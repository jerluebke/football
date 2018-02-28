#include "position.h"

#ifndef TOR_H
#define TOR_H

class Tor
{
    public:

        Tor(int xmax, int ymax);
        ~Tor();

        Position getPosition() const;
        int getLength();


    private:

        const Position m_pos;
        const int m_direction;
        const int m_length;
};

#endif
