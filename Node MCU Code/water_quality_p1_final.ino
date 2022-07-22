#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Servo.h>

#define SensorPin A0  // the pH meter Analog output is connected with the Arduino’s Analog
int FloatSensor = 5;//D1
int FloatSensor2 = 0;//D3
int light = 9; //SD2
int fan = 10; //SD3

int x = 0;
int y = 0;
int z = 0;
int a = 0;
int f = 0;
int k = 0;
int l = 0;

int buttonState = 1; //reads pushbutton status
int buttonState1 = 1; //reads pushbutton status
int dinputstate = 0;
unsigned long int avgValue;  //Store the average value of the sensor feedback
float b;
int buf[10], temp;
const int oneWireBus = 4;

char auth[] = "ITaapbhbY--eF-Lu5xp5bofvittirhmK";       // You should get Auth Token in the Blynk App.
char ssid[] = "SLT_FIBRE";                       // Your WiFi credentials.
char pass[] = "abc12345";



OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);
Servo servo;

void setup()
{

  Serial.begin(115200); // Dubugging on hardware Serial 0
  Blynk.begin(auth, ssid, pass);
  sensors.begin();
  servo.attach(14); //D5
  pinMode(FloatSensor, INPUT_PULLUP);//d1
  pinMode(FloatSensor2, INPUT_PULLUP);//d3
  pinMode(light, OUTPUT);
  pinMode(fan, OUTPUT);
  digitalWrite(light, HIGH);
  digitalWrite(fan, HIGH);

}
void loop()
{
  Blynk.run();
  for (int i = 0; i < 10; i++) //Get 10 sample value from the sensor for smooth the value
  {
    buf[i] = analogRead(SensorPin);
    delay(10);
  }
  for (int i = 0; i < 9; i++) //sort the analog from small to large
  {
    for (int j = i + 1; j < 10; j++)
    {
      if (buf[i] > buf[j])
      {
        temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
      }
    }
  }
  avgValue = 0;
  for (int i = 2; i < 8; i++)               //take the average value of 6 center sample
    avgValue += buf[i];
  float phValue = (float)avgValue * 5.0 / 1024 / 6; //convert the analog into millivolt
  phValue = 3.5 * phValue; //convert the millivolt into pH value

  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);

  buttonState = digitalRead(FloatSensor);
  buttonState1 = digitalRead(FloatSensor2);
  //inside motor
  if (phValue < 4) //BOTTOM SWITCH
  {
    if (z == 0)
    {
      Blynk.notify("INSIDE MOTOR ON");
      z = 1;
    }
  }
  if (phValue < 4) //BOTTOM SWITCH
  {
    if (z == 1) {
  
      Blynk.notify("INSIDE MOTOR OFF");
    }
    z = 0;
  }
  //outside motor
  if (phValue < 4) //BOTTOM SWITCH
  {
    if (a == 0) {
  
      Blynk.notify("OUTSIDE MOTOR ON");
      a = 1;
    }
  }
  if (phValue > 4) //TOP SWITCH
  {
    if (a == 1) {
      Blynk.notify("OUTSIDE MOTOR OFF");
      a = 0;
    }
  }

  if (phValue > 5.5 && phValue < 6.5)
  {
    if (f == 0) {
      Blynk.notify("PH VALUE STABLEING..");
      f = 1;
    }
  }
  if (phValue > 7 && phValue < 7.70)
  {
    if (f ==1) {
      Blynk.notify("PH VALUE STABLED..");
      f = 0;
    }
  }

  //fan
  if (temperatureC > 32) {
    if (y == 0)
    {
      digitalWrite(fan, LOW);
      Blynk.notify("FAN ON");
      y = 1;
    }
  }

  if (temperatureC < 32) {
    if (y == 1)
    {
      digitalWrite(fan, HIGH);
      Blynk.notify("FAN OFF");
      y = 0;
    }
  }
  ///LIGHT
  if (temperatureC < 26) {
    if (x == 0)
    {
      digitalWrite(light, LOW);
      Blynk.notify("LIGHT ON");
      x = 1;
    }
  }

  if (temperatureC > 26) {
    if (x == 1)
    {
      digitalWrite(light, HIGH);
      Blynk.notify("LIGHT OFF");
      x = 0;
    }
  }

  Serial.print(f);

  //  Serial.print("    pH:");
  //  Serial.print(phValue, 2);
  //  Serial.println(" ");
  //  delay(2000);

  Blynk.virtualWrite(V1, phValue);
  Blynk.virtualWrite(V2, temperatureC);

}
BLYNK_WRITE(V3)
{
  servo.write(0);
}
BLYNK_WRITE(V4)
{
  servo.write(150);
}

BLYNK_WRITE(V7)
{
    Blynk.notify("MORTOR MANUAL OFF");
}
  
