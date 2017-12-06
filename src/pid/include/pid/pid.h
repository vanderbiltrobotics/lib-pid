#ifndef PID_H
#define PID_H

class PID
{
 public:
  PID();
  ~PID() {}
  PID(double p, 
      double i, 
      double d, 
      double derivator, 
      double integrator,
      double integrator_max,
      double integrator_min);
  
  PID& operator=(const PID& rhs);
  
  double update(double current_value)
  {
    double error = set_point_ - current_value;
    integrator_ += error;
    //clamp integrator_ value between integrator_max_ and integrator_min_
    double i_value = ki_ * (integrator_ > integrator_max_ ? integrator_max_ : (integrator_ < integrator_min_ ? integrator_min_ : integrator_));
    double pid = kp_*error + kd_*(error-derivator_) + i_value;
    if(isLimited_)
      {
        //clamp pid value between output_max_ and output_min_
        pid = pid > output_max_ ? output_max_ : (pid < output_min_ ? output_min_ : pid);
      }
    derivator_ = error;
    return pid;  
  };
  
  void setPoint(double set_point)
  {
    set_point_ = set_point;
  };
  
  void setIntegrator(double integrator)
  {
    integrator_ = integrator;
  };
  
  void setIntegratorMax(double max)
  {
    integrator_max_ = max;
  };
  
  void setIntegratorMin(double min)
  {
    integrator_min_ = min;
  };
  
  void setDerivator(double derivator)
  {
    derivator_ = derivator;
  };
  
  void setKp(double kp)
  {
    kp_ = kp;
  };
  
  void setKi(double ki)
  {
    ki_ = ki;
  };
  
  void setKd(double kd)
  {
    kd_ = kd;
  };
  
  void limitOutput(double min, double max)
  {
    isLimited_ = true;
    output_min_ = min;
    output_max_ = max;
  };

  void delimitOutput()
  {
    isLimited_ = false;
  };
  
  double getPoint()
  {
    return set_point_;
  };
  
  double getIntegrator()
  {
    return integrator_;
  };
  
  double getDerivator()
  {
    return derivator_;
  };
  
  double getOutputMin()
  {
    return output_min_;
  };
  
  double getOutputMax()
  {
    return output_max_;
  };

  bool outputIsLimited()
  {
    return isLimited_;
  };
  
 private:
  double kp_;
  double ki_;
  double kd_;
  double derivator_;
  double integrator_;
  double integrator_min_;
  double integrator_max_;
  double set_point_;
  double output_max_;
  double output_min_;
  bool isLimited_;
};

#endif
