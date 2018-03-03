#include <iostream>
#include "Position.h"

class Ball {

public:

	Ball(int feldlaenge, int feldbreite);

	Position get_pos() const;
	void set_pos(const Position pos);


private:

	Position m_Position;
};
