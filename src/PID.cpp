//
// Created by tiger on 7/2/2019.
//

#include "PID.h"

namespace PID {


using std::time;
using std::time_t;

PID::PID(double setPoint, kpid_t kpid, double clampingLimit = -1, double cutoffFrequency = -1) :
        _setPoint(setPoint), _kpid(kpid), _clampingLimit(clampingLimit), _lpf(cutoffFrequency) {}

double PID::next(double input) {
  if (_lpf.getCutOffFrequency() < 0) input = _lpf.update(input);

  static double previousInput = input;

  int currentTime = time(NULL);
  _integral += static_cast<double>(currentTime - _previousTime) * input;

  double p = _setPoint - input;
  double i = _setPoint - _integral / (currentTime - _previousTime);
  double d = (input - previousInput) * (_setPoint - (input + previousInput) / 2);

  previousInput = input;
  _previousTime = currentTime;

  return p * _kpid.p + ((_clampingLimit > 0 && std::abs(i) > _clampingLimit) ? 0 : (i * _kpid.i)) + d * _kpid.d;
}

void PID::setkP(double value) {
  _kpid.p = value;
}

void PID::setkI(double value) {
  _kpid.i = value;
}

void PID::setkD(double value) {
  _kpid.d = value;
}

void PID::setkpid(kpid_t value) {
  _kpid = value;
}

kpid_t PID::getkpid() {
  return _kpid;
}

void PID::setValue(double value) {
  _setPoint = value;
}

double PID::getValue() {
  return _setPoint;
}


}  // namespace PID
