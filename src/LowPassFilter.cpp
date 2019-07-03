
#include "LowPassFilter.h"

LowPassFilter::LowPassFilter() :
        output(0),
        cutOffFrequency(0) {}

LowPassFilter::LowPassFilter(double iCutOffFrequency) :
        output(0),
        cutOffFrequency(iCutOffFrequency),
        ePow(0) {}

LowPassFilter::LowPassFilter(double iCutOffFrequency, double iDeltaTime) :
        output(0),
        cutOffFrequency(iCutOffFrequency),
        ePow(1 - exp(-iDeltaTime * iCutOffFrequency)) {}

double LowPassFilter::update(double input) {
  return output += (input - output) * ePow;
}

double LowPassFilter::update(double input, double deltaTime) {
  setDeltaTime(deltaTime); //Changes ePow accordingly.
  return output += (input - output) * ePow;
}

double LowPassFilter::getOutput() {
  return output;
}

double LowPassFilter::getCutOffFrequency() {
  return cutOffFrequency;
}

void LowPassFilter::setCutOffFrequency(double input) {
  if (input >= 0) {
    cutOffFrequency = input;
  } else {
    cutOffFrequency = 0;
    std::cout << "Warning: A LowPassFilter instance has been configured with 0 Hz as cut-off frequency.";
  }
}

void LowPassFilter::setDeltaTime(double deltaTime) {
  if (deltaTime >= 0) {
    ePow = 1 - exp(-deltaTime * cutOffFrequency);
  } else {
    ePow = 0;
    std::cout << "Warning: A LowPassFilter instance has been configured with 0 s as delta time.";
  }
}