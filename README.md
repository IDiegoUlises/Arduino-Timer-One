# Arduino Timer One

Un timer genera una interrupcion para ejecutar funciones independiente al procesador utilizando internamente el cristal de cuarzo de 16 Megahertz para funcionar y utilizar las funciones de tiempo

**Timer 0 Arduino:** Es de 8 bits usado para las funciones delay(), millis(), micros() no utilzar este timer si utilizas las funciones de tiempo anteriores 

**Timer 1 Arduino:** Es de 16 bits usuado por la libreria servo en arduino uno se usa principalmente para el control de servos si no estas controlado servos, puedes usar este timer 1 arduino libremente.

**Timer 2 Arduino:** Es de 8 bits usado en la función tone() si no usas esta funcion puedes emplear el timer 2 arduino libremente para otra aplicación.

**Timer 3, 4, 5 (Arduino Mega):** Solo disponible en el Arduino Mega son de de 16bits Mayormente utilizados principalmente para el control de Servos, sin embargo también eres libre de usarlos como te convenga.




```c++ 
#include <TimerOne.h>
const int led = 13;  // the pin with a LED
int ledState = LOW;    // El LED empieza apagado
volatile int blinkCount = 0; // La definimos como volatile

void setup()
{
  pinMode(led, OUTPUT);
  Timer1.initialize(1000000);         // Dispara cada 1 segundo tiempo en microsegundos
  Timer1.attachInterrupt(ISR_Blink); // Activa la interrupcion y la asocia a ISR_Blink
}

void ISR_Blink()
{

  ledState = !ledState ;
  blinkCount++    ;     // Contador veces se enciende el LED
  digitalWrite(13,ledState);
}

void loop()
{
}
```

## prueba 2 lo que hace es apagar y prender el led pero ahora en el puerto serial cuenta el tiempo que lleva el arduino encendido. 
```c++
#include <TimerOne.h>
const int led = 13;  // the pin with a LED
int ledState = LOW;    // El LED empieza apagado
volatile int blinkCount = 0; // La definimos como volatile

void setup()
{
  pinMode(led, OUTPUT);
  Timer1.initialize(1000000);         // Dispara cada 1 segundo
  Timer1.attachInterrupt(ISR_Blink); // Activa la interrupcion y la asocia a ISR_Blink
  Serial.begin(9600);
}

void ISR_Blink()
{

  ledState = !ledState ;
  blinkCount++    ;     // Contador veces se enciende el LED
  digitalWrite(13,ledState);
}

void loop()
{
  Serial.println(blinkCount);
}


```
Conclusion se supone que el puerto serial se ejecuta en una interrupcion pero el timer tambien es una interrupcion, creo no estoy seguro que el timer es una interrupcion independiente es decir que no es afectada por otra interrupcion


## Usando el timer y el puerto serial al mismo tiempo, esta programado para que en 10 segundos se prenda un led y a la misma vez imprime en el puerto serial el tiempo de ejecucion
```C++
#include <TimerOne.h>
const int led = 13;  // the pin with a LED
int ledState = LOW;    // El LED empieza apagado
volatile int blinkCount = 0; // La definimos como volatile

void setup()
{
  pinMode(led, OUTPUT);
  Timer1.initialize(1000000);         // Dispara cada 1 segundo
  Timer1.attachInterrupt(ISR_Blink); // Activa la interrupcion y la asocia a ISR_Blink
  Serial.begin(9600);
}

void ISR_Blink()
{

  //ledState = !ledState ;
  blinkCount++    ;     // Contador veces se enciende el LED

  if (blinkCount == 10)
  {
    digitalWrite(13, HIGH);
  }

}

void loop()
{
  Serial.println(blinkCount);
}

```
### Cronometro cada vez que suceda 5 segundos se prendera el led y cuando pasen 5 segundos mas se apagara el led de manera infinita esto sirve para hacer un cronometro de tiempo
```c++
#include <TimerOne.h>
const int led = 13;  // the pin with a LED
volatile int ledState = LOW;    // El LED empieza apagado
volatile int blinkCount = 0; // La definimos como volatile

void setup()
{
  pinMode(led, OUTPUT);
  Timer1.initialize(1000000);         // Dispara cada 1 segundo
  Timer1.attachInterrupt(ISR_Blink); // Activa la interrupcion y la asocia a ISR_Blink
  Serial.begin(9600);
}

void ISR_Blink()
{

  ledState = !ledState ;
  blinkCount++    ;     // Contador veces se enciende el LED

  if (blinkCount == 5)
  {
    digitalWrite(led, ledState);
    blinkCount = 0;
  }

}

void loop()
{
  Serial.println(blinkCount);
}
```


### Prende y apaga un led, cuenta el tiempo de ejecucion ademas utiliza la funcion delay() demostrando de que usar delay no afecta el timer y cuenta el tiempo de manera normal
```c++

#include <TimerOne.h>
const int led = 13;  // the pin with a LED
int ledState = LOW;    // El LED empieza apagado
volatile int blinkCount = 0; // La definimos como volatile

void setup()
{
  pinMode(led, OUTPUT);
  Timer1.initialize(1000000);         // Dispara cada 1 segundo
  Timer1.attachInterrupt(ISR_Blink); // Activa la interrupcion y la asocia a ISR_Blink
  Serial.begin(9600);
}

void ISR_Blink()
{

  ledState = !ledState ;
  blinkCount++    ;     // Contador veces se enciende el LED
  digitalWrite(13,ledState);
}

void loop()
{
  Serial.println(blinkCount);
  delay(2000);
}
```
