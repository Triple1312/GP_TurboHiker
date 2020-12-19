#ifndef GP_RANDOM_HPP
#define GP_RANDOM_HPP

#include <ctime>
#include <iostream>

class Random {
public:

    static Random& Get(){
        return random_;
    }

    static float Float(float i, float j) { // precision v 9
        time_t timer;
        time(&timer);
        int range = j - i;
        return i + ((float)(timer * std::rand() % (range * 1000000000)) / 1000000000.f);
    }

    static int Int(int i, int j) {
        time_t timer;
        time(&timer);
        int range = j - i;
        return i + timer * std::rand() % range;
    }

private:

    Random() = default;

    static Random random_;

};

#endif //GP_RANDOM_HPP
