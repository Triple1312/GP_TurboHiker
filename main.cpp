
#include "view/Factory.h"
#include "model/Clock.hpp"
#include "Utils/Random.hpp"
#include "view/Camera.hpp"

#include "src/Controller.h"


Cam* Cam::camera = nullptr;

logic::Factory* logic::Factory::instance_;

Clock* Clock::instance_;

Random Random::random_;


int main() {
    view::Factory::MakeInstance();
    Controller crl;
    crl.Display();

    delete Cam::Get();
    delete Clock::Get();
    delete view::Factory::Get();

}