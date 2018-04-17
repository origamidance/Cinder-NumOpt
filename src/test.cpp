#include <iomanip>
#include <iostream>
#include <math.h>
#include <nlopt.hpp>
#include <vector>
#include <stan/math.hpp>
#include <Eigen/Dense>

// typedef struct {
//   double a, b;
// } my_constraint_data;

// double myfunc(const std::vector<double> &x, std::vector<double> &grad,
//               void *my_func_data) {
//   if (!grad.empty()) {
//     grad[0] = 0.0;
//     grad[1] = 0.5 / sqrt(x[1]);
//   }
//   return sqrt(x[1]);
// }
// double myconstraint(unsigned n, const double *x, double *grad, void *data)
// {
//   my_constraint_data *d = (my_constraint_data *) data;
//   double a = d->a, b = d->b;
//   if (grad) {
//     grad[0] = 3 * a * (a*x[0] + b) * (a*x[0] + b);
//     grad[1] = -1.0;
//   }
//   return ((a*x[0] + b) * (a*x[0] + b) * (a*x[0] + b) - x[1]);
//  }

// int main() {

//   std::vector<double> lb(2);
//   lb[0] = -HUGE_VAL;
//   lb[1] = 0;

//   nlopt::opt opt(nlopt::LD_MMA, 2);
//   opt.set_lower_bounds(lb);
//   opt.set_min_objective(myfunc, NULL);
//   my_constraint_data data[2] = {{2, 0}, {-1, 1}};
//   opt.add_inequality_constraint(myconstraint, &data[0], 1e-8);
//   opt.add_inequality_constraint(myconstraint, &data[1], 1e-8);
//   opt.set_xtol_rel(1e-4);
//   std::vector<double> x(2);
//   x[0] = 1.234;
//   x[1] = 5.678;
//   double minf;
//   try {
//     nlopt::result result = opt.optimize(x, minf);
//     std::cout << "found minimum at f(" << x[0] << "," << x[1]
//               << ") = " << std::setprecision(10) << minf << std::endl;
//   } catch (std::exception &e) {
//     std::cout << "nlopt failed: " << e.what() << std::endl;
//   }
//   return 0;
// }
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
struct objfunc_1{
  template <typename T>
  T operator()(const Matrix<T,Dynamic, 1> &x) const{
    T lp=0;
    lp+=(x*x.transpose()).diagonal().norm();
    return lp;
  }
  double getFunc(const std::vector<double> &x, std::vector<double> &grad,
                 void *my_func_data){
    if (!grad.empty()) {
      grad[0] = 0.0;
      grad[1] = 0.5 / sqrt(x[1]);
    }
    return sqrt(x[1]);
  }
};

struct constraint_1{
  template <typename T>
  T operator()(const Matrix<T,Dynamic, 1> &x) const{
    T lp=0;
    lp+=(x*x.transpose()).diagonal().norm();
    return lp;
  }
  double getFunc(const std::vector<double> &x, std::vector<double> &grad,
                 void *my_func_data){
    if (!grad.empty()) {
      grad[0] = 0.0;
      grad[1] = 0.5 / sqrt(x[1]);
    }
    return sqrt(x[1]);
  }
};

int main(){
  // Matrix<double, Dynamic, 1> y(3);
  // y << 1.3, 2.7, -1.9;
  // normal_ll f(y);
  // Matrix<double, Dynamic, 1> x(2);
  // x << 1.3, 2.9;
  // double fx;
  // Matrix<double, Dynamic, 1> grad_fx;
  // stan::math::gradient(f, x, fx, grad_fx);
  // std::cout<<"fx="<<fx<<"\n";
  // std::cout<<"grad_fx="<<grad_fx.transpose()<<"\n";
  // std::cout<<"testf="<<f(x)<<"\n";

  std::vector<double> lb(2);
  lb[0] = -HUGE_VAL;
  lb[1] = 0;

  objfunc_1 func;
  constraint_1 cons;

  nlopt::opt opt(nlopt::LD_MMA, 2);
  opt.set_lower_bounds(lb);
  opt.set_min_objective(func.&getFunc, NULL);
  // my_constraint_data data[2] = {{2, 0}, {-1, 1}};
  opt.add_inequality_constraint(cons.&getFunc, NULL, 1e-8);
  opt.add_inequality_constraint(cons.&getFunc, NULL, 1e-8);
  opt.set_xtol_rel(1e-4);
  std::vector<double> x(2);
  x[0] = 1.234;
  x[1] = 5.678;
  double minf;
  try {
    nlopt::result result = opt.optimize(x, minf);
    std::cout << "found minimum at f(" << x[0] << "," << x[1]
              << ") = " << std::setprecision(10) << minf << std::endl;
  } catch (std::exception &e) {
    std::cout << "nlopt failed: " << e.what() << std::endl;
  }
  return 0;
}
