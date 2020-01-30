#include <windows.h>
#include "figures.h"

UFO::UFO(Vec p1, float t) {
    setUFO(p1,t);
}

void UFO::draw() {
    glPushMatrix();
    glTranslatef(anchor.getX(), anchor.getY(), 0.0f);
    u.draw();
    t1.draw();
    t2.draw();
    glColor3f(1, 0.5, 0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(l1.getX(), l1.getY());
    glVertex2f(l2.getX(), l2.getY());
    glVertex2f(r1.getX(), r1.getY());
    glVertex2f(r2.getX(), r2.getY());
    glEnd();
    glPopMatrix();
}

void UFO::rotate(float t) {
    u.setAnchor(p);
    t1.setAnchor(p);
    t2.setAnchor(p);
    Vec tm(0.65 * radius, 0);
    tm = tm >> t;

    l1 = ((l1 - p) >> t) + p;
    l2 = ((l2 - p) >> t) + p;
    r1 = ((r1 - p) >> t) + p;
    r2 = ((r2 - p) >> t) + p;

    u.rotate(t);
    t1.rotate(t);
    t2.rotate(t);
    t1.setAnchor(p - tm);
    t2.setAnchor(p + tm);
};

void UFO::setUFO(Vec p1, float t){
    p = p1;
    radius = t;
    semiCircle u1(t, 0, 0, 1);
    u = u1;
    u.setAnchor(p1);
    Vec tl2(-0.35 * t, -0.3 * t), tl1(0.25 * t, 0), tm(0.65 * t, 0);
    Trapezoid trape(tl1, tl2, 1, 1, 0);
    t1 = trape;
    t1.setAnchor(p1 - tm);
    t2 = trape;
    t2.setAnchor(p1 + tm);
    Vec l_1((float) (-3 * sqrt(2) / 4.0 * t), (float) (3 * sqrt(2) / 4.0 * t)), l_2((float) (-sqrt(2) / 2.0 * t), (float) (sqrt(2) / 2.0 * t)), tr(-1,1);
    Vec r_1, r_2;
    r_1 = l_1 * tr;
    r_2 = l_2 * tr;
    l1 = l_1 + p1;
    l2 = l_2 + p1;
    r1 = r_1 + p1;
    r2 = r_2 + p1;
}