#pragma once

#include <vector>
#include "position.h"



class Tor
{
    public:

		Tor() : m_direction(0) {}
        Tor(int xmax, int ymax);

        std::vector<Position> get_pos() const;
        int get_direction() const;


    private:

        std::vector<Position> m_pos;
        const int m_direction;

        int make_location(const int bound);

};


