// **** INCLUDES *****
#include <ESP8266WiFi.h>
#include <Servo.h>

Servo myservo;
int pos = 0;

int knob_pos_1 = D5;
int knob_pos_2 = D6;
int knob_pos_3 = D7;
int knob_pos_4 = D8;

int Timer_Value = 0;

// Use pin 2 as wake up pin
const int wakeUpPin = 6;

void wakeUp()
{
  // Just a handler for the pin interrupt.
}


void setup()
{
  Serial.begin(115200);
  // Allow wake up pin to trigger interrupt on low.
  myservo.attach(D4);

  Serial.println("90");
  myservo.write(90);
  delay(1000);

  pinMode(knob_pos_1, INPUT_PULLUP);
  pinMode(knob_pos_2, INPUT_PULLUP);
  pinMode(knob_pos_3, INPUT_PULLUP);
  pinMode(knob_pos_4, INPUT_PULLUP);

  WiFi.mode(WIFI_OFF);
  WiFi.forceSleepBegin();

}

void loop()
{


  Timer_Value = Read_Knob_Status();

  Serial.print("Timer_Value - "); Serial.println(Timer_Value);

  if (Timer_Value == 0) // 0min (Just to test if the servo works well)
  {
    myservo.write(138);              // turn the switch ON
    delay(500);
    myservo.write(90);
    delay(500);

    delay(2000);


    myservo.write(11);              // turn the switch OFF
    delay(500);
    myservo.write(90);
    delay(500);

  }


  if (Timer_Value == 1) // 1min
  {
    myservo.write(138);              // turn the switch ON
    delay(500);
    myservo.write(90);
    delay(500);

    delay(60000);

    myservo.write(11);              // turn the switch OFF
    delay(500);
    myservo.write(90);
    delay(500);

  }

  if (Timer_Value == 2) // 2min
  {
    myservo.write(138);              // turn the switch ON
    delay(500);
    myservo.write(90);

    for (int i = 0; i < 2; i++)
      delay(60000);

    myservo.write(11);              // turn the switch OFF
    delay(500);
    myservo.write(90);

  }

  if (Timer_Value == 3) // 3min
  {
    myservo.write(138);              // turn the switch ON
    delay(500);
    myservo.write(90);
    delay(500);
    Serial.println("Servo ON");

    for (int i = 0; i < 3; i++)
      delay(60000);

    myservo.write(11);              // turn the switch OFF
    delay(500);
    myservo.write(90);
    delay(500);
    Serial.println("Servo OFF");

  }

  if (Timer_Value == 4) // 4min
  {
    myservo.write(138);              // turn the switch ON
    delay(500);
    myservo.write(90);
    delay(500);

    for (int i = 0; i < 4; i++)
      delay(60000);

    myservo.write(11);              // turn the switch OFF
    delay(500);
    myservo.write(90);
    delay(500);
  }

a
}

int Read_Knob_Status()
{
  if (digitalRead(knob_pos_1) == LOW)
  {
    Serial.println("1 min Timer");
    return 1;

  }
  if (digitalRead(knob_pos_2) == LOW && digitalRead(knob_pos_3) == HIGH )
  {
    Serial.println("2 min Timer");
    return 2; 
  }
  if (digitalRead(knob_pos_2) == LOW && digitalRead(knob_pos_3) == LOW )
  {
    Serial.println("3 min Timer");
    return 3;
  }
  if (digitalRead(knob_pos_4) == LOW)
  {
    Serial.println("4 min Timer");
    return 4;
  }
  if (digitalRead(knob_pos_1) == HIGH && digitalRead(knob_pos_2) == HIGH && digitalRead(knob_pos_3) == HIGH && digitalRead(knob_pos_4) == HIGH )
  {
    Serial.println("No Timer");
    return 0;
  }



}
