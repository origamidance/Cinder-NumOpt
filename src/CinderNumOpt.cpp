#include <CinderNumOpt.h>
#include <iostream>
#include <lib/boost_1.66.0/boost/serialization/shared_ptr.hpp>
#include <math.h>

namespace NumOpt {
Opt::Opt() { mOpt = std::make_shared<nlopt::opt>(); }
Opt::Opt(nlopt::algorithm algo, uint n) {
  mOpt = std::make_shared<nlopt::opt>(algo, n);
}
const std::shared_ptr<nlopt::opt> &Opt::getOpt() const { return mOpt; }
void Opt::set_xtol_rel(double tol) { mOpt->set_xtol_rel(tol); }
  void Opt::set_lower_bounds(const std::vector<double> &lb) { mOpt->set_lower_bounds(lb); }
  void Opt::set_upper_bounds(const std::vector<double> &ub) { mOpt->set_upper_bounds(ub); }
} // namespace NumOpt

// int main(){

//   std::vector<double> lb(2);
//   lb[0] = -HUGE_VAL;
//   lb[1] = -HUGE_VAL;
//   objfunc testfunc;
//   constraint testcons;

//   // nlopt::opt opt(nlopt::LD_LBFGS,2);
//   // nlopt::opt opt(nlopt::LD_MMA, 2);
//   nlopt::opt opt(nlopt::LD_SLSQP,2);
//   // opt.set_lower_bounds(lb);
//   opt.set_max_objective(myfunc<decltype(testfunc)>,&testfunc);
//   // // my_constraint_data data[2] = {{2, 0}, {-1, 1}};
//   opt.add_equality_constraint(myfunc<decltype(testcons)>, &testcons, 1e-8);
//   // opt.add_equality_constraint(mycons, &testcons, 1e-8);
//   // opt.add_inequality_constraint(mycons,&testcons, 1e-8);
//   // opt.add_inequality_constraint(myfunc,&testfunc, 1e-8);
//   opt.set_xtol_rel(1e-4);
//   std::vector<double> x(2);
//   x[0] = 1;
//   x[1] = 1;
//   std::vector<double> y(2);
//   double minf;
//   try {
//     nlopt::result result = opt.optimize(x, minf);
//     std::cout << "found minimum at f(" << x[0] << "," << x[1]
//               << ") = " << minf << std::endl;
//     std::cout<<"func
//     value="<<myfunc<decltype(testfunc)>(x,y,&testfunc)<<"\n";
//     std::cout<<"cons
//     value="<<myfunc<decltype(testcons)>(x,y,&testcons)<<"\n";
//   } catch (std::exception &e) {
//     std::cout << "nlopt failed: " << e.what() << std::endl;
//   }

//   return 0;
// }
