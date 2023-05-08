#include <iostream>

using namespace std;

class Cross {
private:
    int a;
    int b;
public:
    Cross() {
        a = 0;
        b = 0;
    }

    Cross(int a, int b) {
        this->a = a;
        this->b = b;
    }

    void setA(int a) {
        this->a = a;
    }

    void setB(int b) {
        this->b = b;
    }

    int getA() {
        return a;
    }

    int getB() {
        return b;
    }

    int getArea() {
        return a * b;
    }

    Cross operator+(Cross c) {
        return Cross(a + c.a, b + c.b);
    }

    Cross operator++() {
        a++;
        b++;
        return *this;
    }

    Cross operator++(int) {
        Cross c(*this);
        a++;
        b++;
        return c;
    }

    friend ostream& operator<<(ostream& os, Cross& c) {
        os << "a = " << c.a << ", b = " << c.b << ", area = " << c.getArea();
        return os;
    }
};

int main() {
    Cross c1(5, 10);
    Cross c2(3, 8);

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;

    Cross c3 = c1 + c2;
    cout << "c3 (c1 + c2): " << c3 << endl;

    c3++;
    cout << "c3 (after increment): " << c3 << endl;

    ++c3;
    cout << "c3 (after increment): " << c3 << endl;

    return 0;
}
