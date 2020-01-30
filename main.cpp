#include <iostream>
#include <ctime>
#include "figures.h"

using namespace std;

void glDraw();
void glDrawPause();
void glDrawAcc();
void glDrawDec();
void glDrawMove();
void TimeStep(int n);
void getKey(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

#define  GLUT_WHEEL_UP		3
#define  GLUT_WHEEL_DOWN	4

void onMenu(int id)
{
    switch (id)
    {
        case 1:
            glutDisplayFunc(glDrawAcc);
            break;
        case 2:
            glutDisplayFunc(glDrawDec);
            break;
        case 3:
            glutDisplayFunc(glDrawMove);
            break;
        default:break;
    }
}

void initMenu()
{
    GLint mainMenu = glutCreateMenu(onMenu);
    glutAddMenuEntry("Accelerate", 1);
    glutAddMenuEntry("Decelerate", 2);
    glutAddMenuEntry("Rocket & UFO Move / Pause", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}



int main(int argc, char *argv[]) {
    int static i = 0;
    srand(std::time(0));
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Project");
    //glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(glDraw);
    glutTimerFunc(25, TimeStep, 0);
    glutKeyboardFunc(getKey);
    glutMouseFunc(mouse);
    initMenu();
    glutMainLoop();
    return 0;
}

void getKey(unsigned char key, int x, int y) {
    static int isPause = 0;
    if (key == 27) exit(0);
    if (key == 'a' || key == 'A') {//accelerate
        glutDisplayFunc(glDrawAcc);
    }
    if (key == 'd' || key == 'D')//decelerate
    {
        glutDisplayFunc(glDrawDec);
    }
    if (key == 's' || key == 'S')//standard
    {
        glutDisplayFunc(glDraw);
    }
    if (key == 'p' || key == 'P')//stop&resume
    {
        if (isPause == 0)
        {
            isPause = 1;
            glutDisplayFunc(glDrawPause);
        }
        else
        {
            isPause = 0;
            glutDisplayFunc(glDraw);
        }
    }
    if (key == 'w' || key == 'W')//rocket
    {
        glutDisplayFunc(glDrawMove);
    }
}

void mouse(int button, int state, int x, int y) {
    static int isPause = 0;
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            {
                if (isPause == 0)
                {
                    isPause = 1;
                    glutDisplayFunc(glDrawPause);
                }
                else
                {
                    isPause = 0;
                    glutDisplayFunc(glDraw);
                }
            }
            break;
        default:
            break;
    }
}

void glDraw() {
    logic(0.01,0);
    glFlush();
    glClear(GL_COLOR_BUFFER_BIT);
}

void glDrawPause() {}

void glDrawAcc() {
    logic(0.04,0);
    glFlush();
    glClear(GL_COLOR_BUFFER_BIT);
}

void glDrawDec() {
    logic(0.005,0);
    glFlush();
    glClear(GL_COLOR_BUFFER_BIT);
}

void glDrawMove() {
    logic(0.01,1);
    glFlush();
    glClear(GL_COLOR_BUFFER_BIT);
}

void TimeStep(int n) {
    glutTimerFunc(25, TimeStep, 0);
    glutPostRedisplay();
}