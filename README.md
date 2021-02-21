# Arduino Timer One

Un timer genera una interrupcion para ejecutar funciones independiente al procesador utilizando internamente el cristal de cuarzo de 16 megahertz para funcionar y utilizar las funciones de tiempo.

**Timer 0 Arduino:** Es de 8 bits usado para las funciones ```delay()```,```millis()```,```micros()```  si utilizas estas funciones tiempo no es recomendado utilizar este timer.

**Timer 1 Arduino:** Es de 16 bits usado por la libreria servo en arduino uno si no estas controlado servos puedes usar este timer 1 arduino libremente.

**Timer 2 Arduino:** Es de 8 bits usado en la función ```tone()``` si no usas esta funcion puedes emplear el timer 2 arduino libremente para otra aplicacion.

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
* Cada un segundo se ejecuta una interrupcion que incrementara el tiempo
* Se define como volatile para modificar variables en una interrupcion
* Se utiliza la interrupcion serial recordar que el timer es una interrupcion independiente ya que usa el cristal de cuarzo
* Se pueden utilizar la funciones de tiempo ```delay()```,```millis()```,```micros()``` sin afectar el tiempo
