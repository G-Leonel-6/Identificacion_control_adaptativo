// pendulum.cpp
#include "pendulum.h"

void step_discrete(const double Ad[4][4], const double Bd[4],
                   const double x[4], double u, double x_next[4]) {
    for (int i = 0; i < 4; i++) {
        double sum = 0.0;
        for (int j = 0; j < 4; j++) {
            sum += Ad[i][j] * x[j];
        }
        x_next[i] = sum + Bd[i] * u;
    }
}
