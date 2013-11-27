#include <Wire.h>
#include <BH1750.h>

BH1750 lux ;

void setup() {
  Serial.begin(9600);
  lux.BH1750_Init();
  delay(1000);
}
void loop() {
  Serial.print(lux.lux_val());
  Serial.println("(lx)");
  delay(5000);
}
