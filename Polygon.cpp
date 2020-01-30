#include "figures.h"

Polygon1::Polygon1(float radius, int Side, float red, float green, float blue) {
    rad = radius;
    side = Side;
    r = red;
    g = green;
    b = blue;
}

void Polygon1::draw() {
    int i;
    Vec p(-rad, 0);
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (i = 0; i < side; ++i) {
        p = p >> 2 * PI / side;
        glVertex2f(p.getX() + anchor.getX(), p.getY() + anchor.getY());
    };
    glEnd();
}

void Polygon1::zoom(float t) {
    rad = rad * t;
}