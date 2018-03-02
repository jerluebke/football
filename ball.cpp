#include "ball.h"
#include <cstdio>   //for random number
#include <cstdlib>
#include <ctime>

Ball::Ball() {}

Ball::Ball(int feldlaenge, int feldbreite): m_Position(feldlaenge, feldbreite)
{

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
