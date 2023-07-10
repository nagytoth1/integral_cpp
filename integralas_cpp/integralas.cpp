//
// Created by bence on 2023.07.03..
//

#include <vector>
#include <random>
#include <functional>
#include "integralas.h"

using namespace std;

Integralas::Integralas(float a, float b, float (*fgv)(float), uint16_t n):
    a_m(a), b_m(b), n_m(n), fgv_m(fgv) {}
Integralas::Integralas(float a, float  b, float (*fgv)(float)):
        Integralas(a,b,fgv, 10000){}

float Integralas::elvegez_montecarlo() {
    vector<int32_t> randomok(n_m);
    default_random_engine generator;
    cout << "alsó: "<<a_m<<"felső: " << b_m<<endl;
    uniform_int_distribution<int> distribution(a_m, b_m + 1);
    auto randomize = bind(distribution, generator);
    float sum = 0.0f;
    for (int i = 0; i < n_m; ++i){
        sum += fgv_m(randomize()) * b_m;
    }

    return sum / n_m;
    return 0;
}

float Integralas::elvegez_teglalapmodszer() {
    float x = a_m;
    float h = abs(b_m - a_m) / (float) n_m;
    float sum = 0.0f;
    while(x < b_m){
        sum += (h * fgv_m(x));
        x += h;
    }
    return sum;
}

float Integralas::elvegez_trapezmodszer() {
    float x = a_m;
    float h = abs(b_m - a_m) / (float) n_m;
    float sum = 0.0f;
    float elo = 0.0, akt = fgv_m(x);
    while(x < b_m){
        x += h;
        elo = akt;
        akt = fgv_m(x);
        sum += (elo + akt);
    }
    return sum * h / 2.0;
}

float Integralas::elvegez_simpson() {
    float h = abs(b_m - a_m) / (float) n_m;
    float x = a_m;
    float sum = 0.0;
    for(int i = 1; i < div(n_m,2).quot; ++i){
        sum = sum + 2 * fgv_m(x) + fgv_m(x+h);
        x += 2 * h;
    }
    return h / 3 * (2 * sum + fgv_m(a_m) + fgv_m(b_m) + 4 * fgv_m(b_m - h));
}
