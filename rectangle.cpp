#include <windows.h>
#include "figures.h"

Rectangle1::Rectangle1(Vec pt1, float red, float green, float blue) {
    Vec p(1, -1);
    p1 = pt1;
    p2 = pt1 * p;
    p3 = p1 * -1;
    p4 = p2 * -1;
    r = red;
    g = green;
    b = blue;
}

void Rectangle1::draw() {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(p1.getX() + anchor.getX(), p1.getY() + anchor.getY());
    glVertex2f(p2.getX() + anchor.getX(), p2.getY() + anchor.getY());
    glVertex2f(p3.getX() + anchor.getX(), p3.getY() + anchor.getY());
    glVertex2f(p4.getX() + anchor.getX(), p4.getY() + anchor.getY());
    glEnd();
}