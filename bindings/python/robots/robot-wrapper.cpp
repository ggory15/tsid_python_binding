
#include "tsid/bindings/python/robots/expose-robots.hpp"
#include "tsid/bindings/python/robots/robot-wrapper.hpp"

namespace tsid
{
  namespace python
  {
    void exposeRobotWrapper()
    {
      RobotPythonVisitor<tsid::robots::RobotWrapper>::expose("RobotWrapper");
    }
  }
}
