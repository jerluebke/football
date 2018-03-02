#include "position.h"
#include <cstdlib>

Position::Position() {}

Position::Position(const int rangeX, const int rangeY)
{
	// srand(time(NULL));
	m_posX = std::rand() % rangeX; //random position between 1 and rangeX
	m_posY = std::rand() % rangeY;
}


void Position::set_posX(const int posX)
{
	m_posX = posX;
}

void Position::set_posY(const int posY)
{
	m_posY = posY;
}

void Position::set_pos(const int posX, const int posY)
{
	m_posX = posX;
	m_posY = posY;
}

bool Position::operator==(const Position &pos) const
{
	if (m_posX == pos.get_posX() && m_posY == pos.get_posY())
    {
		return 1;
	}
	else
    {
		return 0;
	}
}


int Position::get_posX() const { return m_posX; }

int Position::get_posY() const { return m_posY; }


int Position::abstandQuadrat(const Position &pos) const
{
    const int diffX = m_posX - pos.get_posX();
    const int diffY = m_posY - pos.get_posY();
    return ( diffX*diffX + diffY*diffY );
}
