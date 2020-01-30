#include <windows.h>
#include "figures.h"

Triangle::Triangle(Vec pt1,Vec pt2,Vec pt3, float red, float green, float blue) {
    p1 = pt1;
    p2 = pt2;
    p3 = pt3;
    r = red;
    g = green;
    b = blue;
}

void Triangle::draw() {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    glVertex2f(p1.getX() + anchor.getX(), p1.getY() + anchor.getY());
    glVertex2f(p2.getX() + anchor.getX(), p2.getY() + anchor.getY());
    glVertex2f(p3.getX() + anchor.getX(), p3.getY() + anchor.getY());
    glEnd();
}

void Triangle::zoom(float t) {
    p1 = p1 * t;
    p2 = p2 * t;
    p3 = p3 * t;
}