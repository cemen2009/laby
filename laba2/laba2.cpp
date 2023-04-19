#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

class trapeze{
    private:
    float a;
    float b;
    float c;
    float* d = &c;
    float height;

    public:
    trapeze(){
        this->a, this->b, this->c = 0; 
        this->height = getHeight();
    }

    trapeze(float a, float b, float c){
        this->a = a;
        this->b = b;
        this->c = c;
        this->height = getHeight();
    }

    float getHeight(){
        if (this->a == 0 || this->b == 0 || this->c == 0){
            cout << "Height can't be reached if any of side equal to zero." << endl;
            return 0;
        }

        float catet1 = (this->b - this->a) / 2;
        float height = sqrt(pow(this->c, 2) - pow(catet1, 2));

        return height;
    }

    float getA(){
        return this->a;
    }

    void setA(float a){
        if (a > 0){
            this->a = a;
        }
    }

    float getB(){
        return this->b;
    }

    void setB(float b){
        if (b > 0){
            this->b = b;
        }
    }

    float getLateralSide(){
        return this->c;
    }

    void setLateralSide(float c){
        if (c > 0){
            this->c = c;
        }
    }

    float getArea(){
        if (this->height == 0){
            cout << "No data." << endl;
            return 0;
        }
        float S = ( (this->a + this->b) / 2 ) * this->height;

        return S;
    }

    void print_sqrt(){
        cout << "A: " << this->a << "\nB: " << this->b << "\nHeight: " << this->height << "\nArea: " << this->getArea() << endl;
    }

    friend trapeze frd(trapeze t0, trapeze t1){
        trapeze newT(t0.a + t1.a, t0.b + t1.b, t0.c + t1.c);

        return newT;
    }
};

int main(){
    trapeze t0(4, 10, 5);
    trapeze t1(10, 16, 5);
    
    cout << t0.getHeight() << endl;
    cout << "t0 S = " << t0.getArea() << "\nt1 S = " << t1.getArea() << "\n\n";

    cout << frd(t0, t1).getArea() << endl;

    return 0;
}