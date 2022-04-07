const int ldr=18;
const int led=20;
int val;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(ldr,INPUT);
pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
val=digitalRead(ldr);
Serial.println(val);

if(val==1500)
{
  digitalWrite(led,1);
  delay(1000);
}
else
{
  digitalWrite(led,0);
  delay(1000);  
}
}




if(event.temperature>=20 && event.temperature<=30)
    {
      digitalWrite(greenled,1);
      delay(1000); 
    }
    elseif(event.temperature>=31 && event.temperature<=40)
    {
      digitalWrite(blueled,1);
      delay(1000);
    }
    else(event.temperature>=41 && event.temperature<=50)
    {
      digitalWrite(redled,1);
      delay(1000);
    }
