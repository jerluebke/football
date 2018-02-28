# Football

    +-----------------------+
    | Field                 |
    +=======================+
    | const int xmax        |
    | const int ymax        |
    |                       |
    | Goal                  |
    | Ball                  |
    | Player                |
    +-----------------------+
    | bool start            |
    | void draw(bool start) |
    | bool finished         |
    |                       |
    +-----------------------+


    +-----------------------+
    | Goal                  |
    +=======================+
    | const char direction  |  
    | const int length      |
    | const int postion     |
    +-----------------------+
    | getPosition           |
    | getLength             |
    +-----------------------+


    +---------------+
    | Ball          |
    +===============+
    | int xPos      |
    | int yPos      |
    +---------------+
    | setPos        |
    | getPos        |
    +---------------+


    +---------------------------+
    | Player                    |
    +===========================+
    | int xPos                  |
    | int yPos                  |
    |                           |
    | Goal                      |
    | Ball                      |
    |                           |
    | char whichAction          |
    | int steps                 |
    | int shots                 |
    +---------------------------+
    | bool atBall               |
    | void getBallPos           |
    | void getGoalPos           |
    | void kick(char direction) |
    | void move(char direction) |
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


# main procedure
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
*   
