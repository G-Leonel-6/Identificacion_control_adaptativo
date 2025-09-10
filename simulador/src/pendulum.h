// pendulum.h
#ifndef PENDULUM_H
#define PENDULUM_H

void step_discrete(const double Ad[4][4], const double Bd[4],
                   const double x[4], double u, double x_next[4]);

#endif
