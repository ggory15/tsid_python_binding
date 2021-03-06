#include "tsid/bindings/python/tasks/task-joint-posture.hpp"
#include "tsid/bindings/python/tasks/expose-tasks.hpp"

namespace tsid
{
  namespace python
  {
    void exposeTaskJointPosture()
    {
      TaskJointPosturePythonVisitor<tsid::tasks::TaskJointPosture>::expose("TaskJointPosture");
    }
  }
}
