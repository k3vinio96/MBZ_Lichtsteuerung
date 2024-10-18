#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Adafruit_MCP23X17.h>

#include "html/indexPage.h"

// put function declarations here:
void StartAccessPoint(const char *, const char *);
void ServerHandler();
void handleRoot();
void handleRelay(int RelayNo);

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
  pinMode(LED_BUILTIN, OUTPUT);

  // Port Expander initialiseren
  if (mcp.begin_I2C())
  {
    // alle 16 IO's als OUTPUT setzen
    for (int i = 0; i < 16; i++)
    {
      mcp.pinMode(i, OUTPUT);
    }
  }

  // AccessPoint initialisieren
  StartAccessPoint(ssid, password);
  ServerHandler();
  server.begin();

  digitalWrite(LED_BUILTIN, HIGH);
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
  server.on("/Relay1", HTTP_POST, handleRelay(0));
  server.on("/Relay2", HTTP_POST, handleRelay(1));
  server.on("/Relay3", HTTP_POST, handleRelay(2));
  server.on("/Relay4", HTTP_POST, handleRelay(3));
  server.on("/Relay5", HTTP_POST, handleRelay(4));
  server.on("/Relay6", HTTP_POST, handleRelay(5));
  server.on("/Relay7", HTTP_POST, handleRelay(6));
  server.on("/Relay8", HTTP_POST, handleRelay(7));
  server.on("/Relay9", HTTP_POST, handleRelay(8));
  server.on("/Relay10", HTTP_POST, handleRelay(9));
  server.on("/Relay11", HTTP_POST, handleRelay(10));
  server.on("/Relay12", HTTP_POST, handleRelay(11));
  server.on("/Relay13", HTTP_POST, handleRelay(12));
  server.on("/Relay14", HTTP_POST, handleRelay(13));
  server.on("/Relay15", HTTP_POST, handleRelay(14));
  server.on("/Relay16", HTTP_POST, handleRelay(15));
}

void handleRoot()
{
  Serial.println("GET /");
  server.send(200, "text/html", indexPage);
}

void handleRelay(int RelayNo)
{
  mcp.digitalWrite(RelayNo, !mcp.digitalRead(RelayNo));
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleRelay1()
{
  mcp.digitalWrite(0, !mcp.digitalRead(0));
  // Relay1_state = !relay1_State;
  server.sendHeader("Location", "/"); // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                   // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}