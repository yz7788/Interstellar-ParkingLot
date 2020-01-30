#include <windows.h>
#include "figures.h"
#include <cmath>

Car::Car(Vec p1, float r) {
    //car
    p = p1;
    radius = r;
    Vec w_1(-1.5 * r, -0.5 * r), w_2(1.5 * r, -0.5 * r);
    Circle w1(0.5 * r, 240.0 / 255, 100.0 / 255, 60.0 / 255);
    w1.setAnchor(p + w_1);
    c1 = w1;
    w1.setAnchor(p + w_2);
    c2 = w1;
    Vec tr1(1 * r, 0.5 * r), tr2(-2 * r, -0.5 * r), tm(0, 1 * r);
    Trapezoid trape(tr1, tr2, 83.0 / 255, 128.0 / 255, 219.0 / 255);
    trape.setAnchor(p + tm);
    t1 = trape;
    Vec rc1(-3 * r, 0.5 * r);
    Rectangle1 rec(rc1, 245.0 / 255, 160.0 / 255, 55.0 / 255);
    rec.setAnchor(p);
    rec1 = rec;

    //flag
    Vec rc2(-.05 * r, .6 * r);
    Vec flag(-2.1 * r, 1.0 * r);
    Rectangle1 Rec2(rc2, .6, .6, .6);
    Rec2.setAnchor(p + flag);
    rec2 = Rec2;
    Vec t1(0, -.6 * r), t2(-.9 * r, -.6 * r), t3(0, 0), tc(-2.1 * r, 1.7 * r);
    Triangle Tr1(t1, t2, t3, 1.0, 0.0, 0.0);
    Tr1.setAnchor(p + tc);
    tri1 = Tr1;
    Vec V1(-2.1 * r, 1.1 * r);
    v1 = V1 + p;
    Vec V2(-2.1 * r, 1.7 * r);
    v2 = V2 + p;
}

void Car::draw() {
    t1.draw();
    rec1.draw();
    rec2.draw();
    c1.draw();
    c2.draw();
    Vec newanchor;
    float static scale = 0.05 * radius;
    int static i = 0;
    if (v1.getY() != v2.getY()) {
        if ((tri1.getAnchor().getY() - v1.getY()) / (v2.getY() - v1.getY()) <= 1 && i == 0) {
            newanchor = tri1.getAnchor() +
                        (v2 - v1) *
                        (1.0 / sqrt(powf(v2.getX() - v1.getX(), 2) + powf(v2.getY() - v1.getY(), 2)) * scale);
            tri1.setAnchor(newanchor);
        }
        else if ((tri1.getAnchor().getY() - v1.getY()) / (v2.getY() - v1.getY()) > 0) {
            i = 1;
            newanchor = tri1.getAnchor() -
                        (v2 - v1) *
                        (1.0 / sqrt(powf(v2.getX() - v1.getX(), 2) + powf(v2.getY() - v1.getY(), 2)) * scale);
            tri1.setAnchor(newanchor);
        }
        else { i = 0; }
    }
    else {
        if ((tri1.getAnchor().getX() - v1.getX()) / (v2.getX() - v1.getX()) <= 1 && i == 0) {
            newanchor = tri1.getAnchor() +
                        (v2 - v1) *
                        (1.0 / sqrt(powf(v2.getX() - v1.getX(), 2) + powf(v2.getY() - v1.getY(), 2)) * scale);
            tri1.setAnchor(newanchor);
        }
        else if ((tri1.getAnchor().getX() - v1.getX()) / (v2.getX() - v1.getX()) > 0) {
            i = 1;
            newanchor = tri1.getAnchor() -
                        (v2 - v1) *
                        (1.0 / sqrt(powf(v2.getX() - v1.getX(), 2) + powf(v2.getY() - v1.getY(), 2)) * scale);
            tri1.setAnchor(newanchor);
        }
        else { i = 0; }
    }
    tri1.draw();
}

void Car::rotate(float a) {
    Vec tc = tri1.getAnchor() - p;
    t1.setAnchor(p);
    rec1.setAnchor(p);
    rec2.setAnchor(p);
    c2.setAnchor(p);
    tri1.setAnchor(p);
    t1.rotate(a);
    rec1.rotate(a);
    rec2.rotate(a);
    tri1.rotate(a);
    Vec static w_1(-1.5 * radius, -0.5 * radius), w_2(1.5 * radius, -0.5 * radius), tm(0, 1 * radius), flag(
            -2.1 * radius, 1.0 * radius), V1(-2.1 * radius, 1.1 * radius), V2(-2.1 * radius, 1.7 * radius);
    w_1 = w_1 >> a;
    w_2 = w_2 >> a;
    tm = tm >> a;
    flag = flag >> a;
    tc = tc >> a;
    V1 = V1 >> a;
    V2 = V2 >> a;
    t1.setAnchor(p + tm);
    rec1.setAnchor(p);
    rec2.setAnchor(p + flag);
    c1.setAnchor(p + w_1);
    c2.setAnchor(p + w_2);
    tri1.setAnchor(p + tc);
    v1 = p + V1;
    v2 = p + V2;
}

void Car::rotate(Vec p1, float a) {
    Vec p_0 = p - p1;
    this->rotate(a);
    p_0 = (p_0 >> a) - p_0;
    move(p_0);
}

void Car::move(Vec dir) {
    t1.move(dir);
    rec1.move(dir);
    c1.move(dir);
    c2.move(dir);
    rec2.move(dir);
    tri1.move(dir);
    p = p + dir;
    v1 = v1 + dir;
    v2 = v2 + dir;
}

Vec Car::getAnchor() {
    return rec1.getAnchor();
}