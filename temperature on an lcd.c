#include <OneWire.h>
#include <LiquidCrystal.h>

#define ONE_WIRE_BUS 8
OneWire oneWire(ONE_WIRE_BUS);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float potPin = 8;
void setup(void)
{
  Serial.begin(9600);
  //sensors.begin();
  lcd.begin(16, 2);
  
}

void loop(void){ 

  int val; 
  float temp; 
  float cTemp;
  float fTemp;

  val = analogRead(8);// read the analog value of the sensor and assign it to val
  cTemp = (128 * val) >> 8; 
  fTemp = (1.8 * cTemp) + 32; 
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp(C)");
  lcd.setCursor(10, 0);
  lcd.print(cTemp);

  lcd.setCursor(0, 1);
  lcd.print("Temp(F)");
  lcd.setCursor(10, 1);
  lcd.print(fTemp);
  
  delay(500);
}
