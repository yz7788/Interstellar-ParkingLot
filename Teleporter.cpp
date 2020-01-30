#include "figures.h"
Teleporter::Teleporter(Vec pt,int Side, float R,float G, float B) {
    setTeleporter(pt,Side, R,G, B);
}
void Teleporter::draw() {
    pol1.draw();
}

void Teleporter::setTeleporter(Vec pt,int Side, float R,float G, float B){
    Polygon1 Po(0.08,Side,R,G,B);
    Po.setAnchor(pt);
    pol1=Po;
}