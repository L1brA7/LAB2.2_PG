#include <iostream>
using namespace std;

class VECTOR {
    private:
        float* vec;
        int leng;
    public:
        VECTOR() {
            vec = new float[0];
            leng = 0;
        }
        VECTOR(float* arr) {
            leng = sizeof(arr) / sizeof(arr[0]) + 1;
            vec = new float[leng];
            for (int i = 0; i < leng; i++) vec[i] = arr[i];
        }
        VECTOR(int L) {
            vec = (float*)calloc(L, sizeof(float));
            leng = L;
        }
        VECTOR(VECTOR& SAMPLE) {
            vec = new float[SAMPLE.leng];
            for(int i = 0; i < SAMPLE.leng; i++) {
                vec[i] = SAMPLE.vec[i];
            }
            leng = SAMPLE.leng;
        }
        ~VECTOR() {
            delete[]vec;
        }
        float module();
        void set_leng();
        void set_coord(int i);
        int get_leng();
        float get_coord(int i);
        VECTOR& operator+(VECTOR& V2);
        VECTOR& operator-(VECTOR& V2);
        float operator*(VECTOR& V2);
        VECTOR& operator*(float D);
        float operator^(VECTOR& V2);
        bool operator>(VECTOR& right);
        bool operator<(VECTOR& right);
        bool operator==(VECTOR& right);
        bool operator!=(VECTOR& right);
        friend istream& operator>>(istream& in, VECTOR& vector);
        friend ostream& operator<<(ostream &out, VECTOR &vector);
};

float VECTOR::module() {
    float sum = 0;
    for (int i = 0; i < leng; i++) {
        sum += vec[i] * vec[i];
    }
    return sqrt(sum);
}

void VECTOR::set_leng() {
    cout << "Enter length - ";
    cin >> leng;
}

void VECTOR::set_coord(int i) {
    if (i > leng || i <= 0) {
        cout << "ERROR no such coordinate number" << endl;
        return;
    }
    printf("Enter the coordinate %i - ", i);
    cin >> vec[i - 1];
}

int VECTOR::get_leng() {
    return leng;
}

float VECTOR::get_coord(int i) {
    if (i > leng || i <= 0) {
        cout << "ERROR no such coordinate number" << endl;
        return 0;
    }
    return vec[i - 1];
}

VECTOR& VECTOR::operator+(VECTOR& V2) {
    VECTOR null;
    if (leng == 0) return V2;
    if (V2.leng == 0) return null;
    if (leng != V2.leng) {
        cout << "ERROR Uneven vectors" << endl;
        return null;
    }
    for (int i = 0; i < leng; i++) vec[i] += V2.vec[i];
    return *this;
}

VECTOR& VECTOR::operator-(VECTOR& V2) {
    VECTOR null;
    if (leng == 0) return V2;
    if (V2.leng == 0) return null;
    if (leng != V2.leng) {
        cout << "ERROR Uneven vectors" << endl;
        return null;
    }
    for (int i = 0; i < leng; i++) vec[i] -= V2.vec[i];
    return *this;
}

float VECTOR::operator*(VECTOR& V2) {
    if (leng == 0 || V2.leng == 0) return 0;
    if (leng != V2.leng) {
        cout << "ERROR Uneven vectors" << endl;
        return 0;
    }
    float sum = 0;
    for (int i = 0; i < leng; i++) {
        sum += vec[i] * V2.vec[i];
    }
    return sum;
}

VECTOR& VECTOR::operator*(float D) {
    VECTOR null;
    if (leng == 0 || D == 0) return null;
    for (int i = 0; i < leng; i++) {
        vec[i] *= D;
    }
    return *this;
}

float VECTOR::operator^(VECTOR& V2) {
    
    float sum = 0;
    for (int i = 0; i < leng; i++) {
        sum += vec[i] * V2.vec[i];
    }
    return acos(sum / (module() * V2.module())) * 180.0 / 3.14;
}

bool VECTOR::operator>(VECTOR& right) {
    return module() > right.module();
}

bool VECTOR::operator<(VECTOR& right) {
    return module() < right.module();
}

bool VECTOR::operator==(VECTOR& right) {
    return module() == right.module();
}

bool VECTOR::operator!=(VECTOR& right) {
    return module() != right.module();
}

istream& operator>>(istream& in, VECTOR& vector) {
    in >> vector.leng;
    vector.vec = new float[vector.leng];
    for (int i = 0; i < vector.leng; i++) {
        printf("%i)", i + 1);
        in >> vector.vec[i];
    }
    return in;
}

ostream& operator<<(ostream &out, VECTOR &vector) {
    if (vector.leng == 0) return out << "0";
    out << "{";
    for(int i = 0; i < vector.leng; i++) {
        out << vector.vec[i];
        if(i != vector.leng - 1) out << ",";
    }
    out << "}";
    return out;
}