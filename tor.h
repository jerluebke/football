#include <vector>
#include "position.h"

#ifndef TOR_H
#define TOR_H

class Tor
{
    public:

        Tor();
        Tor(const int xmax, const int ymax);

        std::vector<Position> getPosition() const;
        // int getDirection() const;
        // int getLength() const;


    private:

        std::vector<Position> m_pos;
        // const int m_direction;
        // const int m_length;

        int m_setLocation(const int bound);
        int m_setLength(const int globalBound, const int location);

};

#endif
