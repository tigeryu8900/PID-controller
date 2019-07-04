# PID-controller

This library provides a way to implement PID controllers.

A PID controller is a control loop feedback mechanism that adjusts an input to get a
desired output.

## Getting Started

These instructions will get you a copy of the project up and running on your local
machine for development and testing purposes.

### Perquisites

#### CMake

Go to the [CMake download page](https://cmake.org/download/) and download CMake.

Read the [tutorial](https://cmake.org/cmake-tutorial/) if you want to contribute.

### Installing

Build the project using this command:

```
cmake -Hpath/to/source -Bpath/to/build
```

`path/to/source` is the path to the source folder (which contains CMakeLists.txt), and
`path/to/build` is the path to the build folder. Don't add a space between the paths and
the tags.

Go to the build folder and run `make` to make the project.

Now, you can run the executables that are created.

*Alternatively, you could use [CLion](https://www.jetbrains.com/clion/) or
[CodeBlocks](http://www.codeblocks.org/) to open the project.*

## Running the tests

You can add another test file in the tests folder and add it to CMakeLists.txt (read the
[tutorial](https://cmake.org/cmake-tutorial/) to know how) and make the project, or you
can run one of the existing tests.

## Examples

```c++
// These are some random libraries that I've made up
#include "randomMotor.h"
#include "randomSensor.h"

#include "PID-controller.h"

#define SET_POINT 0
#define CLAMPING_LIMIT 1024
#define CUT_OFF_FREQUENCY 1024

randomLib::Motor myMotor(1);
randomLib::Sensor mySpeedSensor(2);
PID::kpid_t kpid{2000, 250, 125};
PID::PID pid(SET_POINT, kpid, CLAMPING_LIMIT, CUT_OFF_FREQUENCY);

int main() {
  while (true) {
    double sensorValue = mySensor.read();
    double pidOutput = PID.next(sensorValue);
    myMotor.write(pidOutput);
  }
}
```

## Built with
 * [LowPassFilter](https://github.com/overlord1123/LowPassFilter)
 * [CLion](https://www.jetbrains.com/clion/)
 
## Authors
 
 * **Tiger Yu** - *Initial work* - [tigeryu8900](../../..)
 
 See also the list of [contributors](../../graphs/contributors) who participated in this project. (only one so far)
