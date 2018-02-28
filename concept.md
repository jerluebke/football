# Football
---
_TODO:  
`Feld` und `Ball` anpassen  
Ablauf definieren  

Sind die Richtungen so richtig?_

---
## Richtungen
    +-------+
    |   3   |
    |2     4|
    |   1   |
    +-------+


## Schema
    +---------------------------+
    | class Name - Headerfile   |
    +===========================+
    | Konstruktor               |
    +---------------------------+
    | public                    |
    +---------------------------+
    | private                   |
    +---------------------------+


## Klassen

    +-------------------------------+
    | class Position - position.h   |
    +===============================+
    | Position(const int x,         |
    |           const int y)        |
    +-------------------------------+
    | void set_posX(const int x)    |
    | void set_PosY(const int y)    |
    | int get_posX()                |
    | int get_posY()                |
    | bool operator==(Position &pos)|
    +-------------------------------+
    | int m_posX                    |
    | int m_posY                    |
    +-------------------------------+


    +-----------------------+
    | class Feld - feld.h   |
    +=======================+
    | Feld()                |
    +-----------------------+
    | void draw()           |
    |                       |
    +-----------------------+
    | Position m_pos        |
    | Tor m_tor             |
    | Ball m_ball           |
    | Spieler m_spieler     |
    |                       |
    | bool m_beendet()      |
    +-----------------------+


    +-----------------------+
    | class Tor - tor.h     |
    +=======================+
    | Tor(const int xmax,   |
    |       const int ymax) |
    +-----------------------+
    | Position getPosition()|
    | int getDirection()    |
    | int getLength()       |
    | Tor operator=(Tor &t) |
    |  // Compiler: Operator|
    |  //  implizit gelöscht|
    +-----------------------+
    | const Position m_pos  |
    | const int m_direction |  
    | const int m_length    |
    +-----------------------+


    +-----------------------+
    | class Ball - ball.h   |
    +=======================+
    | Ball(const int xmax), |
    |       const int ymax) |
    +-----------------------+
    | void setPosX()        |
    | void setPosY()        |
    | Position getPos()     |
    +-----------------------+
    | const Position m_pos  |
    +-----------------------+


    +---------------------------+
    | class Spieler - spieler.h |
    +===========================+
    | Spieler (const int xmax,  |
    |           const int ymax) |
    +---------------------------+
    | Position getPos()         |
    | void tuEtwas()            |
    | char getLetzteAktion()    |
    +---------------------------+
    | Position m_pos            |
    | Tor m_tor                 |
    | Ball m_ball               |
    |                           |
    | int m_schritte            |
    | int m_schuesse            |
    | char m_letzteAktion       |
    |                           |
    | bool m_amBall()           |
    | void m_schiess()          |
    | void m_geh()              |
    +---------------------------+


                    +-------+
        +-----------| Field |-----------+
        |           +-------+           |
        \/              |               \/         
    +-------+           |           +-------+
    | Goal  |           |           | Ball  |
    +-------+           |           +-------+
        /\              \/             /\
        |           +-------+           |
        +-----------| Player|-----------+
                    +-------+


## Ablauf (main)
---
*   init Field
    -   set random xmax, ymax
    -   init Goal
    -   init Ball
    -   init Player
*   init Goal
    -   set random direction (u, d, l, r)
    -   set random length (< field length)
    -   set random postion (< field length - own length)
*   init Ball
    -   set random Position
*   init Player
    -   retreive reference to Ball and Goal from Field
    -   set random Position
---
_TODO: Ablauf definieren...__
