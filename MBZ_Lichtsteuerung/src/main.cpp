#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Adafruit_MCP23X17.h>

#include "html/indexPage.h"

// put function declarations here:
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

int Relay_2 = 5; // D1
int Relay_3 = 4; // D2

Adafruit_MCP23X17 mcp;

const char *ssid = "MBZ_Licht";
const char *password = "LangenLicht";

// port setzen
ESP8266WebServer server(80);
IPAddress local_IP(192, 168, 4, 1);

void setup()
{
  // put your setup code here, to run once:

  // Pin Modes definieren
  pinMode(SCL, OUTPUT);
  pinMode(SDA, OUTPUT);

  // Port Expander initialiseren
  if (mcp.begin_I2C())
  {
    //alle 16 IO's als OUTPUT setzen
    for (int i = 0; i < 16; i++)
    {
      mcp.pinMode(i, OUTPUT);
    }
  }

  // AccessPoint initialisieren
  StartAccessPoint(ssid, password);
  ServerHandler();
  server.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
  server.handleClient();
}

// put function definitions here:
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
  mcp.digitalWrite(0, !mcp.digitalRead(0));
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay2()
{
  mcp.digitalWrite(1, !mcp.digitalRead(1));
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay3()
{
  mcp.digitalWrite(2, !mcp.digitalRead(2));
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay4()
{
  mcp.digitalWrite(3, !mcp.digitalRead(3));
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay5()
{
  mcp.digitalWrite(4, !mcp.digitalRead(4));
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay6()
{
  mcp.digitalWrite(5, !mcp.digitalRead(5));
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay7()
{
  mcp.digitalWrite(6, !mcp.digitalRead(6));
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay8()
{
  mcp.digitalWrite(7, !mcp.digitalRead(7));
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}