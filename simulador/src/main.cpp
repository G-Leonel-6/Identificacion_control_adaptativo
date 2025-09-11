#include <Arduino.h>
#include "pendulum.h"

// Estado inicial [x, dx, theta, dtheta]
double state[4] = {0.0, 0.0, 0.1, 0.0};  

// Matriz A_d y B_d calculadas offline en Python y copiadas acá
const double Ad[4][4] = {
    {1.0, 0.0995024709, 0.00480129762, 0.000161339966},
    {0.0, 0.990082021, 0.0941298848, 0.00480129762},
    {0.0, 0.000978857822, 0.894048773, 0.0964424206},
    {0.0, 0.0191905983, -2.08046006, 0.894048773}
};
const double Bd[4] = {0.00497529, 0.09917979, -0.00978858, -0.19190598};

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

  Serial.println(state[3]);

  // Mostrar por serial
  Serial.print(">x:");
  Serial.println(state[0],4);

  Serial.print(">dx:");
  Serial.println(state[1],4);

  Serial.print(">theta:");
  Serial.println(state[2],4);

  Serial.print(">dtheta:");
  Serial.println(state[3],4);

  delay(100);  // 10 ms ≈ Ts
}
