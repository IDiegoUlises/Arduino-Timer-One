# Arduino-Timer-One

Prueba 1 cada un segundo prende y apaga un led usando el timer..
Lo que sucede que cada 1 segundo ejecuta la interrupcion para realizar la acccion y aumentar el contador
```c++ 
#include <TimerOne.h>
const int led = 13;  // the pin with a LED
int ledState = LOW;    // El LED empieza apagado
volatile unsigned long blinkCount = 0; // La definimos como volatile

void setup(void)
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
volatile unsigned long blinkCount = 0; // La definimos como volatile

void setup(void)
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
