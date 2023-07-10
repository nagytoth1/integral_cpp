#ifndef INTEGRALAS_INTEGRALAS_H
#define INTEGRALAS_INTEGRALAS_H

#include <iostream>

class Integralas{
public:
    Integralas(float a, float  b, float (*fgv)(float), uint16_t n);
    Integralas(float a, float  b, float (*fgv)(float));

    float elvegez_montecarlo();

    float elvegez_teglalapmodszer();

    float elvegez_trapezmodszer();

    float elvegez_simpson();

private:
    float a_m, b_m;
    uint16_t n_m;
    float (*fgv_m)(float);
};

#endif //INTEGRALAS_INTEGRALAS_H
