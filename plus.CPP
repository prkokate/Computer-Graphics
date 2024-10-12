#include <GL/freeglut.h>
#include <GL/glut.h>

// Function to draw plus symbol
void drawPlus() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);

    // glRotatef(-45, 0, 0, 1);

    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex2f(-50, -50);
    glVertex2f(50, -50);

    glVertex2f(50, -50);
    glVertex2f(50, 50);

    glVertex2f(50, 50);
    glVertex2f(150, 50);

    glVertex2f(150, 50);
    glVertex2f(150, 150);

    glVertex2f(150, 150);
    glVertex2f(50, 150);

    glVertex2f(50, 150);
    glVertex2f(50, 250);

    glVertex2f(50, 250);
    glVertex2f(-50, 250);

    glVertex2f(-50, 250);
    glVertex2f(-50, 150);

    glVertex2f(-50, 150);
    glVertex2f(-150, 150);

    glVertex2f(-150, 150);
    glVertex2f(-150, 50);

    glVertex2f(-150, 50);
    glVertex2f(-50, 50);

    glVertex2f(-50, 50);
    glVertex2f(-50, -50);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Plus");
    glutDisplayFunc(drawPlus);
    glutMainLoop();
}