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
