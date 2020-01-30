//
// Created by Administrator on 2016/8/5 0005.
//
#include <windows.h>
#include "figures.h"
Arrow::Arrow(Vec p1, float scale, float R, float G, float B) {
    p=p1;
    r=scale;
    Triangle tr1({0,(float)0.1*scale},{(float)0.1*scale,0},{0,(float)-0.1*scale},R,G,B),\
    tr2({(float)-0.1*scale,(float)0.1*scale},{0,(float)0.1*scale},{0,0},R,G,B),tr3({(float)\
    -0.1*scale,(float)-0.1*scale},{0,(float)-0.1*scale},{0,0},R,G,B);
    tr1.setAnchor(p);
    tr2.setAnchor(p);
    tr3.setAnchor(p);
    t1=tr1;
    t2=tr2;
    t3=tr3;
}
void Arrow::setarrow(Vec p1) {
    p=p1;
    t1.setAnchor(p);
    t2.setAnchor(p);
    t3.setAnchor(p);
}
void Arrow::draw() {
    t1.draw();
    t2.draw();
    t3.draw();
}
void Arrow::rotate(float a) {
    t1.rotate(a);
    t2.rotate(a);
    t3.rotate(a);
}
void Arrow::arrowcolor(float R, float G, float B) {
    t1.setcolor(R,G,B);
    t2.setcolor(R,G,B);
    t3.setcolor(R,G,B);
}
