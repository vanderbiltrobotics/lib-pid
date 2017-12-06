#include "pid/pid.h"

PID::PID()
{
  kp_ = ki_ = kd_ = derivator_ = integrator_ = integrator_max_ = integrator_min_ = set_point_ = output_max_ = output_min_ = 0;
  isLimited_ = false;
}

PID::PID(double p, 
	 double i, 
	 double d, 
	 double derivator, 
	 double integrator,
	 double integrator_max,
	 double integrator_min) {
  kp_ = p;
  ki_ = i;
  kd_ = d;
  derivator_ = derivator;
  integrator_ = integrator;
  integrator_max_ = integrator_max;
  integrator_min_ = integrator_min;
  output_max_ = 0;
  output_min_ = 0;
  isLimited_ = false;
}

PID&
PID::operator=(const PID& rhs) {
  if (this == &rhs)
    return *this;
  kp_ = rhs.kp_;
  ki_ = rhs.ki_;
  kd_ = rhs.kd_;
  set_point_ = rhs.set_point_;
  derivator_ = rhs.derivator_;
  integrator_ = rhs.integrator_;
  integrator_max_ = rhs.integrator_max_;
  integrator_min_ = rhs.integrator_min_;
  output_min_ = rhs.output_min_;
  output_max_ = rhs.output_max_;
  isLimited_ = rhs.isLimited_;

  return *this;
}


