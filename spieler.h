#pragma once

#include "position.h"
#include "tor.h"
#include "ball.h"


class Spieler
{
    public:

        Spieler();
        Spieler(const int xmax, const int ymax, Tor *tor, Ball *ball);

        Position getPos() const;
        void tuEtwas();
        int getSchritte() const;
        int getSchuesse() const;


    private:

        bool m_ballErreicht;

        Position m_pos;
        Tor* m_tor;
        Ball* m_ball;
        Position m_naechsteTorPos;
        bool m_setNaechsteTorPos;

        int m_schritte;
        int m_schuesse;
        char m_letzteAktion = 0;  // Schritt oder Schuss? Für die Spielstatistik
                                  // t, s

        bool m_amBall() const;
        void m_schiess(int direction);
        void m_geh(int direction);
        void m_geheZuBall();
        void m_geheZumTor();
        Position m_getNaechsteTorPos();

        int m_xmax, m_ymax;

};

