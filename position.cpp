#include "Position.h"
#include <stdlib.h>

Position::Position() {

}
Position::Position(const int rangeX, const int rangeY) {

	srand(time(NULL));
	m_posX = rand() % rangeX + 1; //random position between 1 and rangeX
	m_posY = rand() % rangeY + 1;
}

void Position::set_posX(const int posX)
{
	m_posX = posX;
}
void Position::set_posY(const int posY) {
	m_posY = posY;
}
void Position::set_pos(const int posX, const int posY)
{
	m_posX = posX;
	m_posY = posY;

}

bool Position::operator==(const Position &pos) const {

	if (m_posX == pos.get_posX() && m_posY == pos.get_posY()) {
		return 1;
	}
	else {
		return 0;
	}
}


int Position::get_posX() const {
	return m_posX;
}
int Position::get_posY() const {
	return m_posY;
}