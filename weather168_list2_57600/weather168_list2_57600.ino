// light lcd on by hand.

#include <Wire.h>   //I2C library
#include <Adafruit_BMP085.h> // pressure and temperature sensor library (I2C)
#include <SHT2x.h> //SHT2x temperature and humidity sensor(I2C)
#include <BH1750.h>  //light sensor library (I2C)
#include <LiquidCrystal_I2C.h> //LCD1602 display (I2C)


LiquidCrystal_I2C lcd(0x27,16,2);
Adafruit_BMP085 bmp;
BH1750 lux ;
SHT2xClass SHT20 ;

float altitude_0=0 ; //set altitude to zero point
float temperature_SHT20;
float humidity_SHT20;
float temperature_BMP;
float pressure_BMP;
float altitude_BMP;
unsigned int lux_BH1750=0;

void setup()
{
   Serial.begin(57600);
   Wire.begin();
   bmp.begin();
   lux.BH1750_Init();
   lcd.init();                      
   lcd.backlight();
   lcd.clear();
   lcd.print("Sensors inital..");
   delay(1000);
   lcd.clear();
   
}

void loop()
{
   
  temperature_SHT20=SHT20.GetTemperature();
  humidity_SHT20=SHT20.GetHumidity();
  temperature_BMP=bmp.readTemperature();
  pressure_BMP=float(bmp.readPressure())/1000;
  altitude_BMP=bmp.readAltitude();
  lux_BH1750=lux.lux_val();
  

Serial.print("[");
Serial.print(temperature_SHT20,1);
Serial.print(",");
Serial.print(int(humidity_SHT20));
Serial.print(",");
Serial.print(pressure_BMP,2);
Serial.print(",");
Serial.print(lux_BH1750);
Serial.print("]");
Serial.println();
Serial.flush();

lcd.clear();
lcd.setCursor(1,0);
lcd.print(temperature_SHT20);
lcd.setCursor(5,0);
lcd.print(" ");
lcd.setCursor(6,0);
lcd.print((char)223);
lcd.print("C");

lcd.setCursor(10,0);
lcd.print(int(humidity_SHT20));
lcd.print(" %");
lcd.print("RH");

lcd.setCursor(0,1);
lcd.print(pressure_BMP);
lcd.setCursor(6,1);
lcd.print("kPa");

lcd.setCursor(10,1);
lcd.print(lux_BH1750);
lcd.print(" L");
 delay(1000);
 
 }

void serialEvent() {
  while (Serial.available()) {
    char inchar =(char)Serial.read();
    if (inchar=='0') {
      altitude_0=bmp.readAltitude(); //set altitude to 0
      }
    
 }
}

