#include <windows.h>
#include "figures.h"

Trapezoid::Trapezoid(Vec pt1,Vec pt2, float red, float green, float blue) {
    Vec p(-1,1);
    p1 = pt1;
    p3 = pt2;
    p2 = p3 * p;
    p4 = p1 * p;
    r = red;
    g = green;
    b = blue;
}

void Trapezoid::draw() {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(p1.getX() + anchor.getX(), p1.getY() + anchor.getY());
    glVertex2f(p2.getX() + anchor.getX(), p2.getY() + anchor.getY());
    glVertex2f(p3.getX() + anchor.getX(), p3.getY() + anchor.getY());
    glVertex2f(p4.getX() + anchor.getX(), p4.getY() + anchor.getY());
    glEnd();
}
