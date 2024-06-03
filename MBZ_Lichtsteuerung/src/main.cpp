#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "html/indexPage.h"

// put function declarations here:
void toggle_output(int);
void StartAccessPoint(const char *, const char *);
void ServerHandler();
void handleRoot();
void handleRelay1();
void handleRelay2();
void handleRelay3();
void handleRelay4();
void handleRelay5();
void handleRelay6();
void handleRelay7();
void handleRelay8();

int sec = 1000;
int act_millis;
int last_millis_1 = 0;
int last_millis_2 = 0;
int last_millis_4 = 0;

int Relay_1 = 16; //D0
int Relay_2 = 5;  //D1
int Relay_3 = 4;  //D2
int Relay_4 = 0;  //D3
int Relay_5 = 2;  //D4
int Relay_6 = 14; //D5
int Relay_7 = 12; //D6
int Relay_8 = 13; //D7

const char *ssid = "MBZ_Licht";
const char *password = "LangenLicht";

// port setzen
ESP8266WebServer server(80);
IPAddress local_IP(192, 168, 4, 1);

void setup()
{
  // put your setup code here, to run once:

  pinMode(Relay_1, OUTPUT);
  pinMode(Relay_2, OUTPUT); 
  pinMode(Relay_3, OUTPUT); 
  pinMode(Relay_4, OUTPUT);  
  pinMode(Relay_5, OUTPUT); 
  pinMode(Relay_6, OUTPUT); 
  pinMode(Relay_7, OUTPUT); 
  pinMode(Relay_8, OUTPUT);

  StartAccessPoint(ssid, password);
  ServerHandler();
  server.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
  act_millis = millis();

  server.handleClient();
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

  server.on("/Relay1", HTTP_POST, handleRelay1);
  server.on("/Relay2", HTTP_POST, handleRelay2);
  server.on("/Relay3", HTTP_POST, handleRelay3);
  server.on("/Relay4", HTTP_POST, handleRelay4);
  server.on("/Relay5", HTTP_POST, handleRelay5);
  server.on("/Relay6", HTTP_POST, handleRelay6);
  server.on("/Relay7", HTTP_POST, handleRelay7);
  server.on("/Relay8", HTTP_POST, handleRelay8);
}

void handleRoot()
{
  Serial.println("GET /");
  server.send(200, "text/html", indexPage);
}

void handleRelay1()
{
  digitalWrite(Relay_1, !digitalRead(Relay_1)); 
  server.sendHeader("Location", "/");   // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                     // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay2()
{
  digitalWrite(Relay_2, !digitalRead(Relay_2)); 
  server.sendHeader("Location", "/");   // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                     // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay3()
{
  digitalWrite(Relay_3, !digitalRead(Relay_3)); 
  server.sendHeader("Location", "/");   // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                     // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay4()
{
  digitalWrite(Relay_4, !digitalRead(Relay_4)); 
  server.sendHeader("Location", "/");   // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                     // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay5()
{
  digitalWrite(Relay_5, !digitalRead(Relay_5)); 
  server.sendHeader("Location", "/");   // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                     // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay6()
{
  digitalWrite(Relay_6, !digitalRead(Relay_6)); 
  server.sendHeader("Location", "/");   // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                     // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay7()
{
  digitalWrite(Relay_7, !digitalRead(Relay_7)); 
  server.sendHeader("Location", "/");   // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                     // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay8()
{
  digitalWrite(Relay_8, !digitalRead(Relay_8)); 
  server.sendHeader("Location", "/");   // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                     // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}