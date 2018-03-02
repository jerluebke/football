#pragma once

#include <iostream>
#include "position.h"

class Ball {

public:

    Ball();
	Ball(int feldlaenge, int feldbreite);

	void set_pos(const Position pos);
    void set_posX(const int posX);
    void set_poxY(const int posY);

    Position get_pos() const;


private:

	Position m_Position;

};
