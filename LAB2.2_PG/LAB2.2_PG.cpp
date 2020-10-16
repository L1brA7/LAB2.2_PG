#include <iostream>
#include <iomanip>
#include "COMPLEX.h"
#include "VECTOR.h"
using namespace std;

void enter();
void num_changer(int* N);

int main() {
    int number;
    num_changer(&number);
    while (number) {
        if (number == 1) {
            enter();
            COMPLEX num1(2, 3), num2(3, 5), num3, num4(num1);
            cout << num1 << " - num1" << endl;
            cout << num2 << " - num2" << endl;
            cout << num3 << " - default" << endl;
            cout << num4 << " - from sample(num1 = 2 + 3i)" << endl;
            enter();
            num3 = num1 + num2;
            cout << num3 << " = num1 + num2" << endl;
            num3 = num1 - num2;
            cout << num3 << " = num1 - num2" << endl;
            num3 = num1 * num2;
            cout << num3 << " = num1 * num2" << endl;
            enter();
            cout << (num1 > num2) << " = num1 > num2" << endl;
            cout << (num1 < num2) << " = num1 < num2" << endl;
            cout << (num1 == num2) << " = num1 == num2" << endl;
            cout << (num1 != num2) << " = num1 != num2" << endl;
            enter();
            cin >> num3;
            cout << num3 << "- num3 from cin" << endl;
            enter();
            cout << "set and get for real number (for img are same):" << endl;
            num3.set_re();
            cout << num3.get_re() << endl;
        }
        if (number == 2) {
            enter();
            cout << fixed << setprecision(2);
            VECTOR null;
            cout << null << " - default null vector" << endl;
            VECTOR V1(10);
            cout << V1 << " - empty vector with length - V1" << endl;
            float arr[3] = { 2.4333, 3.2, 4.0 };
            VECTOR V2(arr);
            cout << V2 << " - vector from array - V2" << endl;
            VECTOR V3(V2);
            cout << V3 << " - vector from sample - V3" << endl;
            enter();
            cout << (V2 < V3) << " = V2 < V3" << endl;
            cout << (V2 > V3) << " = V2 > V3" << endl;
            cout << (V2 == V3) << " = V2 == V3" << endl;
            cout << (V2 != V3) << " = V2 != V3" << endl;
            enter();
            V2 = V2 + V3;
            cout << V2 << " V2 = V2 + V3" << endl;
            V2 = V2 - V3;
            cout << V2 << " V2 = V2 - V3" << endl;
            V2 = V2 * 2;
            cout << V2 << " V2 = V2 * 2" << endl;
            float scal = V2 * V3;
            cout << scal << " = V2 * V3" << endl;
            enter();
            VECTOR V4, V5;
            cin >> V4;
            cout << V4 << endl;
            cin >> V5;
            cout << V5 << endl;
            enter();
            cout << (V4 ^ V5) << " - angle between vectors created by cin" << endl;
        }
        num_changer(&number);
    }
    return 0;
}

void num_changer(int* N) {
    cout << "Enter the number or 0 to close - ";
    cin >> *N;
}

void enter() {
    printf("\n");
}