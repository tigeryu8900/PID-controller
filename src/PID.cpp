//
// Created by tiger on 7/2/2019.
//

#include "PID.h"

namespace PID {


int64_t PID::nanos() {
  return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::time_point_cast<std::chrono::nanoseconds>(
          (std::chrono::high_resolution_clock::now())).time_since_epoch()).count();
}

PID::PID(double setPoint, kpid_t kpid, double clampingLimit = -1, double cutoffFrequency = -1) :
        _setPoint(setPoint), _kpid(kpid), _clampingLimit(clampingLimit), _lpf(cutoffFrequency) {
  _startTime = _previousTime = nanos();
  std::this_thread::sleep_for(std::chrono::milliseconds(2));
}

/*
double PID::next(double input) {
//  std::cout << "input: " << input << std::endl;
  if (_lpf.getCutOffFrequency() > 0) input = _lpf.update(input);

  static double previousInput = input;

  int64_t currentTime = nanos();
  _integral += static_cast<double>(currentTime - _previousTime) * input;

  double p = _setPoint - input;
  double i = _setPoint - _integral / static_cast<double>(currentTime - _previousTime);
  double d = (input - previousInput) * (_setPoint - (input + previousInput) / 2);

//  std::cout << "input: " << input << " time lapse: " << currentTime - _previousTime << " p: " << p << " i: " << i << " d: " << d << std::endl;
//  std::cout << "_setPoint: " << _setPoint << " _integral: " <<_integral << " elapsed time: " <<
//            static_cast<double>(currentTime - _previousTime) << std::endl;

  previousInput = input;
  _previousTime = currentTime;

  return p * _kpid.p + ((_clampingLimit > 0 && std::abs(i) > _clampingLimit) ? 0 : (i * _kpid.i)) + d * _kpid.d;
}
 */

double PID::next(double input) {
  static double previousInput = input;

  int64_t now = nanos();

  /*Compute all the working error variables*/
  double error = _setPoint - input;
  double dInput = (input - previousInput);
  _integral += (_kpid.i * error) - _kpid.p * dInput;

//  if(outputSum > outMax) outputSum= outMax;
//  else if(outputSum < outMin) outputSum= outMin;

  /*Add Proportional on Error, if P_ON_E is specified*/
  double output = _kpid.p * error + _integral - _kpid.d * dInput;

//  if(output > outMax) output = outMax;
//  else if(output < outMin) output = outMin;

  /*Remember some variables for next time*/
  previousInput = input;
  _previousTime = now;
  return output;
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
