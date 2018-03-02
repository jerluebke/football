#ifndef POSITION_H
#define POSITION_H

// NOTIZ
// ich habe `void get_position()` entfernt, da es mir redundant schien

class Position {

    public:

        Position();
        Position(const int posX, const int posY);

        void set_pos(const int posX, const int posY);
        void set_posX(const int posX);
        void set_posY(const int posY);

        int get_posX() const;
        int get_posY() const;

        bool operator==( const Position &pos) const;

        int abstandQuadrat(const Position &pos) const;


    private:

        int m_posX = 0;
        int m_posY = 0;

};

#endif
