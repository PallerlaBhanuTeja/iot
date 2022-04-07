#include "ThingSpeak.h"
#include "WiFi.h"

//-------Enter your WiFi Details------//
char ssid[] = "nikki2g";  //SSID
char pass[] = "yugandhar1968";  //Password

const int trigger = 5;
const int echo = 18;
long T;
float distanceCM;
WiFiClient client;

//------ThingSpeak Details-------//
unsigned long myChannelField = 1644777; //Channel ID
const int ChannelField1 = 3 ; //for Ultrasonic Data
const int ChannelField2 = 4; //for Time
const char * myWriteAPIKey = "MZWSJDWFDO4S5CZ9"; //Your Write API Key


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
  //----------WiFi Setup-------------//
    if(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print("Attempting to Connect to SSID: ");
    Serial.println(ssid);
    while(WiFi.status()!= WL_CONNECTED)
    {
    WiFi.begin(ssid,pass);
    Serial.print(".");
    delay(5000);
    }
  Serial.print("Connected\n");
  }

  digitalWrite(trigger, LOW);   // No input to Triggerpin(of Ultrasonic Sensor)
  delay(1);
  digitalWrite(trigger, HIGH); // Input provided to Triggerpin(of Ultrasonic Sensor)
  delayMicroseconds(10);
  digitalWrite(trigger, LOW); // No input to Triggerpin(of Ultrasonic Sensor)
  T = pulseIn(echo, HIGH);    // Receive signal from Echo pin(of Ultrasonic Sensor)
  distanceCM = (T * 0.034)/2;  // distance of object / obstacle calculated
  Serial.print("Distance in cm: ");
  Serial.println(distanceCM);

  ThingSpeak.writeField(myChannelField,ChannelField1, distanceCM, myWriteAPIKey);
  ThingSpeak.writeField(myChannelField,ChannelField2, T, myWriteAPIKey);
  delay(1000);
}
