# lib-pid
simple pid class ready to import as a source library in ROSMOD

# source library setup

1. In this github repo navigate to [releases](https://github.com/rosmod/lib-pid/releases), right click on `pid.zip` (not the source code zip!) and select `Copy link address'
2. In a rosmod project, drag in a new source library to the software model
3. Paste the link in the url attribute
4. Name the source library `pid`


# Usage

1. Drag the library into the `set editor` of any component that uses it
2. In the forwards section of the component add `#include "pid/pid.h`


# API

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
```
