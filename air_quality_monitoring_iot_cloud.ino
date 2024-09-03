#include "thingProperties.h"

int sensorAQ = 32;
int hydrogen = 33;
int methane = 34;
int carbonmono = 35;

int airQualityValue;
float hydrogenValue;
float methaneValue;
float carbonMonoxideValue;


void setup() {
  
  Serial.begin(115200);
  delay(1500); 
  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  int airQualityRaw = analogRead(sensorAQ);
  float hydrogenRaw = analogRead(hydrogen);
  float methaneRaw = analogRead(methane);
  float carbonMonoRaw = analogRead(carbonmono);

  airQualityValue = (map(airQualityRaw, 0, 1023, 0, 300))-100;
  hydrogenValue = map(hydrogenRaw, 0, 1023, 0, 8000);
  methaneValue = map(methaneRaw, 0, 1023, 0, 8000);
  carbonMonoxideValue = map(carbonMonoRaw, 0, 1023, 0, 2000);
  
  aq=airQualityValue;
  cm=carbonMonoxideValue;
  hy=hydrogenValue;
  met=methaneValue;

  msg="\nAir Quality Value: "+ (String)airQualityValue+ "\nHydrogen (ppm): " + (String)hydrogenValue + " \nMethane (ppm): " + (String)methaneValue+ " \nCarbon Monoxide (ppm): " + (String)carbonMonoxideValue; 
  
  Serial.print("Air Quality Value: ");
  Serial.println(airQualityValue);
  
  Serial.print("Hydrogen (ppm): ");
  Serial.println(hydrogenValue);
  
  Serial.print("Methane (ppm): ");
  Serial.println(methaneValue);
  
  Serial.print("Carbon Monoxide (ppm): ");
  Serial.println(carbonMonoxideValue);
  delay(1000);
  
}
/*
  Since Aq is READ_WRITE variable, onAqChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onAqChange()  {
}

void onHyChange()  {
}

void onMetChange()  {
}

void onCmChange()  {
}


void onMsgChange()  {
}


