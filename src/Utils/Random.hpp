#ifndef GP_SRC_UTILS_RANDOM_HPP_
#define GP_SRC_UTILS_RANDOM_HPP_

#include <random>
#include <iostream>

class Random {
public:

    static Random& Get(){
        return random_;
    }

    float Float(float i, float j) { // precision v 9
      std::uniform_real_distribution<float> distribution(i, std::nextafter(j, FLT_MAX));
      return distribution(random_device_); // todo efficientere random
    }

    int Int(int i, int j) {
      std::uniform_int_distribution<int> distribution(i, std::nextafter(j, INT_MAX));
      return distribution(random_device_); // todo efficientere random
    }

private:

    Random() = default;

    static Random random_;

    std::random_device random_device_;

};

#endif //GP_SRC_UTILS_RANDOM_HPP_
