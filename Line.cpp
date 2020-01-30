#include "figures.h"
Line::Line(Vec pt1,Vec pt2,int linewidth) {
    p1=pt1;p2=pt2;lw=linewidth;
}
void Line::draw() {
    glColor3f(1,1,1);
    glLineWidth(lw);
    glBegin(GL_LINE_STRIP);
    glVertex2f(p1.getX(),p1.getY());
    glVertex2f(p2.getX(),p2.getY());
    glEnd();
}