#include<GL/glut.h>
#include<GL/gl.h>

void setPixel(int x, int y) {
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void bresenhamCircle(int xc, int yc, int r) {

    int d = 3 - 2 * r;
    int x = 0;
    int y = r;

    while (x <= y) {
        setPixel(xc + x, yc + y);
        setPixel(xc + y, yc + x);
        setPixel(xc - x, yc - y);
        setPixel(xc - y, yc - x);
        setPixel(xc - x, yc + y);
        setPixel(xc + y, yc - x);
        setPixel(xc - y, yc + x);
        setPixel(xc + x, yc - y);

        if (d < 0) {
            d = d + 4 * x + 6;
        }
        else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    gluOrtho2D(-600, 600, -600, 600);
}

void draw() {
    //through origin
    bresenhamCircle(0, 0, 400);
    bresenhamCircle(0, 0, 200);
    //90 angle
    bresenhamCircle(0, 440, 40);
    bresenhamCircle(0, -440, 40);
    bresenhamCircle(440, 0, 40);
    bresenhamCircle(-440, 0, 40);
    //45 angle
    bresenhamCircle(311, 311, 40);
    bresenhamCircle(-311, -311, 40);

    bresenhamCircle(311, -311, 40);
    bresenhamCircle(-311, 311, 40);

    bresenhamCircle(-311, 311, 40);
    bresenhamCircle(311, -311, 40);
    //22.5 angle
    bresenhamCircle(168, 405, 40);
    bresenhamCircle(-168, -405, 40);

    bresenhamCircle(168, -405, 40);
    bresenhamCircle(-168, 405, 40);

    bresenhamCircle(405, 168, 40);
    bresenhamCircle(-405, -168, 40);

    bresenhamCircle(405, -168, 40);
    bresenhamCircle(-405, 168, 40);

    bresenhamCircle(-405, 168, 40);
    bresenhamCircle(405, -168, 40);

    //11.25 angle
    bresenhamCircle(86, 431, 40);
    bresenhamCircle(-86, -431, 40);

    bresenhamCircle(-86, 431, 40);
    bresenhamCircle(86, -431, 40);

    bresenhamCircle(86, -431, 40);
    bresenhamCircle(-86, 431, 40);

    bresenhamCircle(431, 86, 40);
    bresenhamCircle(-431, -86, 40);

    bresenhamCircle(-431, 86, 40);
    bresenhamCircle(431, -86, 40);

    //trial and error
    bresenhamCircle(242, 371, 40);

}

int main(int args, char** argv) {
    glutInit(&args, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 0);
    glutCreateWindow("Bangle");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}