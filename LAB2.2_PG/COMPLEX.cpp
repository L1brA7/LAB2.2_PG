#include <iostream>

using namespace std;

class COMPLEX {
    int real, img;
    public:
        COMPLEX() {
            real = 0; img = 0;
        }
        COMPLEX(int r, int i) {
            real = r; img = i;
        }
        COMPLEX(COMPLEX& SAMPLE) {
            real = SAMPLE.real;
            img = SAMPLE.img;
        }
        float module();
        void set();
        void get();
        COMPLEX operator+(COMPLEX& cn2);
        COMPLEX operator-(COMPLEX& cn2);
        //z=z1⋅z2=(a1a2−b1b2)+(a1b2+b1a2)i
        COMPLEX operator*(COMPLEX& cn2);
        friend bool operator>(COMPLEX& left, COMPLEX& right);
        friend bool operator<(COMPLEX& left, COMPLEX& right);
        friend bool operator==(COMPLEX& left, COMPLEX& right);
        friend bool operator!=(COMPLEX& left, COMPLEX& right);
        friend bool operator<=(COMPLEX& left, COMPLEX& right);
        friend bool operator>=(COMPLEX& left, COMPLEX& right);
        friend istream& operator>>(istream &in, COMPLEX &c);
        friend ostream& operator<<(ostream &out, COMPLEX &c);
};

float COMPLEX::module() {
    return sqrt(real * real + img * img);
}

void COMPLEX::set() {
    printf("Enter the real part - ");
    cin >> real;
    printf("Enter the imaginary part - ");
    cin >> img;
}

void COMPLEX::get() {
    printf("(%i, %ii)", real, img);
}


COMPLEX COMPLEX::operator+(COMPLEX& cn2) {
    COMPLEX sum;
    sum.real = real + cn2.real;
    sum.img = img + cn2.img;
    return sum;
}

COMPLEX COMPLEX::operator-(COMPLEX& cn2) {
    COMPLEX sub;
    sub.real = real - cn2.real;
    sub.img = img - cn2.img;
    return sub;
}

COMPLEX COMPLEX::operator*(COMPLEX& cn2) { 
    COMPLEX comp;
    comp.real = real * cn2.real - img * cn2.img;
    comp.img = real * cn2.img + cn2.real * img;
    return comp;
}

bool operator>(COMPLEX& left, COMPLEX& right) {
    return left.module() > right.module();
}

bool operator<(COMPLEX& left, COMPLEX& right) {
    return left.module() < right.module();
}

bool operator==(COMPLEX& left, COMPLEX& right) {
    return left.module() == right.module();
}

bool operator!=(COMPLEX& left, COMPLEX& right) {
    return left.module() != right.module();
}

bool operator<=(COMPLEX& left, COMPLEX& right) {
    return left.module() <= right.module();
}

bool operator>=(COMPLEX& left, COMPLEX& right) {
    return left.module() >= right.module();
}