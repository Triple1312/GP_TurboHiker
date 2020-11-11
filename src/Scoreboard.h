//
// Created by Phili on 11/11/2020.
//

#ifndef GP_SCOREBOARD_H
#define GP_SCOREBOARD_H
#include <iostream>


class Scoreboard {
private:
    std::uint32_t score;

    Scoreboard();


public:
    static Scoreboard& getInstance() {
        static Scoreboard instance;
        return instance;
    }

};


#endif //GP_SCOREBOARD_H
