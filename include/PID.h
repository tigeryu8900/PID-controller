//
// Created by tiger on 7/2/2019.
//

#ifndef PID_CONTROLLER_PID_H
#define PID_CONTROLLER_PID_H

#include <chrono>
#include <thread>

#include "LowPassFilter.h"

namespace PID {


struct kpid_t {
  double p;
  double i;
  double d;
};

class PID {
private:
  double _setPoint;
  kpid_t _kpid;
  double _clampingLimit;

  int64_t _startTime;
  int64_t _previousTime;
  int64_t _integral = 0;

  LowPassFilter _lpf;

  static int64_t nanos();

public:
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
