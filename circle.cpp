#include "figures.h"

Circle::Circle(float radius, float red, float green, float blue) {
    rad = radius;
    side = 100;
    r = red;
    g = green;
    b = blue;
}

void Circle::draw() {
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

void Circle::zoom(float t) {
    rad = rad * t;
}