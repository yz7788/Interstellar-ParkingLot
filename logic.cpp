#include "figures.h"

void randomcolor(float *R, float *G, float *B);

void logic(float speed, bool isMove){
    int static n = 1;
    float static _gate = 0;
    float static _scalar = 0;
    float static _rotate = 0.05;
    float static _rocketMoveSpeed = 0;
    float static _ufoMoveSpeed = 0;
    int static _time1 = (int)(PI / (2 * _rotate));
    int static _time2 = (int)(PI / _rotate);
    int static _time3 = (int)(PI / (2 * _rotate));
    float R, G, B;
    int Side;
    int i, j;
    star mystar[20];
    Arrow arrows[7];
    Vec arrowspos[7]={{-0.25,-0.05},{0,-0.05},{0.25,-0.05},{0.8,0.225},{-0.25,0.5},{0,0.5},{0.25,0.5}};

    static float pos[20][3];
    for (i = 0; i < 19; i++) {
        pos[i][0] = sin(rand())*0.9;
        pos[i][1] = cos(rand())*0.9;
        pos[i][2] = ((float)rand())/(RAND_MAX*20);
        mystar[i].setStar({pos[i][0],pos[i][1]},pos[i][3]/2);
        mystar[i].zoom(0.2);
        mystar[i].draw();
    }

    static int turn[3] = {0,1,2};

    for (i=0;i<7;i++){
        if (i%3 == turn[0]) arrows[i].arrowcolor(0.78,0.93,0.91);
        if (i%3 == turn[1]) arrows[i].arrowcolor(0.69,0.84,0.93);
        if (i%3 == turn[2]) arrows[i].arrowcolor(0.36,0.65,0.73);
        if(i<3){
            arrows[i].setarrow(arrowspos[i]);
            arrows[i].draw();
        }else if(i==3){
            arrows[i].setarrow(arrowspos[i]);
            arrows[i].rotate(3*PI/2);
            arrows[i].draw();
        } else{
            arrows[i].setarrow(arrowspos[i]);
            arrows[i].rotate(PI);
            arrows[i].draw();
        }
    }
    if(n%30 == 0){
        for (i = 0;i<3;i++){
            turn[i]++;
            if(turn[i]>2) turn[i] = 0;
        }
    }

    map mp;
    mp.draw();
    srand(std::time(0));
    Vec slot[10] = {{-.475, -.375},
                    {-.225, -.375},
                    {.025,  -.375},
                    {.275,  -.375},
                    {.525,  -.375},
                    {.525,  .825},
                    {.275,  .825},
                    {.025,  .825},
                    {-.225, .825},
                    {-.475, .825}};
    const int maxOccupied = 6;
    Vec static occupied[maxOccupied];
    Vec static unoccupied[10 - maxOccupied];
    Vec static park;
    int static isemp[10] = {0};
    if (n == 1) {
        for (i = 0; i < maxOccupied; i++) {
            j = rand() % 10;
            while (isemp[j] != 0) {
                j = rand() % 10;
            }
            occupied[i] = slot[j];
            isemp[j] = 1;
        }
        i = 0;
        for (j = 0; j < 10; j++) {
            if (isemp[j] == 0) {
                unoccupied[i] = slot[j];
                i++;
            }
        }
        park = unoccupied[rand() % 3];
    }
    const static int _numRocket = rand()%maxOccupied;
    const static int _numUFO = rand()%(maxOccupied - _numRocket);
    const static int _numTeleporter = maxOccupied - _numRocket - _numUFO;

    Rocket* rkt = new Rocket[_numRocket];
    UFO* ufo = new UFO[_numUFO];
    Teleporter* tel = new Teleporter[_numTeleporter];

    for (i = 0;i<_numRocket;i++){
        rkt[i].setRocket(occupied[i], 0.025);
        if (i%2 == 1) rkt[i].zoom((float) (fabs(sin(_scalar)) * 0.5 + 0.6));
        else rkt[i].zoom((float) (fabs(cos(_scalar)) * 0.5 + 0.6));
        if(isMove&&i%2 == 1) {rkt[i].move(Vec(0.0f, 0.3*sin(_rocketMoveSpeed)));_rocketMoveSpeed+=0.01;}
        else if(isMove&&i%2 == 0) {rkt[i].move(Vec(0.0f, 0.3*sin(-_rocketMoveSpeed)));_rocketMoveSpeed+=0.01;}
        else _rocketMoveSpeed = 0;
        rkt[i].draw();
    }
    for (i = 0;i<_numUFO;i++){
        ufo[i].setUFO(occupied[i+_numRocket], 0.08);
        if (i%2 == 1) ufo[i].rotate(sin(_scalar));
        else ufo[i].rotate(cos(_scalar));
        if(isMove&&i%2 == 1) {ufo[i].move(Vec(0.0f, 0.3*sin(-_ufoMoveSpeed)));_ufoMoveSpeed+=0.01;}
        else if(isMove&&i%2 == 0) {ufo[i].move(Vec(0.0f, 0.3*sin(_ufoMoveSpeed)));_ufoMoveSpeed+=0.01;}
        else _ufoMoveSpeed = 0;
        ufo[i].draw();
    }
    for (i = 0;i<_numTeleporter;i++){
        randomcolor(&R, &G, &B);
        Side = rand() % 5 + 3;
        tel[i].setTeleporter(occupied[i+_numRocket+_numUFO],Side, R, G, B);
        tel[i].rotate(sin(_scalar));
        tel[i].draw();
    }

    _scalar += 0.13;

    Rectangle1 static gate({.19, .003}, 1, 0, 0);
    gate.setAnchor({-.79, -.605});

    Car static car({-.79, -.8}, 0.04);
    if (n == 1) { car.rotate(-PI/ 2); }

    int static a = 0;
    if (park.getY() > 0.225 && a == 0) {
        if (car.getAnchor().getY() < -.75) {
            car.move({0, speed});
        }
        else if (car.getAnchor().getY() >= -.75 && car.getAnchor().getY() < -.45) {
            if (_gate < 0.36) {
                _gate += 0.024;
                gate.move({_gate, 0});
            }
            else {
                _gate = 0.4;
                gate.move({_gate, 0});
                car.move({0, speed});
            }
        }
        else if (car.getAnchor().getY() >= -.45 && car.getAnchor().getY() <= -.25) {
            if (_gate > 0) {
                _gate -= 0.024;
                gate.move({_gate, 0});
            }
            car.move({0, speed});
        }
        else if (car.getAnchor().getY() >= -.25 && car.getAnchor().getY() < -.05 && _time1 > 0) {
            car.rotate({-.6, -.25}, _rotate);
            _time1--;
        }
        else if (car.getAnchor().getX() >= -.6 && car.getAnchor().getX() < .55 && car.getAnchor().getY() < .225) {
            car.move({speed, 0});
        }
        else if (car.getAnchor().getY() >= -.06 && car.getAnchor().getY() < .51 && _time2 > 0) {
            car.rotate({0.55, 0.225}, -_rotate);
            _time2--;
        }
        else if (car.getAnchor().getX() > park.getX() - 0.25 && car.getAnchor().getX() <= .6 &&
                 car.getAnchor().getY() > .225) {
            car.move({-speed, 0});
        }
        else {
            a = 1;
        }
    }
    else if (park.getY() < 0.225 && a == 0) {
        if (car.getAnchor().getY() < -.75) {
            car.move({0, speed});
        }
        else if (car.getAnchor().getY() >= -.75 && car.getAnchor().getY() < -.45) {
            if (_gate < 0.36) {
                _gate += 0.024;
                gate.move({_gate, 0});
            }
            else{
                _gate = 0.4;
                gate.move({_gate, 0});
                car.move({0, speed});
            }
        }
        else if (car.getAnchor().getY() >= -.45 && car.getAnchor().getY() <= -.25) {
            if (_gate > 0) {
                _gate -= 0.024;
                gate.move({_gate, 0});
            }
            car.move({0, speed});
        }
        else if (car.getAnchor().getY() >= -.25 && car.getAnchor().getY() < -.05 && _time1 > 0) {
            car.rotate({-.6, -.25}, _rotate);
            _time1--;
        }
        else if (car.getAnchor().getX() >= -.6 && car.getAnchor().getX() < park.getX() + .25 &&
                 car.getAnchor().getY() < .225) {
            car.move({speed, 0});
        }
        else {
            a = 1;
        }
    }
    else if (park.getY() > 0.225 && a == 1) {
        if (car.getAnchor().getX() <= park.getX() - 0.2 && car.getAnchor().getY() > .225) {
            car.move({speed, 0});
        }
        else if (car.getAnchor().getY() > .225 && _time3 > 0) {
            car.rotate({park.getX() - (float)0.2, 0.7}, -_rotate);
            _time3--;
        }
        else {
            a = 2;
        }
    }
    else if (park.getY() < 0.225 && a == 1) {
        if (car.getAnchor().getX() >= park.getX() + 0.2 && car.getAnchor().getY() < .225) {
            car.move({-speed, 0});
        }
        else if (car.getAnchor().getY() < .225 && _time3 > 0) {
            car.rotate({park.getX() + (float)0.2, -0.25}, -_rotate);
            _time3--;
        }
        else {
            a = 2;
        }

    }
    else if (park.getY() > 0.225 && a == 2) {
        if (car.getAnchor().getY() <= park.getY() - 0.02) {
            car.move({0, speed});
        }
    }
    else if (park.getY() < 0.225 && a == 2) {
        if (car.getAnchor().getY() >= park.getY() + 0.02) {
            car.move({0, -speed});
        }
    }
    n++;
    gate.draw();
    car.draw();
}


void randomcolor(float *R, float *G, float *B) {
    *R = (float) rand() / RAND_MAX;
    *G = (float) rand() / RAND_MAX;
    *B = (float) rand() / RAND_MAX;
}
