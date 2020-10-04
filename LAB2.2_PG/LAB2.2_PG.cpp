#include <iostream>
#include "COMPLEX.h"
#include "VECTOR.h"
using namespace std;

int main() {
    //добавить пример копирования из числа в число
    
    /*COMPLEX num1(2, 3), num2(3, 5), num3;
    num3.set();
    cout << num3 << endl;
    num3 = num1 + num2;
    cout << num3 << endl;
    num3 = num1 - num2;
    cout << num3 << endl;
    num3 = num1 * num2;
    cout << num3 << endl;
    cout << (num1 > num2) << endl;
    cout << (num1 < num2) << endl;
    cout << (num1 == num2) << endl;
    cout << (num1 != num2) << endl;
    cin >> num3;
    cout << num3 << endl;*/
    
    
    /*VECTOR vectr;
    vectr.set();
    cout << vectr << endl;*/

    VECTOR vectr2(4);
    cout << "Enter vector's coordinates\n";
    cin >> vectr2;
    cout << vectr2 << endl;
    
    /*VECTOR vectr3(vectr2);
    cout << vectr3 << endl;*/

    return 0;
}