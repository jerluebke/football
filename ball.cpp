#include "Ball.h"
#include<stdio.h> < //for random number
#include<stdlib.h>
#include<time.h>

Ball::Ball(const int feldlaenge, const int feldbreite) {

	srand(time(NULL));
	int x = rand() % feldbreite;
	int y = rand() % feldlaenge;

	m_Position.set_pos(x, y);
}

Position Ball::get_pos() const{

	return m_Position;
}

void Ball::set_pos(const Position pos) {

	m_Position.set_pos(pos.get_posX(), pos.get_posY());
}