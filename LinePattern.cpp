#include<GL/glut.h>


void init() {
    glClearColor(0, 0, 0, 0);
    glColor3f(1, 1, 1);
    glPointSize(2);

    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 500, 0, 500);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

}
void displaypoint(float x, float y) {

    glBegin(GL_POINTS);
    glColor3f(1, 1, 1);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}

void Simpleline(float x1, float y1, float x2, float y2) {
    float step;
    float dx = x2 - x1;
    float dy = y2 - y1;

    if (abs(dx) > abs(dy)) {
        step = abs(dx);
    }
    else {
        step = abs(dy);

    }
    float xin = dx / (float)step;
    float yin = dy / (float)step;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= step;i++) {
        displaypoint(x, y);
        x = x + xin;
        y = y + yin;
    }
}

void dottedline(float x1, float y1, float x2, float y2) {
    float step;
    float dx = x2 - x1;
    float dy = y2 - y1;

    if (abs(dx) > abs(dy)) {
        step = abs(dx);
    }
    else {
        step = abs(dy);

    }
    float xin = dx / (float)step;
    float yin = dy / (float)step;

    float x = x1;
    float y = y1;
    displaypoint(x, y);

    for (int i = 0; i <= step;i++) {
        x = x + xin;
        y = y + yin;
        if (i % 5 == 0) {

            displaypoint(x, y);
        }

    }
}

void dashedline(float x1, float y1, float x2, float y2) {
    float step;
    float dx = x2 - x1;
    float dy = y2 - y1;

    if (abs(dx) > abs(dy)) {
        step = abs(dx);
    }
    else {
        step = abs(dy);

    }
    float xin = dx / (float)step;
    float yin = dy / (float)step;

    float x = x1;
    float y = y1;
    displaypoint(x, y);

    for (int k = 0; k <= step;k++) {
        x = x + xin;
        y = y + yin;
        int m;
        k = m % 20;
        if (k % 9 != 0 && k % 10 != 0 && k % 11 != 0 && k % 12 != 0 && k % 16 != 0 && k % 17 != 0 && k % 18 != 0 && k % 19 != 0) {
            displaypoint(x, y);

        }
        m++;

    }
}

void bsa(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int xin, yin = 1;
    int x = x1;
    int y = y1;

    if (dx < 0) {
        dx = -dx;
    }
    if (dy < 0) {
        dy = -dy;
    }

    if (x1 > x2) {
        xin = -1;
    }

    if (y1 > y2) {
        yin = -1;
    }

    displaypoint(x, y);

    if (dx > dy) {
        int  p = 2 * dy - dx;
        for (int i = 1;i < dx;i++) {
            if (p > 0) {
                y = y + yin;
                p = p + 2 * (dy - dx);

            }
            else {
                p = p + 2 * dy;
            }
            x = x + xin;
            displaypoint(x, y);
        }

    }

    else {
        int  p = 2 * dx - dy;
        for (int i = 1;i < dy;i++) {
            if (p > 0) {
                p = p + 2 * (dx - dy);
                x = x + xin;
            }
            else {
                p = p + 2 * dx;
            }
            y = y + yin;
            displaypoint(x, y);
        }
    }



}




void render() {

    // Simpleline(100, 100, 200, 100);
    // Simpleline(100, 100, 100, 140);
    // Simpleline(100, 140, 160, 140);
    // Simpleline(160, 140, 160, 200);

    // Simpleline(160, 200, 100, 200);
    // Simpleline(100, 200, 100, 340);

    // Simpleline(100, 340, 140, 340);
    // Simpleline(140, 340, 140, 240);

    // Simpleline(140, 240, 160, 240);
    // Simpleline(160, 240, 160, 340);

    // Simpleline(160, 340, 300, 340);
    // Simpleline(300, 340, 300, 300);
    // Simpleline(300, 300, 200, 300);

    // Simpleline(200, 300, 200, 240);
    // Simpleline(200, 240, 300, 240);

    // Simpleline(300, 240, 300, 100);
    // Simpleline(300, 100, 260, 100);
    // Simpleline(260, 100, 260, 200);

    // Simpleline(260, 200, 200, 200);
    // Simpleline(200, 200, 200, 100);

    dashedline(100, 100, 300, 100);
    Simpleline(100, 100, 100, 300);
    Simpleline(300, 100, 300, 300);
    Simpleline(300, 300, 100, 300);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Line Pattern");
    init();
    glutDisplayFunc(render);
    glRotated(-45, 1, 0, 0);

    glutMainLoop();
    return 0;
}