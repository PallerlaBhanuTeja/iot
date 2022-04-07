// Turn ON PIEZO BUZZER every 2 seconds
const int buzz = 22;
void setup() {
  // put your setup code here, to run once:
pinMode(buzz,OUTPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(buzz,HIGH);
Serial.println("Buzzer ON\n");
delay(2000);

digitalWrite(buzz,LOW);
Serial.println("Buzzer ON\n");
delay(2000);
}
