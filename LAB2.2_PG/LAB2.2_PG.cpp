#include <iostream>
#include <iomanip>
#include "COMPLEX.h"
#include "VECTOR.h"
using namespace std;

int main() {
    
    COMPLEX num1(2, 3), num2(3, 5), num3, num4(num1);
    cout << num3 << " - default" << endl;
    cout << num4 << " - from sample(num1 = 2 + 3i)" << endl;
    num3 = num1 + num2;
    cout << num3 << " = num1 + num2" << endl;
    num3 = num1 - num2;
    cout << num3 << " = num1 - num2" << endl;
    num3 = num1 * num2;
    cout << num3 << " = num1 * num2" << endl;
    cout << (num1 > num2) << " = num1 < num2" << endl;
    cout << (num1 < num2) << " = num1 > num2" << endl;
    cout << (num1 == num2)<< " = num1 == num2" << endl;
    cout << (num1 != num2)<< " = num1 != num2" << endl;
    cin >> num3;
    cout << num3 << "- num3 from cin"<< endl;
    cout << "set and get for real number (for img are same):" << endl;
    num3.set_re();
    cout << num3.get_re() << endl;
    
    cout << fixed << setprecision(2);
    VECTOR null;
    cout << null << " - default null vector" << endl;
    VECTOR V1(10);
    cout << V1 << " - empty vector with length" << endl;
    float arr[3] = {2.4333, 3.2, 4.0};
    VECTOR V2(arr);
    cout << V2 << " - vector from array" << endl;
    VECTOR V3(V2);
    cout << V3 << " - vector from sample" << endl;
    V2 = V2 + V3;
    cout << V2 << " V2 = V2 + V3" << endl;
    V2 = V2 - V3;
    cout << V2 << " V2 = V2 - V3" << endl;
    V2 = V2 * 2;
    cout << V2 << " V2 = V2 * 2" << endl;
    float scal = V2 * V3;
    cout << scal << " = V2 * V3" << endl;

    VECTOR V4;
    cin >> V4;
    cout << V4 << endl;

    VECTOR V5;
    cin >> V5;
    cout << V5 << endl;

    cout << (V4 ^ V5) << " - angle between vectors created by cin"<< endl;

    return 0;
}