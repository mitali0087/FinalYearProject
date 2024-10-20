from math import sin, cos, pi
from pylab import *
from lego_robot import *

#theta = 0.0;
# This function takes the old (x, y, heading) pose and the motor ticks
# (ticks_left, ticks_right) and returns the new (x, y, heading).
def filter_step(old_pose, motor_ticks, ticks_to_mm, robot_width):

    # Find out if there is a turn at all.
    
    if motor_ticks[0] == motor_ticks[1]:
        # No turn. Just drive straight.
        #theta = old_pose[2]
        #x = old_pose[0] + motor_ticks[0]*ticks_to_mm*math.cos(theta)
        #y = old_pose[1] + motor_ticks[0]*ticks_to_mm*math.sin(theta)

        dist = motor_ticks[0] * ticks_to_mm
        theta = old_pose[2]
        x = old_pose[0] + dist * cos(theta)
        y = old_pose[1] + dist * sin(theta)
       
        return (x, y, theta)

    else:
        # Turn. Compute alpha, R, etc.

        #alpha = (motor_ticks[1]-motor_ticks[0])*ticks_to_mm/robot_width
        #R = (motor_ticks[0]*ticks_to_mm)/alpha
        #theta = old_pose[2]
        #cx = old_pose[0] - (R + robot_width/2)*math.sin(theta)
        #cy = old_pose[1] + (R + robot_width/2)*math.cos(theta)

        #theta = (old_pose[2] + alpha) % 2*pi

        #x = cx + (R + robot_width/2)*math.sin(theta)
        #y = cy - (R + robot_width/2)*math.cos(theta)

        old_theta = old_pose[2]
        old_x = old_pose[0]
        old_y = old_pose[1]

        l = motor_ticks[0] * ticks_to_mm
        r = motor_ticks[1] * ticks_to_mm
        alpha = (r - l) / robot_width
        R = l / alpha
        new_theta = (old_theta + alpha) % (2*pi)
        new_x = old_x + (R + robot_width/2.0) * (sin(new_theta) - sin(old_theta))
        new_y = old_y + (R + robot_width/2.0) * (-cos(new_theta) + cos(old_theta))



        
        return (new_x, new_y, new_theta)

if __name__ == '__main__':
    # Empirically derived conversion from ticks to mm.
    ticks_to_mm = 5.44

    # Measured width of the robot (wheel gauge), in mm.
    robot_width = 160.0

    # Our Code STarts 
    for a in range(2):
        file_name = "encoder_readings" + str(a + 1) + ".txt"
        f = open(file_name,"r")
        right_list = []
        left_list = []

        right = []
        left = []
        for l in f:
            sp = l.split()
            #print sp
            left_list.append(int(sp[0]))
            right_list.append(int(sp[1]))

        #print right_list

        right = [right_list[i+1]-right_list[i] for i in range(len(right_list)-1)]
        left = [left_list[i+1]-left_list[i] for i in range(len(left_list)-1)]
     
        #print right
        #print left

        ticks = []

        for i in range(len(right)):
            ticks.append([right[i] , left[i]])
        #Our Code Ends  

        

        # Start at origin (0,0), looking along x axis (alpha = 0).
        pose = (0.0, 0.0, 0.0)

        # Loop over all motor tick records generate filtered position list.
        filtered = []
        for i in ticks:
            pose = filter_step(pose, i, ticks_to_mm, robot_width)
            filtered.append(pose)

        # Draw result.
        for pose in filtered:
            print pose
            l = plot([p[0] for p in filtered], [p[1] for p in filtered], 'bo')
            setp(l, markersize=30)
            #l.hold(True)
    show()
