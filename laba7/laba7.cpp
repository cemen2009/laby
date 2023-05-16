#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Triangle {
protected:
    double side1, side2, angle;
public:
    Triangle(double s1, double s2, double a) : side1(s1), side2(s2), angle(a) {}
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double s) : Triangle(s, s, 60) {}
    double getArea() override {
        return 0.25 * sqrt(3) * pow(side1, 2);
    }
    double getPerimeter() override {
        return 3 * side1;
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(double s, double a) : Triangle(s, s, a) {}
    double getArea() override {
        return 0.5 * side1 * sqrt(pow(side2, 2) - pow(0.5 * side1, 2));
    }
    double getPerimeter() override {
        return 2 * side1 + side2;
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle(double s1, double s2) : Triangle(s1, s2, 90) {}
    double getArea() override {
        return 0.5 * side1 * side2;
    }
    double getPerimeter() override {
        return side1 + side2 + sqrt(pow(side1, 2) + pow(side2, 2));
    }
};

int main() {
    vector<Triangle*> triangles;
    triangles.push_back(new EquilateralTriangle(4));
    triangles.push_back(new IsoscelesTriangle(3, 60));
    triangles.push_back(new RightTriangle(3, 4));

    double totalArea = 0;
    for (auto triangle : triangles) {
        cout << "Area: " << triangle->getArea() << endl;
        cout << "Perimeter: " << triangle->getPerimeter() << endl;
        totalArea += triangle->getArea();
    }

    cout << "Total area of all triangles: " << totalArea << endl;

    // Clean up memory
    for (auto triangle : triangles) {
        delete triangle;
    }
    return 0;
}
