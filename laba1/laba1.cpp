// input output + console i/o
#include <iostream>
#include <conio.h>

using namespace std;

class Cross{
    private:
    float a;
    float b;
    
    public:
    void SetSideA(float a){
        if (a <= 0) {
            cout << "Side can't be less than zero." << endl;
        }
        else {
            this->a = a;
        }
    }

    void SetSideB(float b){
        if (b <= 0) {
            cout << "Side can't be less than zero." << endl;
        }
        else {
            this->b = b;
        }
    }

    float GetSideA(){
        return a;
    }
    
    float GetSideB(){
        return b;
    }

    Cross(){
        cout << "Constructor without parameters was called." << endl;
        a = 0;
        b = 0;
    }

    Cross(float a, float b){
        cout << "Constructor with parameters was called." << endl;
        this->a = a;
        this->b = b;
    }

    ~Cross(){
        cout << "Destructor was called." << endl;
    }

    float AreaCalculate(){
        return this->a * this->b;
    }
};

int main(){

    Cross cross0(5, 10);    // новий клас
    cout << "Side A: " << cross0.GetSideA() << endl;
    cross0.SetSideA(10.5);  // нове значення сторони А
    cout << "Side A: " << cross0.GetSideA() << endl;
    cout << "Area of cross: " << cross0.AreaCalculate() << endl;

    return 0;
}