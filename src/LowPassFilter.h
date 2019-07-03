// https://github.com/overlord1123/LowPassFilter

#ifndef _LowPassFilter_h_
#define _LowPassFilter_h_

#include <iostream>
#include <cmath>

class LowPassFilter {
public:
  //constructors
  LowPassFilter();

  LowPassFilter(double iCutOffFrequency);

  LowPassFilter(double iCutOffFrequency, double iDeltaTime);

  //functions
  double update(double input);

  double update(double input, double deltaTime);

  //get and set funtions
  double getOutput();

  double getCutOffFrequency();

  void setCutOffFrequency(double input);

  void setDeltaTime(double input);

private:
  double output;
  double cutOffFrequency;
  double ePow;
};

#endif //_LowPassFilter_h_
