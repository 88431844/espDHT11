#include "DHTesp.h"

DHTesp dht;


void setup(){
  Serial.begin(115200);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)\tHeatIndex (C)\t(F)");

  dht.setup(2, DHTesp::DHT11); // Connect DHT sensor to GPIO 2(D4)
}

void loop()
{
 delay(dht.getMinimumSamplingPeriod());

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

Serial.print("-----------");
  Serial.println(dht.getStatusString());
  Serial.print(humidity, 1);
  Serial.print(",");
  Serial.print(temperature, 1);
  delay(2000);
}



//#include "DHT.h" //DHT sensor
//#define DHTTYPE DHT11
//uint8_t DHTPin = 2;
//
//// Initialize DHT sensor.
//DHT dht(DHTPin, DHTTYPE);
//
//float Temperature;
//float Humidity;
//
//void setup() {
//  Serial.begin(115200);
//  delay(100);
//
//  pinMode(DHTPin, INPUT);
//
//  dht.begin();
//
//  Serial.println("Connecting to ");
//
//
//}
//void loop() {
//  Temperature = dht.readTemperature(); // Gets the values of the temperature
//  Humidity = dht.readHumidity(); // Gets the values of the humidity
//  Serial.println("------------");
//  Serial.println("Temperature£º"+String(Temperature));
//  Serial.println("Humidity:"+String(Humidity));
//  delay(2000);
//}
