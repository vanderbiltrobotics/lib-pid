class libpid
{
 public:
  libpid()
  {
    kp_ = ki_ = kd_ = derivator_ = integrator_ = integrator_max_ = integrator_min_ = set_point_ = 0;
  }

  libpid(double p,
	 double i,
	 double d,
	 double derivator,
	 double integrator,
	 double integrator_max,
   double integrator_min)
   {
    kp_ = p;
    ki_ = i;
    kd_ = d;
    derivator_ = derivator;
    integrator_ = integrator;
    integrator_max_ = integrator_max;
    integrator_min_ = integrator_min;
  }

  double update(double current_value){
    double error = set_point_ - current_value;
    double p_value = kp_ * error;
    double d_value = kd_ * (error - derivator_);
    derivator_ = error;
    integrator_ = integrator_ + error;
    if (integrator_ > integrator_max_)
      integrator_ = integrator_max_;
    else if (integrator_ < integrator_min_)
      integrator_ = integrator_min_;
    double i_value = integrator_ * ki_;
    double pid = p_value + i_value + d_value;
    return pid;
  }

  void setPoint(double set_point){
    set_point_ = set_point;
  }

  void setIntegrator(double integrator){
    integrator_ = integrator;
  }

  void setIntegratorMax(double max){
    integrator_max_ = max;
  }
  
  void setIntegratorMin(double min) {
    integrator_min_ = min;
  }

  void setKp(double kp){
    kp_ = (kp >= 0) ? kp : 0;
  }

  void setKi(double ki){
    ki_ = (ki >= 0) ? ki : 0;
  }

  void setKd(double kd){
    kd_ = (kd >= 0) ? kd : 0;
  }
  double getKp(){
    return kp_;
  }
  double getKd(){
    return kd_;
  }
  double getKi(){
    return ki_;
  }

  double getPoint(){
    return set_point_;
  }

  double getIntegrator(){
    return integrator_;
  }
  double getDerivator(){
    return derivator_;
  }

 private:
  double kp_;
  double ki_;
  double kd_;
  double derivator_;
  double integrator_;
  double integrator_min_;
  double integrator_max_;
  double set_point_;
};
