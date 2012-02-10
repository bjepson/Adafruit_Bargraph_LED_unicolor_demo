#include "BarGraph.h"


int counter = 0;
long last;
int direction = 1;

BarGraph bargraph;

void setup() {
  Serial.begin(9600);
  bargraph.setStartPin(2);
  bargraph.setValue(counter);
  last = millis();
}

void loop() {

  if (millis() > last + 250) {

    last = millis();
    counter += direction;
    bargraph.setValue(counter);

    if (counter == 12) {
      direction = -1;
    } 
    if (counter == 0) {
      direction = 1;
    }

  }

  bargraph.light();

}



