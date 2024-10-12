#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

struct pixel {
    float r, g, b;
};
pixel fclr;
pixel bclr;
pixel o;
pixel n;

void initialize(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    // gluOrtho2D(l,r,b,t)
    gluOrtho2D(0, 500, 0, 500);
}

void displayPoint(int x, int y) {
    glColor3f(0, 0, 0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}


float x01, x2, y01, y2;
void SimpleLine(float x1, float y1, float x2, float y2) {
    float step;

    float dx = x2 - x1;
    float dy = y2 - y1;

    if (abs(dx) > abs(dy)) {
        step = abs(dx);
    }
    else step = abs(dy);

    float Xinc = dx / (float)step;
    float Yinc = dy / (float)step;
    float x = x1;
    float y = y1;

    for (int i = 0; i <= step;i++) {
        displayPoint(x, y);
        x = x + Xinc;
        y = y + Yinc;
    }
    glFlush();
}
int r = 50;
void circle(int xc, int yc) {
    int x = 0;
    int y = r;
    float d = 3 - 2 * r;
    while (x <= y) {
        glColor3f(0, 0, 0);
        glBegin(GL_POINTS);
        glVertex2i(xc + x, yc + y);
        // glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc + y);
        // glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        // glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc + x);
        // glVertex2i(xc - y, yc - x);
        glEnd();

        if (d < 0) {
            d += 4 * x + 6;
        }
        else {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}


void circle1(int xc, int yc) {
    int x = 0;
    int y = r;
    float d = 3 - 2 * r;
    while (x <= y) {
        glColor3f(0, 0, 0);
        glBegin(GL_POINTS);
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc + x, yc - y);
        // glVertex2i(xc - x, yc + y);
        // glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc + y, yc - x);
        // glVertex2i(xc - y, yc + x);
        // glVertex2i(xc - y, yc - x);
        glEnd();

        if (d < 0) {
            d += 4 * x + 6;
        }
        else {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}
void circle2(int xc, int yc) {
    int x = 0;
    int y = r;
    float d = 3 - 2 * r;
    while (x <= y) {
        glColor3f(0, 0, 0);
        glBegin(GL_POINTS);
        // glVertex2i(xc + x, yc + y);
        glVertex2i(xc + x, yc - y);
        // glVertex2i(xc - x, yc + y);
        glVertex2i(xc - x, yc - y);
        // glVertex2i(xc + y, yc + x);
        glVertex2i(xc + y, yc - x);
        // glVertex2i(xc - y, yc + x);
        glVertex2i(xc - y, yc - x);
        glEnd();

        if (d < 0) {
            d += 4 * x + 6;
        }
        else {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void circle3(int xc, int yc) {
    int x = 0;
    int y = r;
    float d = 3 - 2 * r;
    while (x <= y) {
        glColor3f(0, 0, 0);
        glBegin(GL_POINTS);
        // glVertex2i(xc + x, yc + y);
        // glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc - x, yc - y);
        // glVertex2i(xc + y, yc + x);
        // glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc - y, yc - x);
        glEnd();

        if (d < 0) {
            d += 4 * x + 6;
        }
        else {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void circle4(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    float d = 3 - 2 * r;
    while (x <= y) {
        glColor3f(0, 0, 0);
        glBegin(GL_POINTS);
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc - y, yc - x);
        glEnd();

        if (d < 0) {
            d += 4 * x + 6;
        }
        else {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}


void boundaryfill(int x, int y) {
    pixel c;
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, &c);
    if ((c.r != bclr.r || c.g != bclr.g || c.b != bclr.b) && (c.r != fclr.r || c.g != fclr.g || c.b != fclr.b))
    {
        glBegin(GL_POINTS);
        glColor3f(fclr.r, fclr.g, fclr.b);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        boundaryfill(x - 1, y);
        boundaryfill(x + 1, y);
        boundaryfill(x, y - 1);
        boundaryfill(x, y + 1);
    }
    glFlush();
}
void floodfill(int x, int y, pixel old, pixel n) {
    pixel c;
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, &c);
    if ((c.r == old.r && c.g == old.g && c.b == old.b))
    {
        glBegin(GL_POINTS);
        glColor3f(n.r, n.g, n.b);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        floodfill(x - 1, y, old, n);
        floodfill(x + 1, y, old, n);
        floodfill(x, y - 1, old, n);
        floodfill(x, y + 1, old, n);
    }
    glFlush();

}
void primitives(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    // circle(250, 300);
    // circle1(300, 250);
    // circle2(250, 200);
    // circle3(200, 250);
    // circle4(250, 250, 100);
    SimpleLine(200, 300, 200, 200);
    SimpleLine(300, 300, 300, 200);
    SimpleLine(200, 200, 300, 200);
    SimpleLine(200, 300, 225, 350);
    SimpleLine(225, 350, 225, 375);
    SimpleLine(225, 375, 275, 375);
    SimpleLine(275, 375, 275, 350);
    SimpleLine(275, 350, 300, 300);
    SimpleLine(225, 350, 275, 350);
    fclr.r = 1.0f;
    fclr.g = 0.0f;
    fclr.b = 0.0f;
    boundaryfill(210, 250);
    // fclr.r = 0.0f;
    // fclr.g = 1.0f;
    // fclr.b = 0.0f;
    // boundaryfill(250, 290);
    // fclr.r = 0.0f;
    // fclr.g = 0.0f;
    // fclr.b = 1.0f;
    // boundaryfill(250, 210);
    // fclr.r = 0.8f;
    // fclr.g = 1.0f;
    // fclr.b = 0.4f;
    // boundaryfill(290, 250);
    // n.r = 0.8f;
    // n.g = 0.2f;
    // n.b = 0.8f;
    // o.r = 1.0;
    // o.g = 1.0;
    // o.b = 1.0;
    // floodfill(250, 310, o, n);
    // fclr.r = 0.2f;
    // fclr.g = 0.0f;
    // fclr.b = 0.5f;
    // boundaryfill(320, 250);

    // fclr.r = 0.2f;
    // fclr.g = 0.9f;
    // fclr.b = 0.5f;
    // boundaryfill(170, 250);

    // fclr.r = 0.4f;
    // fclr.g = 0.3f;
    // fclr.b = 0.5f;
    // boundaryfill(251, 170);


    n.r = 0.8f;
    n.g = 0.2f;
    n.b = 0.8f;
    o.r = 1.0;
    o.g = 1.0;
    o.b = 1.0;
    floodfill(250, 360, o, n);

    // n.r = 0.8f;
    // n.g = 0.2f;
    // n.b = 0.8f;
    // o.r = 1.0;
    // o.g = 1.0;
    // o.b = 1.0;
    // floodfill(170, 250, o, n);

    // n.r = 0.8f;
    // n.g = 0.2f;
    // n.b = 0.8f;
    // o.r = 1.0;
    // o.g = 1.0;
    // o.b = 1.0;
    // floodfill(250, 170, o, n);




}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowPosition(300, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL - FIGURE");
    initialize();
    glutDisplayFunc(primitives);
    glutMainLoop();
    return 0;
}