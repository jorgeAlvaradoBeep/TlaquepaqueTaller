#include "IRremote.h"
#include <Motor.h>
Motor motora = Motor(5, 6);
Motor motorb = Motor(7, 8);
int receiver = 11;

IRrecv irrecv(receiver);
uint32_t results;
bool activate = false;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}


void loop()
{
  if (irrecv.decode())
  {
    results = irrecv.decodedIRData.decodedRawData;
    Serial.println(results);
    activate = true;
    switch (results)
    {
      case 3877175040: Serial.println("Tecla: Arriba");
        motora.MoveFoward();
        motorb.MoveFoward();
        break;
      case 2774204160: Serial.println("Tecla: Derecha");
        motora.MoveFoward();
        motorb.MoveBackward();
        break;
      case 2907897600: Serial.println("Tecla: Abajo");
        motorb.MoveBackward();
        motora.MoveBackward();
        break;
      case 4144561920: Serial.println("Tecla: Izquierda");
        motora.MoveBackward();
        motorb.MoveFoward();
        break;
    }
    irrecv.resume();
  }
  else
  {
    if (activate)
    {
      Serial.println("Stop");
      motora.Stop();
      motorb.Stop();
      activate = false;
    }
  }
  delay(300);
}
