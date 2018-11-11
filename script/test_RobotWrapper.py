import pinocchio as se3
import libtsid_pywrap as tsid
import numpy as np

print ""
print "Test RobotWrapper"
print ""


path = '/home/ggory15/ongoing_work/tsid/models/romeo'
urdf = path + '/urdf/romeo.urdf'
vector = se3.StdVec_StdString()
vector.extend(item for item in path)

robot = tsid.RobotWrapper(urdf, vector, se3.JointModelFreeFlyer(), False)
model = robot.model()
lb = model.lowerPositionLimit
lb[0:3] = -10.0*np.matrix(np.ones(3)).transpose()
lb[3:7] = -1.0*np.matrix(np.ones(4)).transpose()

ub = model.upperPositionLimit
ub[0:3] = 10.0*np.matrix(np.ones(3)).transpose()
ub[3:7] = 1.0*np.matrix(np.ones(4)).transpose()

q = se3.randomConfiguration(robot.model(), lb, ub)
print q.transpose()

data = robot.data()
v = np.matrix(np.ones(robot.nv)).transpose()
robot.computeAllTerms(data, q, v)
print robot.com(data)

print "All test is done"
