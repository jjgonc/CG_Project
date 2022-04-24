from cmath import sqrt
import sys
import math



def shpereEquation():
    theta = 0
    radius = float(sys.argv[1])

    while(theta < 2 * math.pi):

        x = radius * math.cos(theta)
        y = radius * math.sin(theta)
        theta = theta + math.pi/5;

        print('<point x="%f" y="0" z="%f"/>' % (x,y))

shpereEquation()


def elipseEquation():

    a = float(sys.argv[1])
    b = float(sys.argv[2])


    increment = (2 * a)/50
    alinha = -a

    while(alinha >= -a and alinha < a):

        x = alinha
        y = math.sqrt( (1 - pow(x,2)/pow(a,2)) * pow(b,2))
        alinha += increment

        print('<point x="%f" y="0" z="%f"/>' % (x,y))


    alinha = a


    while(alinha > -a and alinha <= a):

        x = alinha
        y = - math.sqrt( (1 - pow(x,2)/pow(a,2)) * pow(b,2))
        alinha -= increment

        print('<point x="%f" y="0" z="%f"/>' % (x,y))
        

    
#elipseEquation()

