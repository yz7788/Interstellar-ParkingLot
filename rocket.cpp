//
// Created by Administrator on 2016/8/3 0003.
//

#include <windows.h>
#include "figures.h"

Rocket::Rocket(Vec p1, float t) {
    setRocket(p1,t);
}

void Rocket::draw() {
    glPushMatrix();
    glTranslatef(anchor.getX(), anchor.getY(), 0.0f);
    tr1.draw();
    tr2.draw();
    tr3.draw();
    r1.draw();
    t1.draw();
    t2.draw();
    c1.draw();
    glPopMatrix();
}

void Rocket::zoom(float t) {
    tr1.zoom(t);
    tr2.zoom(t);
    tr3.zoom(t);
    Vec cm(0, 1.5 * radius);
    cm = cm * t;
    c1.zoom(t);
    c1.setAnchor(p + cm);
    r1.zoom(t);
    t1.zoom(t);
    t2.zoom(t);
}

void Rocket::setRocket(Vec p1, float t) {
    p = p1;
    radius = t;
    Vec tr_1(-t, 0), tr_2(-t, -3 * t), tr_3(-2 * t, -3 * t), tr_4(t, 0), tr_5(t, -3 * t), tr_6(2 * t, -3 * t);
    Triangle tri1(tr_1, tr_2, tr_3, 0.2, 0.3, 0.4), tri2(tr_4, tr_5, tr_6, 0.2, 0.3, 0.4);
    tri1.setAnchor(p);
    tri2.setAnchor(p);
    tr1 = tri1;
    tr2 = tri2;
    Vec tr3_1(0, 4.5 * t), tr3_2(-t, 3 * t), tr3_3(t, 3 * t);
    Triangle tri3(tr3_1, tr3_2, tr3_3, 0.9, 0.5, 0.7);
    tri3.setAnchor(p);
    tr3 = tri3;
    Vec rec(-t, 3 * t);
    Rectangle1 rec1(rec, 0.3, 1, 1);
    rec1.setAnchor(p);
    r1 = rec1;
    Vec trape1(-0.8 * t, -3 * t), trape2(1 * t, -3.5 * t), trape3(-0.05 * t, 0), trape4(0.1 * t, -3 * t);
    Trapezoid trape_1(trape1, trape2, 0.8, 0.8, 0.8), trape_2(trape3, trape4, 0.2, 0.3, 0.4);
    trape_1.setAnchor(p);
    trape_2.setAnchor(p);
    t1 = trape_1;
    t2 = trape_2;
    Circle c(0.3 * t, 1, 1, 0.6);
    Vec cm(0, 1.5 * t);
    c.setAnchor(p + cm);
    c1 = c;
}