#pragma once

#include <vector>
#include "position.h"



class Tor
{
    public:

		Tor(){}
        Tor(int xmax, int ymax);

        std::vector<Position> getPosition() const;


    private:

        std::vector<Position> m_pos;

        int m_setLocation(const int bound);
        int m_setLength(const int globalBound, const int location);

};


