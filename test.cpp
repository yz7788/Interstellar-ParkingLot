//
// Created by suwenhao_jiaoda on 2016/8/4.
//

#include <iostream>
#include <ctime>
#include <windows.h>
#include "figures.h"

using namespace std;

void glDraw();

void TimeStep(int n);

//void randomcolor(float *R,float *G,float *B);

void getKey(unsigned char key,int x,int y);
void mouse(int button, int state, int x, int y);


int main(int argc, char *argv[]) {
    srand(std::time(0));
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Project");
    //glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(glDraw);
    glutTimerFunc(25, TimeStep, 0);
    glutKeyboardFunc(getKey);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

void getKey(unsigned char key,int x,int y)
{
    if(key==27) exit(0);
}

void mouse(int button, int state, int x, int y)
{
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
                Sleep(1000);
            break;
        case GLUT_MIDDLE_BUTTON: break;
        case GLUT_RIGHT_BUTTON: break;
        default:
            break;
    }
}

void glDraw() {
//    int static n=1;
//    float static _gate = 0;
//    float static _scalar = 0;
//    float static _rotate = 0.01;
//    float R,G,B;
//    map mp;
//    mp.draw();
//    srand(std::time(0));
//    int i,j;
//    Vec slot[10]={{-.475,-.375},{-.225,-.375},{.025,-.375},{.275,-.375},{.525,-.375},{.525,.825},{.275,.825},{.025,.825},{-.225,.825},{-.475,.825}};
//    Vec static occupied[7];
//    Vec static unoccupied[3];
//    Vec static park;
//    int static isemp[10]={0};
//    if(n==1){
//        for (i=0;i<7;i++){
//            j=rand()%10;
//            while(isemp[j]!=0){
//                j=rand()%10;
//            }
//            occupied[i]=slot[j];
//            isemp[j]=1;
//        }
//        i=0;
//        for (j=0;j<10;j++){
//            if(isemp[j]==0){
//                unoccupied[i]=slot[j];
//                i++;
//            }
//        }
//        park=unoccupied[rand()%3];
//    }
//    _scalar += 0.13;
//    Rocket RKT1(occupied[0],0.025);
//    RKT1.zoom((float) (fabs(sin(_scalar)) * 0.5 + 0.6));
//    RKT1.draw();
//    Rocket RKT2(occupied[1],0.025);
//    RKT2.zoom((float) (fabs(cos(_scalar)) * 0.5 + 0.6));
//    RKT2.draw();
//    UFO ufo1(occupied[2],0.08);
//    ufo1.rotate(sin(_scalar));
//    ufo1.draw();
//    UFO ufo2(occupied[3],0.08);
//    ufo2.rotate(cos(_scalar));
//    ufo2.draw();
//
//    Rectangle1 static gate({.19,.003},1,0,0);
//    gate.setAnchor({-.79,-.605});
//
//    randomcolor(&R,&G,&B);
//    Teleporter tel1(occupied[4],R,G,B);
//    tel1.draw();
//    randomcolor(&R,&G,&B);
//    Teleporter tel2(occupied[5],R,G,B);
//    tel2.draw();
//    randomcolor(&R,&G,&B);
//    Teleporter tel3(occupied[6],R,G,B);
//    tel3.draw();
//
//    Car static car({-.79,-.8},0.04);
//    if(n==1){car.rotate(-3.1415/2);}
//
//    int static a=0;
//    if(park.getY()>0.225&&a==0){
//        if(car.getAnchor().getY()<-.75){
//            car.move({0,0.01});
//        }
//        else if(car.getAnchor().getY()>=-.75&&car.getAnchor().getY()<-.45){
//            if(_gate < 0.36){
//                _gate += 0.027;gate.move({_gate,0});
//            }
//            else if(_gate = 0.4){gate.move({_gate,0});car.move({0,0.01});}
//        }
//        else if (car.getAnchor().getY()>=-.45&&car.getAnchor().getY()<=-.25){
//            if(_gate > 0){
//                _gate -= 0.027;gate.move({_gate,0});
//            }
//            car.move({0,0.01});
//        }
//        else if(car.getAnchor().getY()>=-.25&&car.getAnchor().getY()<-.05) {
//            car.rotate({-.6,-.25},_rotate);  }
//        else if(car.getAnchor().getX()>=-.6&&car.getAnchor().getX()<.6&&car.getAnchor().getY()<.225) {
//            car.move({0.01,0}); }
//        else if(car.getAnchor().getY()>=-.06&&car.getAnchor().getY()<.225) {
//            car.move({0.01,0.01});}
//        else if(car.getAnchor().getY()>=.225&&car.getAnchor().getY()<.51) {
//            car.move({-0.01,0.01});}
//        else if(car.getAnchor().getX()>park.getX()-0.25&&car.getAnchor().getX()<=.6&&car.getAnchor().getY()>.225) {
//            car.move({-0.01,0});}
//        else{
//            a=1;
//        }
//    }
//    else if(park.getY()<0.225&&a==0){
//        if(car.getAnchor().getY()<-.75){
//            car.move({0,0.01});
//        }
//        else if(car.getAnchor().getY()>=-.75&&car.getAnchor().getY()<-.45){
//            if(_gate < 0.36){
//                _gate += 0.027;gate.move({_gate,0});
//            }
//            else if(_gate = 0.4){gate.move({_gate,0});car.move({0,0.01});}
//        }
//        else if (car.getAnchor().getY()>=-.45&&car.getAnchor().getY()<=-.25){
//            if(_gate > 0){
//                _gate -= 0.027;gate.move({_gate,0});
//            }
//            car.move({0,0.01});
//        }
//        else if(car.getAnchor().getY()>=-.25&&car.getAnchor().getY()<-.05) {
//            car.rotate({-.6,-.25},_rotate);
//        }
//        else if(car.getAnchor().getX()>=-.6&&car.getAnchor().getX()<park.getX()+.25&&car.getAnchor().getY()<.225) {
//            car.move({0.01,0});
//        }
//        else{
//            a=1;
//        }
//    }
//    else if(park.getY()>0.225&&a==1){
//        if(car.getAnchor().getX()<=park.getX()-0.125&&car.getAnchor().getY()>.225){
//            car.move({0.01,0});
//        }
//        else if(car.getAnchor().getX()<=park.getX()&&car.getAnchor().getY()>.225){
//            car.move({0.01,0.01});
//        }
//        else{
//            a=2;
//        }
//    }
//    else if(park.getY()<0.225&&a==1){
//        if(car.getAnchor().getX()>=park.getX()+0.125&&car.getAnchor().getY()<.225){
//            car.move({-0.01,0});
//        }
//        else if(car.getAnchor().getX()>=park.getX()&&car.getAnchor().getY()<.225){
//            car.move({-0.01,-0.01});
//        }
//        else{
//            a=2;
//        }
//
//    }
//    else if(park.getY()>0.225&&a==2){
//        if(car.getAnchor().getY()<=park.getY()-0.02){
//            car.move({0,0.01});
//        }
//    }
//    else if(park.getY()<0.225&&a==2){
//        if(car.getAnchor().getY()>=park.getY()+0.02){
//            car.move({0,-0.01});
//        }
//    }
//
//    gate.draw();
    int i = 0;
    static int n = 0;

    glFlush();
    glClear(GL_COLOR_BUFFER_BIT);
    n++;
}

void TimeStep(int n) {
    glutTimerFunc(25, TimeStep, 0);
    glutPostRedisplay();
}
//void randomcolor(float *R,float *G,float *B){
//    *R = (float) rand() / RAND_MAX;
//    *G = (float) rand() / RAND_MAX;
//    *B = (float) rand() / RAND_MAX;
//}
