import sys
import math

radius = float(sys.argv[1])


def shpereEquation():
    theta = 0

    while(theta < 2 * math.pi):

        x = radius * math.cos(theta)
        y = radius * math.sin(theta)
        theta = theta + math.pi/5;

        print('<point x="%f" y="0" z="%f"/>' % (x,y))



shpereEquation()

