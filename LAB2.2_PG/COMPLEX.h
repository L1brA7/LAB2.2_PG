#include <iostream>

using namespace std;

class COMPLEX {
    private:
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
        void set_re();
        void set_im();
        int get_re();
        int get_im();
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
        friend istream& operator>>(istream &in, COMPLEX &cn);
        friend ostream& operator<<(ostream &out, COMPLEX &cn);
};

float COMPLEX::module() {
    return sqrt(real * real + img * img);
}

void COMPLEX::set_re() {
    printf("Enter the real part - ");
    cin >> real;
}

void COMPLEX::set_im() {
    printf("Enter the imaginary part - ");
    cin >> img;
}

int COMPLEX::get_re() {
    return real;
}

int COMPLEX::get_im() {
    return img;
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

istream& operator>>(istream& in, COMPLEX& cn) {
    in >> cn.real;
    in >> cn.img;
    return in;
}

ostream& operator<<(ostream& out, COMPLEX& cn) {
    out << "(" << cn.real << " + " << cn.img << "i)";
    return out;
}