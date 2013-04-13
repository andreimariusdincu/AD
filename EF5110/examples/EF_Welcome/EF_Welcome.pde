
#include  <EF5110.h>

// digiatal 8  - SCE    You can change the define
// digiatal 9  - RST
// digiatal 10 - DC
// digiatal 11 - MOSI
// digiatal 12 - SCLK

EF_LCM5110  lcm(8,9,10,11,12);

void setup()
{
  lcm.init();
  lcm.clearLCM();
}

void loop()
{
  lcm.write_string(0,0,"Welecome to ");
  lcm.write_string(2,2," ElecFreaks");
  delay(1000);
}

