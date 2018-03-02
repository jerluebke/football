#include "position.h"
#include "tor.h"
#include "ball.h"

#ifndef SPIELER_H
#define SPIELER_H

class Spieler
{
    public:

        Spieler();
        Spieler(const int xmax, const int ymax, Tor &tor, Ball &ball);

        Position getPos() const;
        void tuEtwas();
        char getLetzteAktion() const;


    private:

        bool m_ballErreicht;

        Position m_pos;
        Tor* m_tor;
        Ball* m_ball;

        int m_schritte;
        int m_schuesse;
        char m_letzteAktion = 0;  // Schritt oder Schuss? Für die Spielstatistik
                                  // t, s

        bool m_amBall() const;
        void m_schiess(int direction);
        void m_geh(int direction);
        void m_geheZuBall();
        void m_geheZumTor();

};

#endif
