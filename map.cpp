#include "figures.h"
map::map(){
    Rectangle1 rec({.55,.06},130.0/255,130.0/255,130.0/255);
    rec.setAnchor({0,.225});
    rec1=rec;
    Line L1({-.98,-.6},{-.98,.95},2);
    Line L2({-.98,.95},{.98,.95},2);
    Line L3({.98,.95},{.98,-.5},2);
    Line L4({.98,-.5},{-.6,-.5},2);
    Line L5({-.6,-.5},{-.6,-.6},2);
    //slot line
    Line L6({-.6,-.5},{-.6,-.25},1);
    Line L7({-.35,-.5},{-.35,-.25},1);
    Line L8({-.1,-.5},{-.1,-.25},1);
    Line L9({.15,-.5},{.15,-.25},1);
    Line L10({.4,-.5},{.4,-.25},1);
    Line L11({.65,-.5},{.65,-.25},1);
    Line L12({-.6,.95},{-.6,.7},1);
    Line L13({-.35,.95},{-.35,.7},1);
    Line L14({-.1,.95},{-.1,.7},1);
    Line L15({.15,.95},{.15,.7},1);
    Line L16({.4,.95},{.4,.7},1);
    Line L17({.65,.95},{.65,.7},1);
    myLine[0]=L1;
    myLine[1]=L2;
    myLine[2]=L3;
    myLine[3]=L4;
    myLine[4]=L5;
    myLine[5]=L6;
    myLine[6]=L7;
    myLine[7]=L8;
    myLine[8]=L9;
    myLine[9]=L10;
    myLine[10]=L11;
    myLine[11]=L12;
    myLine[12]=L13;
    myLine[13]=L14;
    myLine[14]=L15;
    myLine[15]=L16;
    myLine[16]=L17;

}
void map::draw() {
    int i = 0;
    rec1.draw();
    for (i;i<17;i++){
        myLine[i].draw();
    }
}
void map::move(Vec dir) {}
void map::rotate(float a) {}
void map::rotate(Vec p1, float a) {}
void map::zoom(float k) {}