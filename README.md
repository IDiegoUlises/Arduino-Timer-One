# Arduino Timer One

Un timer genera una interrupcion para ejecutar funciones independiente al procesador utilizando internamente el cristal de cuarzo de 16 megahertz para funcionar y utilizar las funciones de tiempo.

**Timer 0 Arduino:** Es de 8 bits usado para las funciones ```delay()```, ```millis()```, ```micros()``` no utilizar este timer si utilizas las funciones de tiempo anteriores.

**Timer 1 Arduino:** Es de 16 bits usado por la libreria servo en arduino uno si no estas controlado servos puedes usar este timer 1 arduino libremente.

**Timer 2 Arduino:** Es de 8 bits usado en la función tone() si no usas esta funcion puedes emplear el timer 2 arduino libremente para otra aplicación.

**Timer 3, 4, 5 (Arduino Mega):** Solo disponible en el arduino mega son de de 16 bits mayormente utilizados principalmente para el control de servos sino utilizas servos puedes usarlos libremente.

```c++ 
#include <TimerOne.h>
volatile int tiempo = 0;

void setup()
{
  Timer1.initialize(1000000); //En microsegundos
  Timer1.attachInterrupt(funcion);
  Serial.begin(9600);
}

void funcion()
{
  tiempo++;
}

void loop()
{
  Serial.println(tiempo);
}
```
