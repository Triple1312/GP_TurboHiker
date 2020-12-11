//
// Created by ppp on 12/10/20.
//

#ifndef GP_CLOCK_HPP
#define GP_CLOCK_HPP

#include <chrono>

class Clock {
public:
    unsigned int GetTimeAsSeconds() {
        return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - begin).count();
    }

    unsigned int GetTimeAsMilliSeconds() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - begin).count();
    }

    unsigned int GetTimeAsMicroSeconds() {
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - begin).count();
    }

    void Update() {
        since_last = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - last).count();
        last = std::chrono::steady_clock::now();
    }

    static Clock* Get() {
        if (!instance) {
            instance = new Clock;
        }
        return instance;
    }

    double TimeSinceLast() const {
        return since_last;
    }

    double GetTimeSinceLastInSeconds() const {
        return since_last/1000000;
    }


private:
    Clock() {
        begin = std::chrono::steady_clock::now();
        last = std::chrono::steady_clock::now();
        since_last = 0;

    }

    std::chrono::_V2::steady_clock::time_point begin;

    float since_last;

    std::chrono::_V2::steady_clock::time_point last;

    static Clock* instance ;
};


class Timer {
public:

    static Timer ConstructAsSeconds(unsigned int time) { return Timer(time * 1000000); }

    static Timer ConstructAsMicroSeconds(unsigned int time) { return Timer(time); }

    static Timer ConstructAsMilliSeconds(unsigned int time) { return Timer(time * 1000); }

    bool Complete(){return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - begin).count() > time;}

private:

    unsigned int time;

    std::chrono::_V2::steady_clock::time_point begin;

    Timer(unsigned int time) : time(time){
        begin  = std::chrono::steady_clock::now();
    }

};
#endif //GP_CLOCK_HPP
