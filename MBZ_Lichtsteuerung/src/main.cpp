#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "html/indexPage.h"

// put function declarations here:
void toggle_output(int);
void StartAccessPoint(const char *, const char *);
void ServerHandler();
void handleRoot();
void handleLED();

int sec = 1000;
int act_millis;
int last_millis_1 = 0;
int last_millis_2 = 0;
int last_millis_4 = 0;

const char *ssid = "MBZ_Licht";
const char *password = "LangenLicht";

// port setzen
ESP8266WebServer server(80);
IPAddress local_IP(192, 168, 4, 1);

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

  StartAccessPoint(ssid, password);
  ServerHandler();
  server.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
  act_millis = millis();

  server.handleClient();


  if (act_millis - last_millis_1 > sec)
  {
    toggle_output(5);
    last_millis_1 = act_millis;
  }
  if (act_millis - last_millis_2 > sec * 2)
  {
    toggle_output(4);
    last_millis_2 = act_millis;
  }
  if (act_millis - last_millis_4 > sec * 4)
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

void StartAccessPoint(const char *ssid, const char *password)
{
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
}

void ServerHandler()
{
  server.on("/", HTTP_GET, handleRoot);
  server.on("/LED", HTTP_POST, handleLED);
}

void handleRoot()
{
  Serial.println("GET /");
  server.send(200, "text/html", indexPage);
}

void handleLED()
{
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); 
  server.sendHeader("Location", "/");   // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                     // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}