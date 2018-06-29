[![Build Status](https://travis-ci.com/vanderbiltrobotics/lib-pid.svg?branch=master)](https://travis-ci.com/vanderbiltrobotics/lib-pid)
# lib-pid
simple header only pid class ready to import as a source library in ROSMOD


Install Build Tools
-------------------------

```bash
sudo apt-get install python-catkin-tools
```

Build Library:
-------------

```bash
cd
mkdir catkin_ws #if a workspace does not already exist
cd catkin_ws
git clone https://github.com/rosmod/lib-pid.git src/lib-pid
```

Update Library:
-----------------

```bash
cd ~/catkin_ws
catkin clean pid
cd src/lib-pid
git pull
```

# API

## Include

`include "pid/pid.h"`

## Instantiaion

```c++
PID pidObject();
PID pidObject(Kp, Ki, Kd, 0, 0, i_max, i_min);
```

## Set goal

```c++
// double goal = XXX;
pidObject.setPoint(goal);
```

## get pid output

```c++
// double currentValue = XXX;
double output = pidObject.update(currentValue);
```

## Clamp output

```c++
// double outputMin = XXX;
// double outputMax = XXX;
pidObject.limitOutput(outputMin, outputMax);
double max = pidObject.getOutputMax();
double min = pidObject.getOutputMin();
bool isSet = pidObject.outputIsLimited();
pidObject.delimitOutput();
```
## Set deadzone about setpoint

```c++
// double deadzoneLower = xxx;
// double deadzoneUpper = xxx;
pidObject.setDeadzone(deadzoneLower, deadzoneUpper);
double upper = pidObject.getDeadzoneUpper();
double lower = pidObject.getDeadzoneLower();
bool isSet = pidObject.hasDeadzone();
pidObject.removeDeadzone();
```

# Rosmod source library setup

1. Copy the url of this repo (https://github.com/rosmod/lib-pid)
2. In a rosmod project, drag in a new source library to the software model
3. Paste the link in the url attribute
4. Name the source library `pid`
5  Optionally specify a branch to use in the branch attribute
6. Drag the library into the `set editor` of any component that uses it
7. In the forwards section of the component add `#include "pid/pid.h`
