#include <nlopt.hpp>
#include <vector>
#include <stan/math.hpp>
#include <Eigen/Dense>

class objfunc{
public:
  template <typename T>
  T operator()(const Eigen::Matrix<T,Eigen::Dynamic, 1> &x) const{
    T lp=0;
    Eigen::Map<const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>> v(x.data(),x.size()/2,2);
    Eigen::MatrixXd a(2,2);
    a<<10,0,-10,0;
    /* lp+=10+(a(0,0)*v.transpose()*v).norm(); */
    lp+=(a.cast<T>()*v).norm();
    return lp;
  }
};

class CC{
 public:
  template <typename T>
    T operator()(const Eigen::Matrix<T,Eigen::Dynamic, 1> &x) const{
    Eigen::Map<const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>> v(x.data(),x.size()/2,2);
    T lp=0;
    lp+=10-(v.transpose()*v).norm();
    return lp;
  }
};
/* class constraint{ */
/* public: */
/*   template <typename T> */
/*   T operator()(const Eigen::Matrix<T,Eigen::Dynamic, 1> &x) const{ */
/*     Eigen::Map<const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>> v(x.data(),x.size()/2,2); */
/*     T lp=0; */
/*     lp+=5-v.transpose()*v; */
/*     return lp; */
/*   } */
/* }; */

namespace NumOpt{
  double Functor(const std::vector<double> &x, std::vector<double> &grad, void *data);
  using Eigen::Matrix;
  using Eigen::Dynamic;
  /* template <typename T> */
  /* double Functor(const std::vector<double> &x, std::vector<double> &grad, void *func) { */
  /*   T& functor= reinterpret_cast<T&>(func); */
  /*   Matrix<double,Dynamic, 1> mX=Eigen::Map<const Matrix<double,Dynamic, 1>>(&x[0],x.size(),1); */
  /*   Matrix<double, Dynamic, 1> grad_fx; */
  /*   double fx; */
  /*   stan::math::gradient(functor, mX, fx, grad_fx); */
  /*   if (!grad.empty()) { */
  /*     grad=std::vector<double>(grad_fx.data(),grad_fx.data()+grad_fx.size()); */
  /*   } */
  /*   return functor(mX); */
  /* } */

  /* class Opt{ */
  /* public: */
  /*   Opt(); */
  /*   Opt(nlopt::algorithm algo,uint n); */
  /*   template <typename T> */
  /*   void set_min_objective(T func){ */
  /*     mOpt->set_min_objective(Functor<T>, &func); */
  /*   } */
  /*   template <typename T> */
  /*   void set_max_objective(T func){ */
  /*     mOpt->set_max_objective(Functor<T>, &func); */
  /*   } */
  /*   template<typename T> */
  /*   void add_equality_constraint(T func, double tol) { */
  /*     mOpt->add_equality_constraint(Functor<T>, &func, tol); */
  /*   } */
  /*   template<typename T> */
  /*   void add_inequality_constraint(T func, double tol) { */
  /*     mOpt->add_inequality_constraint(Functor<T>, &func, tol); */
  /*   } */
  /*   void set_xtol_rel(double tol); */
  /*   void set_lower_bounds(const std::vector<double> &lb); */
  /*   void set_upper_bounds(const std::vector<double> &ub); */
  /*   const std::shared_ptr<nlopt::opt> &getOpt() const; */
  /* private: */
  /*   std::shared_ptr<nlopt::opt> mOpt; */
  /* }; */
}
