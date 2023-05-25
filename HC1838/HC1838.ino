#include "IRremote.h"
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
    irrecv.resume();
  }
  delay(300);
}
