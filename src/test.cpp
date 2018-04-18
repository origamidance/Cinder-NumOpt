#include <iostream>
#include <math.h>
#include <nlopt.hpp>
#include <vector>
#include <stan/math.hpp>
#include <Eigen/Dense>

using Eigen::Matrix;
using Eigen::Dynamic;
struct normal_ll {
  const Matrix<double, Dynamic, 1> y_;
  normal_ll(const Matrix<double, Dynamic, 1>& y) : y_(y) { }
  template <typename T>
  T operator()(const Matrix<T, Dynamic, 1>& theta) const {
    T mu = theta[0];
    T sigma = theta[1];
    T lp = 0;
    lp+=y_[0]*(theta*theta.transpose()).diagonal().norm();
    return lp;
  }
};

class objfunc{
public:
  template <typename T>
  T operator()(const Matrix<T,Dynamic, 1> &x) const{
    T lp=0;
    lp+=x.transpose()*x;
    return lp;
  }
};

class constraint{
public:
  template <typename T>
  T operator()(const Matrix<T,Dynamic, 1> &x) const{
    T lp=0;
    lp+=x.norm()-10;
    return lp;
  }
};

template <typename T>
double myfunc(const std::vector<double> &x, std::vector<double> &grad, void *func) {
  T& functor= reinterpret_cast<T&>(func);
  // objfunc& functor= reinterpret_cast<objfunc&>(func);
  // objfunc* functor=func;
  Matrix<double,Dynamic, 1> mX=Eigen::Map<const Matrix<double,Dynamic, 1>>(&x[0],x.size(),1);
  Matrix<double, Dynamic, 1> grad_fx;
  double fx;
  stan::math::gradient(functor, mX, fx, grad_fx);
  if (!grad.empty()) {
    grad=std::vector<double>(grad_fx.data(),grad_fx.data()+grad_fx.size());
  }
  return functor(mX);
}

int main(){

  std::vector<double> lb(2);
  lb[0] = -HUGE_VAL;
  lb[1] = -HUGE_VAL;
  objfunc testfunc;
  constraint testcons;

  // nlopt::opt opt(nlopt::LD_LBFGS,2);
  // nlopt::opt opt(nlopt::LD_MMA, 2);
  nlopt::opt opt(nlopt::LD_SLSQP,2);
  // opt.set_lower_bounds(lb);
  opt.set_max_objective(myfunc<decltype(testfunc)>,&testfunc);
  // // my_constraint_data data[2] = {{2, 0}, {-1, 1}};
  opt.add_equality_constraint(myfunc<decltype(testcons)>, &testcons, 1e-8);
  // opt.add_equality_constraint(mycons, &testcons, 1e-8);
  // opt.add_inequality_constraint(mycons,&testcons, 1e-8);
  // opt.add_inequality_constraint(myfunc,&testfunc, 1e-8);
  opt.set_xtol_rel(1e-4);
  std::vector<double> x(2);
  x[0] = 1;
  x[1] = 1;
  std::vector<double> y(2);
  double minf;
  try {
    nlopt::result result = opt.optimize(x, minf);
    std::cout << "found minimum at f(" << x[0] << "," << x[1]
              << ") = " << minf << std::endl;
    std::cout<<"func value="<<myfunc<decltype(testfunc)>(x,y,&testfunc)<<"\n";
    std::cout<<"cons value="<<myfunc<decltype(testcons)>(x,y,&testcons)<<"\n";
  } catch (std::exception &e) {
    std::cout << "nlopt failed: " << e.what() << std::endl;
  }

  return 0;
}
