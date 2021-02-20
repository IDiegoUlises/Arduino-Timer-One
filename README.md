# Arduino-Timer-One

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
}
