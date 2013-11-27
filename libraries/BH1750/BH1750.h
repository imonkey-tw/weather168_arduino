#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include "Wire.h"


#define BH1750ADDR 0x23

class BH1750 {
 public:
 BH1750();
 void BH1750_Init(int address=BH1750ADDR);
 int BH1750_Read(int address=BH1750ADDR);
 byte buff[2];
 int lux_val(void);

};