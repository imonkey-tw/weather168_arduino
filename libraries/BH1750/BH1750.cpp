#include "BH1750.h"
#include "math.h"

BH1750::BH1750()
{
}

void BH1750::BH1750_Init(int address)
{
Wire.beginTransmission(address);
Wire.write(0x10);//1lx reolution 120ms
Wire.endTransmission();
delay(200);
}

int BH1750::BH1750_Read(int address) 
{
int i=0;
Wire.beginTransmission(address);
Wire.requestFrom(address, 2);

while(Wire.available()) //
{
buff[i] = Wire.read(); // receive one byte
i++;
}
Wire.endTransmission(); 
return i;
}

int BH1750::lux_val(void)
{
if(2==BH1750_Read(BH1750ADDR))
{
return int(((buff[0]<<8)|buff[1])/1.2);
}

return 0;
}