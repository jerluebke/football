#include "ball.h"
#include <stdio.h>   //for random number
#include <stdlib.h>
#include <time.h>

Ball::Ball(const int feldlaenge, const int feldbreite)
{
    Position m_Position(feldlaenge, feldbreite);
}

Position Ball::get_pos() const
{
	return m_Position;
}

void Ball::set_pos(const Position pos)
{
	m_Position.set_pos(pos.get_posX(), pos.get_posY());
}

void Ball::set_posX(const int posX)
{
    m_Position.set_posX(posX);
}

void Ball::set_poxY(const int posY)
{
    m_Position.set_posY(posY);
}
