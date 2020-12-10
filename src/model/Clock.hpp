//
// Created by ppp on 12/10/20.
//

#ifndef GP_CLOCK_HPP
#define GP_CLOCK_HPP

#include <chrono>

class Clock {
public:
    static unsigned int GetTimeAsSeconds() {
        return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - begin).count();
    }

    static unsigned int GetTimeAsMilliSeconds() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - begin).count();
    }

    static unsigned int GetTimeAsMicroSeconds() {
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - begin).count();
    }


private:
    Clock(){
        begin = std::chrono::steady_clock::now();
    }

    static std::chrono::_V2::steady_clock::time_point begin;

    static Clock clock;
};


class Timer {
public:

    static Timer ConstructAsSeconds(unsigned int time) { return Timer(time * 1000000); }

    static Timer ConstructAsMicroSeconds(unsigned int time) { return Timer(time); }

    static Timer ConstructAsMilliSeconds(unsigned int time) { return Timer(time * 1000); }

    bool complete(){return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - begin).count() > time;}

private:

    unsigned int time;

    std::chrono::_V2::steady_clock::time_point begin;

    Timer(unsigned int time) : time(time){
        begin  = std::chrono::steady_clock::now();
    }

};
#endif //GP_CLOCK_HPP
