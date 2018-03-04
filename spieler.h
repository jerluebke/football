#pragma once

#include "position.h"
#include "tor.h"
#include "ball.h"


class Spieler
{
    public:

        Spieler();
        Spieler(const int xmax, const int ymax, Tor *tor, Ball *ball);

        Position get_pos() const;
        void tuEtwas();
        int get_schritte() const;
        int get_schuesse() const;
        bool get_ballErreicht() const;


    private:

        Position m_pos;
        Tor* m_tor;
        Ball* m_ball;
        Position m_naechsteTorPos;

        bool m_ballErreicht;
        bool m_setNaechsteTorPos;
        bool m_schauAufTorRichtungX;

        int m_schritte;
        int m_schuesse;

        bool amBall() const;
        void schiess(int direction);
        void geh(int direction);
        void geheZuBall();
        void geheZuTor();
        Position get_naechsteTorPos();

        int m_xmax, m_ymax;

};

