#include <iostream>
using namespace std;

enum ColorCode {
    Red, Green, Blue
};

enum ShapeCode {
    CircleCode, SquareCode, RectangleCode
};

struct Point {
    int x;
    int y;
};


class Shape {
    public:
        Point positon;
        virtual void shapePrint() = 0;

        static Shape* create(ShapeCode code);
};


class Circle : public Shape {
    public:
        Circle() {}
        void shapePrint() { cout << "This object is circular." << endl; }
};

class Square : public Shape {
    public:
        Square() {}
        void shapePrint() { cout << "This object is square." << endl; }
};

class Rectangle : public Shape {
    public:
        void shapePrint() { cout << "This object is rectangular." << endl; }
};


Shape* Shape::create(ShapeCode code) {
    if (code == CircleCode) {
        return new Circle();
    } else if (code == SquareCode) {
        return new Square();
    } else if (code == RectangleCode) {
        return new Rectangle();
    } else {
        return nullptr;
    }
}


class Frame {
    public:
        Shape* shape;
        ColorCode color;

        Frame(ShapeCode shapeCode, ColorCode colorCode) {
            shape = Shape::create(shapeCode);
            color = colorCode;
        }
};


int main() {
    Frame f1 = Frame(CircleCode,Red);
    Frame f2 = Frame(SquareCode,Blue);

    f1.shape->shapePrint();
    cout << endl;
    f2.shape->shapePrint();
    
    return 0;
}