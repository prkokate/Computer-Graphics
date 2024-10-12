#include <bits/stdc++.h>
#include <GL/glut.h>

#define ll GLint
#define lf GLfloat

lf rotaaa = 0.0;

void spinn()
{
    rotaaa += 0.2;
    if (rotaaa == 360)
        rotaaa = 0;

    glutPostRedisplay();
}

void drawFace(lf a[], lf b[], lf c[], lf d[])
{
    glBegin(GL_POLYGON);
    glVertex3f(a[0], a[1], a[2]);
    glVertex3f(b[0], b[1], b[2]);
    glVertex3f(c[0], c[1], c[2]);
    glVertex3f(d[0], d[1], d[2]);
    glEnd();
}

void drawCube(lf v0[], lf v1[], lf v2[], lf v3[], lf v4[], lf v5[], lf v6[], lf v7[])
{
    glColor3f(1.0, 0.0, 0.0);
    drawFace(v0, v1, v2, v3);

    glColor3f(0.0, 1.0, 0.0);
    drawFace(v4, v5, v6, v7);

    glColor3f(0.0, 0.0, 1.0);
    drawFace(v1, v5, v6, v2);

    glColor3f(1.0, 0.0, 1.0);
    drawFace(v0, v4, v7, v3);

    glColor3f(1.0, 1.0, 0.0);
    drawFace(v0, v4, v5, v1);

    glColor3f(1.0, 1.0, 1.0);
    drawFace(v3, v7, v6, v2);
}

void to_display()
{
    lf V[8][3] = {
                            {-0.5, 0.5, 0.5},
                            { 0.5, 0.5, 0.5},
                            { 0.5,-0.5, 0.5},
                            {-0.5,-0.5, 0.5},

                            {-0.5, 0.5,-0.5},
                            { 0.5, 0.5,-0.5},
                            { 0.5,-0.5,-0.5},
                            {-0.5,-0.5,-0.5},
    };
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glRotatef(rotaaa, 1.0, 1.0, 1.0);
    drawCube(V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);

    glutSwapBuffers();
}

void initi()
{
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(200, 500);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D-Cube");
    glClearColor(0.3, 0.7, 0.4, 1.0);
    glColor3f(1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    initi();

    glutDisplayFunc(to_display);
    glutIdleFunc(spinn);

    glutMainLoop();

    return 0;
}