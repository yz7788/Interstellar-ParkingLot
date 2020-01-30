#include "figures.h"


semiCircle::semiCircle(float radius, float red, float green, float blue) {
    rad = radius;
    Vec _p(-rad, 0);
    p = _p;
    r = red;
    g = green;
    b = blue;
    side = 100;
}

void semiCircle::draw() {
    int i;
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(p.getX() + anchor.getX(), p.getY() + anchor.getY());
    for (i = 0; i < side; ++i) {
        p = p >> PI / side;
        glVertex2f(p.getX() + anchor.getX(), p.getY() + anchor.getY());
    };
    glEnd();
}
