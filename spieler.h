#include "position.h"
#include "tor.h"
// #include "ball.h"

#ifndef SPIELER_H
#define SPIELER_H

class Spieler
{
    public:

        Spieler();
        Spieler(const int xmax, const int ymax);

        int getPos() const;


    private:
        Position m_pos;
        Tor m_tor;
        // Ball m_ball;

        int m_schritte;
        int m_schuesse;
        char m_action;  // Schritt oder Schuss? Für die Spielstatistik

        bool atBall() const;
        void getBallPos() const;
        void getTorPos() const;
        void kick();
        void move();

};

#endif
