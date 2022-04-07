#include "DHT.h"
#define DHT11PIN 16

const int greenled=13;
const int blueled=12;
const int redled=14;

DHT dht(DHT11PIN, DHT11);
void setup()
{
  
  Serial.begin(115200);
/* Start the DHT11 Sensor */
  dht.begin();
  pinMode(greenled, OUTPUT); //green led
  pinMode(blueled, OUTPUT); //blue led
  pinMode(redled, OUTPUT); //red led
}

void loop()
{
  float humi = dht.readHumidity();
  float temp = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("ºC ");
  if(temp>=20 && temp<=30){
      digitalWrite(greenled, HIGH);
      digitalWrite(blueled, LOW);
      digitalWrite(redled, LOW);
      Serial.println(" Cold");
  }
  else if(temp>=31 && temp<=40){
      digitalWrite(greenled, LOW );
      digitalWrite(blueled, HIGH);
      digitalWrite(redled, LOW );
      Serial.println(" Moderate");
  }
  else if(temp>=41 && temp<=50){
      digitalWrite(greenled, LOW);
      digitalWrite(blueled, LOW);
      digitalWrite(redled, HIGH);
      Serial.println("Hot");
  }
  Serial.print("Humidity: ");
  Serial.println(humi);
  delay(1000);
}
