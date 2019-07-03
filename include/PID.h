//
// Created by tiger on 7/2/2019.
//

#ifndef PID_CONTROLLER_PID_H
#define PID_CONTROLLER_PID_H

#include <ctime>
#include "LowPassFilter.h"

namespace PID {


using std::time;
using std::time_t;

struct kpid_t {
  double p;
  double i;
  double d;
};

class PID {

  double _setPoint;
  kpid_t _kpid;
  double _clampingLimit;

  time_t startTime = time(nullptr);
  time_t _previousTime = startTime;
  int _integral = 0;

  LowPassFilter _lpf;

  PID(double setPoint, kpid_t kpid, double clampingLimit, double cutoffFrequency);

  double next(double input);

  void setkP(double value);

  void setkI(double value);

  void setkD(double value);

  void setkpid(kpid_t value);

  kpid_t getkpid();

  void setValue(double value);

  double getValue();
};


}  // namespace PID

#endif // PID_CONTROLLER_PID_H
