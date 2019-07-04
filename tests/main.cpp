#include "PID.h"

class Plant {
private:
  double _inertia;
  double _bias;
  double _value;

public:
  Plant(double inertia, double bias, double initialValue) : _inertia(inertia), _bias(bias), _value(initialValue) {}

  double next(double value) {
    _inertia += value;
    _inertia -= _bias;
    _value += _inertia;
    std::cout << "inertia: " << _inertia << " _value: " << _value << std::endl;
    return _value;
  }
};

int main() {
  int setPoint = 100;
  Plant plant(0, 2, 0);
  PID::kpid_t kpid{0.5, 0.25, 0.25};
  PID::PID pid(setPoint, kpid, -1, -1);
//  char display[200];
//  for (int i = 0; i < 200; i++) {
//    display[i] = ' ';
//  }
//  display[setPoint] = '|';
  double output = 0;
  for (int i = 0; i < 1024; i++) {
//    display[output] = '0';
//    std::cout << display << std::endl;
//    display[output] = (output != setPoint ? '0' : '|');
//    std::cout << "output: " << output << std::endl;
    int pidVal = pid.next(output);
//    std::cout << "Desired: " << setPoint << " Actual: " << output << " Pid Output: " << pidVal << std::endl;
    output = plant.next(pidVal);
  }
}
