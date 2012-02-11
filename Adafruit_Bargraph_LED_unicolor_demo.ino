#include "BarGraph.h"


int counter = 0;
long last;
int direction = 1;

BarGraph bargraphA;
BarGraph bargraphB;
BarGraph bargraphC;

void setup() {
  Serial.begin(9600);

  bargraphA.setStartPin(26);
  bargraphA.setValue(counter);

  bargraphB.setStartPin(33);
  bargraphB.setValue(counter);

  bargraphC.setStartPin(40);
  bargraphC.setValue(counter);

  last = millis();
}

void loop() {

  if (millis() > last + 250) {

    last = millis();
    counter += direction;
    bargraphA.setValue(counter); 
    bargraphB.setValue(counter); 
    bargraphC.setValue(counter); 
    
    if (counter == 12) {
      direction = -1;
    } 
    if (counter == 0) {
      direction = 1;
    }

  }

  bargraphA.light(true);  
  bargraphB.light();
  bargraphC.light(true);
}



