#include <Arduino.h>
#include "pendulum.h"

// Estado inicial [x, dx, theta, dtheta]
double state[4] = {0.0, 0.0, 0.1, 0.0};  

// Matriz A_d y B_d calculadas offline en Python y copiadas acá
const double Ad[4][4] = {
    {1.0, 0.0995, 0.0048, 0.00016},
    {0.0, 0.99, 0.094, 0.0048},
    {0.0, 0.00098, 0.89, 0.09},
    {0.0, 0.0191, -2.0, 0.894}
};
const double Bd[4] = {0.00497, 0.099, -0.0097, -0.191};

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Control de ejemplo: fuerza nulaá
  double u = 0.0;

  // Paso discreto del modelo
  double new_state[4];
  step_discrete(Ad, Bd, state, u, new_state);

  // Copiar el nuevo estado
  for (int i = 0; i < 4; i++) state[i] = new_state[i];

  // Mostrar por serial
  Serial.print("x:");
  Serial.println(state[0]);

  Serial.print("dx:");
  Serial.println(state[1]);

  Serial.print("theta:");
  Serial.println(state[2]);

  Serial.print("dtheta:p");
  Serial.println(state[3]);

  delay(10);  // 10 ms ≈ Ts
}
