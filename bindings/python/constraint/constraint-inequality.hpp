#ifndef __tsid_python_constriant_inequality_hpp__
#define __tsid_python_constriant_inequality_hpp__

#include <boost/python.hpp>
#include <string>
#include <eigenpy/eigenpy.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include "tsid/math/constraint-inequality.hpp"

namespace tsid
{
  namespace python
  {    
    namespace bp = boost::python;
    
    template<typename ConstraintInequality>
    struct ConstraintIneqPythonVisitor
    : public boost::python::def_visitor< ConstraintIneqPythonVisitor<ConstraintInequality> >
    {
      EIGEN_MAKE_ALIGNED_OPERATOR_NEW
      typedef double Scalar;
      typedef Eigen::Matrix<Scalar,Eigen::Dynamic,1> Vector;
      typedef Eigen::Ref<Vector>              RefVector;
      typedef const Eigen::Ref<const Vector>  ConstRefVector;

      template<class PyClass>     

      void visit(PyClass& cl) const
      {
        cl
        .def(bp::init<std::string>((bp::arg("name")), "Default constructor with name."))
        .def(bp::init<std::string, unsigned int, unsigned int>((bp::arg("name"), bp::arg("row"), bp::arg("col")), "Default constructor with name and size."))
        .def(bp::init<std::string, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd>((bp::arg("name"), bp::arg("A"), bp::arg("lb"), bp::arg("ub")), "Default constructor with name and constraint."))
        
        .add_property("rows", &ConstraintInequality::rows)
        .add_property("cols", &ConstraintInequality::cols)
        .def("resize",&ConstraintInequality::resize, (bp::arg("r"), bp::arg("c")),"Resize constraint size.")
        
        .add_property("isEquality", &ConstraintInequality::isEquality)
        .add_property("isInequality", &ConstraintInequality::isInequality)
        .add_property("isBound", &ConstraintInequality::isBound)
        
        .add_property("matrix", &ConstraintIneqPythonVisitor::matrix)
        .add_property("vector", &ConstraintIneqPythonVisitor::vector)
        .add_property("lowerBound", &ConstraintIneqPythonVisitor::lowerBound)
        .add_property("upperBound", &ConstraintIneqPythonVisitor::upperBound)

        .def("setMatrix", (bool (ConstraintInequality::*)(const Eigen::MatrixXd &) const) &ConstraintInequality::setMatrix, bp::args("matrix"), "Set Matrix")
        .def("setVector", (bool (ConstraintInequality::*)(const Eigen::VectorXd &) const) &ConstraintInequality::setVector, bp::args("vector"), "Set Vector")
        .def("setLowerBound", (bool (ConstraintInequality::*)(const Eigen::VectorXd &) const) &ConstraintInequality::setLowerBound, bp::args("lb"), "Set LowerBound")
        .def("setUpperBound", (bool (ConstraintInequality::*)(const Eigen::VectorXd &) const) &ConstraintInequality::setUpperBound, bp::args("ub"), "Set UpperBound")
        ;
      }
      static Eigen::MatrixXd matrix (const ConstraintInequality & self) {return self.matrix();}
      static Eigen::VectorXd vector (const ConstraintInequality & self) {return self.vector();}
      static Eigen::VectorXd lowerBound (const ConstraintInequality & self) {return self.lowerBound();}
      static Eigen::VectorXd upperBound (const ConstraintInequality & self) {return self.upperBound();}
      
      static void expose(const std::string & class_name)
      {
        std::string doc = "Constraint Inequality info.";
        bp::class_<ConstraintInequality>(class_name.c_str(),
                          doc.c_str(),
                          bp::no_init)
        .def(ConstraintIneqPythonVisitor<ConstraintInequality>());
      }
    };
  }
}


#endif // ifndef __tsid_python_constriant_inequality_hpp__