#ifndef FINAL_PROJECT_FIGURES_H
#define FINAL_PROJECT_FIGURES_H

#include <windows.h>
#include <cmath>
#include <GL/glut.h>
#include <ctime>

static const double PI = 3.1415926535;

class Vec {

private:
    float x, y;

public:

    Vec(float _x, float _y) {
        x = _x;
        y = _y;
    }

    Vec() {}

    float getX() { return x; }

    float getY() { return y; }

    Vec operator+(Vec v) { return Vec(x + v.getX(), y + v.getY()); }

    Vec operator-(Vec v) { return Vec(x - v.getX(), y - v.getY()); }

    Vec operator*(float k) { return Vec(k * x, k * y); }

    Vec operator*(Vec v) { return Vec(x * v.getX(), y * v.getY()); }

    Vec operator<<(float angle) {
        return Vec((float) (x * cos(angle) - y * sin(angle)), (float) (x * sin(angle) + y * cos(angle)));
    }

    Vec operator>>(float angle) {
        return Vec((float) (x * cos(-angle) - y * sin(-angle)), (float) (x * sin(-angle) + y * cos(-angle)));
    }
};

class Figure {
protected:
    Vec anchor;

public:
    Figure() : anchor(0, 0) {}

    virtual Vec getAnchor() { return anchor; }

    virtual void setAnchor(Vec a) { anchor = a; }

    virtual void draw() = 0;
    virtual void move(Vec dir) = 0;
    virtual void rotate(float angle) = 0;
    virtual void zoom(float k) = 0;

    virtual ~Figure() {}
};

class ColoredFig : public Figure {
public:
    void setcolor(float _r, float _g, float _b) {
        r = _r;
        g = _g;
        b = _b;
    }

    void move(Vec dir) {
        anchor = anchor + dir;
    };
protected:
    float r, g, b;
};

class Line : public ColoredFig {
protected:
    Vec p1, p2;
    int lw;
public:
    Line(Vec pt1 = {0, 0}, Vec pt2 = {.1, 0}, int linewidth = 1);

    void draw();
    void zoom(float t) {};
    void rotate(float a) {};
    void rotate(Vec p1, float a) {};
    void move(Vec dir) {};
};

class Triangle : public ColoredFig {
public:
    Triangle(Vec pt1 = {-.5, -.5}, Vec pt2 = {.5, .5}, Vec pt3 = {.5, 0}, float red = 0.96, float green = 0.87,
             float blue = 0);

    void draw();

    void zoom(float t);

    void rotate(float t) {
        p1 = p1 >> t;
        p2 = p2 >> t;
        p3 = p3 >> t;
    }

protected:
    Vec p1, p2, p3;
};

class Quadrilateral : public ColoredFig {
public:
    void rotate(float t) {
        p1 = p1 >> t;
        p2 = p2 >> t;
        p3 = p3 >> t;
        p4 = p4 >> t;
    };

    void zoom(float t) {
        p1 = p1 * t;
        p2 = p2 * t;
        p3 = p3 * t;
        p4 = p4 * t;
    }

    void _move(Vec dir) {
        p1 = p1 + dir;
        p2 = p2 + dir;
        p3 = p3 + dir;
        p4 = p4 + dir;
    }

protected:
    Vec p1, p2, p3, p4;
};

class Polygon1 : public ColoredFig {
protected:
    float rad;
    int side;
public:
    Polygon1(float radius = .5, int Side = 4, float red = 0, float green = 0, float blue = 0);

    void draw();
    void zoom(float t);

    virtual void rotate(float t) {};
};

class Rectangle1 : public Quadrilateral {
public:
    Rectangle1(Vec pt1 = {.5, .5}, float red = 0, float green = 0, float blue = 0);

    void draw();
};

class Trapezoid : public Quadrilateral {
public:
    Trapezoid(Vec pt1 = {-.5, -.5}, Vec pt2 = {.5, .5}, float red = 0, float green = 0, float blue = 0);

    void draw();
};


class Circle : public Polygon1 {

public:
    Circle(float radius = .5, float red = 0, float green = 0, float blue = 0);

    void draw();
    void zoom(float t);
    void rotate(float t) {};
};

class semiCircle : public Circle {
private:
    Vec p;

public:
    semiCircle(float radius = .5, float red = 0, float green = 0, float blue = 0);

    void draw();

    void rotate(float t) {
        p = p >> t;
    };
};

class Group : public Figure {
public:
    void move(Vec dir) {
        anchor = anchor + dir;
    };
};

class UFO : public Group {
protected:
    Vec p;
    semiCircle u;
    Trapezoid t1, t2;
    Vec l1, l2, r1, r2;
    float radius;
public:
    UFO(){};
    UFO(Vec p1, float r);

    void setUFO(Vec p1, float t);
    void draw();
    void zoom(float t) {};
    void rotate(float a);
};

class Car : public Group {
protected:
    Circle c1, c2;
    Vec p, v1, v2;
    Trapezoid t1;
    Rectangle1 rec1,rec2;
    Triangle tri1;
    float radius;
public:
    Car(Vec p1, float r);

    void draw();
    void zoom(float t) {};
    void rotate(float a);
    void rotate(Vec p1, float a);
    void move(Vec dir);

    Vec getAnchor();
};

class Rocket : public Group {
protected:
    Rectangle1 r1;
    Triangle tr1, tr2, tr3;
    Circle c1;
    float radius;
    Vec p;
    Trapezoid t1, t2;
public:
    Rocket(){};
    Rocket(Vec p1, float t);
    void setRocket(Vec p1, float t);
    void draw();
    void zoom(float t);
    void rotate(float a) {};
};

class map : public Group {
protected:
    Rectangle1 rec1;
    Vec p;
    Line myLine[17];
public:
    map();

    void draw();
    void zoom(float t);
    void rotate(float a);
    void rotate(Vec p1, float a);
    void move(Vec dir);
};

class Teleporter : public Group {
protected:
    Polygon1 pol1;
public:
    Teleporter(){};
    Teleporter(Vec pt, int Side, float R, float G, float B);

    void setTeleporter(Vec pt,int Side, float R,float G, float B);
    void draw();
    void zoom(float t) {};
    void rotate(float a) {};
    void rotate(Vec p1, float a) {};
    void move(Vec dir) {};
};

class star: public Group{
protected:
    Triangle myStar[4];
public:
    star();
    ~star(){};

    void setStar(Vec pt, float _scale);
    void draw();
    void zoom(float t);
    void rotate(float a) {};
};
class Arrow: public Group{
protected:
    Vec p;
    Triangle t1,t2,t3;
    float r;
public:
    Arrow(Vec p1={.5,.5},float scale=0.8,float R = 1, float G = 1, float B = 0);
    ~Arrow(){};
    void draw();
    void move(Vec dir){};
    void zoom(float t){};
    void rotate(float a);
    void setarrow(Vec p1);
    void arrowcolor(float R,float G , float B);
};
void logic(float speed,bool isMove);

#endif //FINAL_PROJECT_FIGURES_H
