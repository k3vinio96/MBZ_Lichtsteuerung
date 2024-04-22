#include <Arduino.h>

// put function declarations here:
void toggle_output(int);
int sec = 1000;
int act_millis;
int last_millis_1 = 0;
int last_millis_2 = 0;
int last_millis_4 = 0;

void setup()
{
  // put your setup code here, to run once:

  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(16, OUTPUT); // D0
  pinMode(5, OUTPUT);  // D1
  pinMode(4, OUTPUT);  // D2
  pinMode(0, OUTPUT);  // D3

  digitalWrite(16, HIGH);  
  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
  
  // put your main code here, to run repeatedly:
  act_millis = millis();

  if (act_millis - last_millis_1 > sec)
  {
    toggle_output(5);
    last_millis_1 = act_millis;
  }
  if (act_millis - last_millis_2 > sec*2)
  {
    toggle_output(4);
    last_millis_2 = act_millis;
  }
  if (act_millis - last_millis_4 > sec*4)
  {
    toggle_output(0);
    last_millis_4 = act_millis;
  }
}

// put function definitions here:
void toggle_output(int pin)
{
  if (digitalRead(pin) == HIGH)
    digitalWrite(pin, LOW);
  else
    digitalWrite(pin, HIGH);
}
