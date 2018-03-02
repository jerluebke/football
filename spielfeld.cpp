#include <stdio.h>   //for random number
#include <stdlib.h>
#include <time.h>
#include "spielfeld.h"
#include "ball.h"


Spielfeld::Spielfeld()
{
	srand(time(NULL));
	m_breite = rand() % 10 + 1;
	m_laenge = rand() % 10 + 1;

    Ball m_ball(m_breite, m_laenge);
    Tor m_tor(m_breite, m_laenge);
    Spieler m_spieler(m_breite, m_laenge, m_tor, m_ball);
}

int Spielfeld::get_breite() const { return m_breite; }

int Spielfeld::get_laenge() const { return m_laenge; }


void Spielfeld::print_Spielfeld() {

	for (int i = 0; i < m_laenge; ++i) {
		for (int j = 0; j < m_breite; ++j)
		{
			Position draw(i, j);
			if (draw == ball.get_pos())
			{
				std::cout << 'o';
			}
			else if (draw == m_SpielerPosition) {

				std::cout << 'i';
			}
			else if (tor.get_direction() % 2 == 0 && i >= tor.get_posX() && i <= tor.get_posX() + tor.get_) {

				std::cout << 'x';
			}
			else if (m_TorLage % 2 != 0 && j >= m_TorPosition.get_posX() && j <= m_TorPosition.get_posX() + m_TorLänge) {

				std::cout << 'x';
			}
			else {

				std::cout << '-';
			}

		}
	}





}
