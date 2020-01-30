#include "figures.h"

star::star() {
    Triangle _up({-.25, 0}, {.25, 0}, {0, .5});
    Triangle _down({-.25, 0}, {.25, 0}, {0, -.5});
    Triangle _left({0, -.25}, {0, .25}, {-.5, 0});
    Triangle _right({0, -.25}, {0, .25}, {.5, 0});
    myStar[0] = _up;
    myStar[1] = _down;
    myStar[2] = _left;
    myStar[3] = _right;
}

void star::setStar(Vec pt, float _scale) {
    int i = 0;
    for(i;i<4;i++){
        myStar[i].setAnchor(pt);
        myStar[i].zoom(_scale);
    }
}

void star::draw() {
    int i = 0;
    for(i;i<4;i++) myStar[i].draw();
}

void star::zoom(float t) {
    int i = 0;
    for(i;i<4;i++) myStar[i].zoom(t);
}