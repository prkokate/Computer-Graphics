#include <stdio.h>
#include <GL/glut.h>

double xmin = 50, ymin = 50, xmax = 100, ymax = 100;       // Window boundaries
double xvmin = 150, yvmin = 150, xvmax = 400, yvmax = 400; // Viewport boundaries

// bit codes for the right, left, top, & bottom   (tbrl)
const int RIGHT = 2;
const int LEFT = 1;
const int TOP = 8;
const int BOTTOM = 4;

void putPixel(float x, float y)
{
    // glColor3f(1, 1, 1);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}

// used to compute bit codes of a point
int ComputeOutCode(double x, double y)
{
    int code = 0;
    if (y > ymax) // above the clip window
        code |= TOP;
    else if (y < ymin) // below the clip window
        code |= BOTTOM;
    if (x > xmax) // to the right of clip window
        code |= RIGHT;
    else if (x < xmin) // to the left of clip window
        code |= LEFT;
    return code;
}




void clip(double x0, double y0, double x1, double y1)
{
    // Outcodes for P0, P1, and whatever point lies outside the clip rectangle
    int outcode0, outcode1, outcodeOut;
    bool accept = false, done = false;   //accept indicates line is accepted for clipping & done indicates clipping is done
    // compute outcodes
    outcode0 = ComputeOutCode(x0, y0);
    outcode1 = ComputeOutCode(x1, y1);
    do
    {
        if (!(outcode0 | outcode1)) // logical or is 0 Trivially accept & exit
        {
            accept = true;
            done = true;
        }
        else if (outcode0 & outcode1)
            // logical and is not 0. Trivially reject and exit
            done = true;
        else
        { // failed both tests, so calculate the line segment to clip
            // from an outside point to an intersection with clip edge
            double x, y;
            // At least one endpoint is outside the clip rectangle; pick it.
            outcodeOut = outcode0 ? outcode0 : outcode1;   // outcodeOut is assigned the value of outcode0 if outcode0 is non-zero (true), otherwise it is assigned the value of outcode1.
            // Now find the intersection point;
            // use formulas y = y0 + slope * (x - x0),
            //  x = x0 + (1/slope)* (y - y0)
            if (outcodeOut & TOP)
                // point is above the clip rectangle
            {
                x = x1 - (y1 - ymax) * (x1 - x0) / (y1 - y0);
                y = ymax;
            }
            else if (outcodeOut & BOTTOM)
                // point is below the clip rectangle
            {
                x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
                y = ymin;
            }
            else if (outcodeOut & RIGHT)
                // point is to the right of clip rectangle
            {
                y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
                x = xmax;
            }
            else
                // point is to the left of clip rectangle
            {
                y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
                x = xmin;
            }
            // Now we move outside point to intersection point to clip
            // and get ready for next pass.
            if (outcodeOut == outcode0)
            {
                x0 = x;
                y0 = y;
                outcode0 = ComputeOutCode(x0, y0);
            }
            else
            {
                x1 = x;
                y1 = y;
                outcode1 = ComputeOutCode(x1, y1);
            }
        }
    } while (!done);
    if (accept)
    {                                                // Window to viewport mappings
        double sx = 5; // Scale parameters
        double sy = 5;
        double vx0 = xvmin + (x0 - xmin) * sx;
        double vy0 = yvmin + (y0 - ymin) * sy;
        double vx1 = xvmin + (x1 - xmin) * sx;
        double vy1 = yvmin + (y1 - ymin) * sy; // draw a red colored viewport
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINE_LOOP);
        glVertex2f(xvmin, yvmin);
        glVertex2f(xvmax, yvmin);
        glVertex2f(xvmax, yvmax);
        glVertex2f(xvmin, yvmax);
        glEnd();
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_LINE_LOOP);
        glVertex2f(xmin, ymin);
        glVertex2f(xmax, ymin);
        glVertex2f(xmax, ymax);
        glVertex2f(xmin, ymax);
        glEnd();

        glColor3f(1.0, 1.0, 0.0); // draw blue colored clipped line
        //cliped drawing aatla
        glBegin(GL_LINES);
        glVertex2d(vx0, vy0);
        glVertex2d(vx1, vy1);
        glEnd();
    }
}
// Compute the bit code for a point (x, y) using the clip rectangle
// bounded diagonally by (xmin, ymin), and (xmax, ymax)
void display()
{
    double x0 = 30, y0 = 20, x1 = 80, y1 = 120;
    double x2 = 80, y2 = 20, x3 = 100, y3 = 80;
    double x4 = 10, y4 = 80, x5 = 40, y5 = 80;
    double x6 = 40, y6 = 80, x7 = 80, y7 = 120;
    double x8 = 130, y8 = 50, x9 = 60, y9 = 120;
    glClear(GL_COLOR_BUFFER_BIT); // draw the line with red color
    glColor3f(1.0, 0.0, 0.0);     // bres(120,20,340,250);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2d(x0, y0);
    glVertex2d(x1, y1);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(x2, y2);
    glVertex2d(x3, y3);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(x4, y4);
    glVertex2d(x5, y5);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(x6, y6);
    glVertex2d(x7, y7);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(x8, y8);
    glVertex2d(x9, y9);
    glEnd();

    // draw a blue colored window

    clip(x0, y0, x1, y1);
    clip(x2, y2, x3, y3);
    clip(x4, y4, x5, y5);
    clip(x6, y6, x7, y7);
    clip(x8, y8, x9, y9);
    glFlush();
}
void myinit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    // glPointSize(1.0);
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Cohen Suderland Line Clipping Algorithm");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
}