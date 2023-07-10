#include <iostream>
#include <cmath>
#include "integralas.h"
using namespace std;

float f(float x){
    return x * x;
}

int main() {
    Integralas m(0, 10, f, 10000);
    float eredmeny = m.elvegez_montecarlo();
    float eredmeny2 = m.elvegez_teglalapmodszer();
    float eredmeny3 = m.elvegez_trapezmodszer();
    float eredmeny4 = m.elvegez_simpson();
    cout << eredmeny << endl;
    cout << eredmeny2 << endl;
    cout << eredmeny3 << endl;
    cout << eredmeny4 << endl;
    return 0;
}
